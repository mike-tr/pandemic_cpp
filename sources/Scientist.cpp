#include "Scientist.hpp"

#include <string>

using namespace std;

namespace pandemic {
Scientist::Scientist(Board &board, City city, int n) : Player(board, city) {
    cards_needed = n;
    if (cards_needed > CARDS_FOR_CURE) {
        cards_needed = CARDS_FOR_CURE;
    }
}
Player &Scientist::discover_cure(Color disease_color) {
    if (board.cures[disease_color]) {
        return *this;
    }

    if (board.stations[current]) {
        if (removeKCards(disease_color, cards_needed)) {
            board.cures[disease_color] = true;
        } else {
            throw invalid_argument{"needs " + to_string(cards_needed) + "cards in ourder to discorver a cure."};
        }
    } else {
        throw invalid_argument{"Cannot discover cure without a science station."};
    }
    return *this;
}

string Scientist::role() {
    return "Scientist";
}
} // namespace pandemic