#include "Researcher.hpp"

using namespace std;

namespace pandemic {
Researcher ::Researcher(Board &board, City city) : Player(board, city) {
}
Player &Researcher::discover_cure(Color disease_color) {
    if (board.cures[disease_color]) {
        return *this;
    }

    if (removeKCards(disease_color, CARDS_FOR_CURE)) {
        board.cures[disease_color] = true;
    } else {
        throw invalid_argument{"needs 5 cards in ourder to discorver a cure."};
    }
    return *this;
}

string Researcher::role() {
    return "Researcher";
}
} // namespace pandemic