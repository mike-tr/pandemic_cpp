#include "GeneSplicer.hpp"

using namespace std;
namespace pandemic {

GeneSplicer::GeneSplicer(Board &board, City city) : Player(board, city) {
}
Player &GeneSplicer::discover_cure(Color disease_color) {
    if (board.cures[disease_color]) {
        return *this;
    }

    if (board.stations[current]) {
        int needed = CARDS_FOR_CURE;
        int count = 0;
        for (auto [color, list] : cards) {
            count += list.size();
        }

        if (count >= needed) {
            for (auto [color, list] : cards) {
                if (list.size() >= needed) {
                    removeKCards(color, needed);
                    break;
                }
                needed -= list.size();
                cards[color].clear();
            }
            board.cures[disease_color] = true;
        } else {
            throw invalid_argument{"needs 5 cards in ourder to discorver a cure."};
        }

    } else {
        throw invalid_argument{"Cannot discover cure without a science station."};
    }
    return *this;
}

string GeneSplicer::role() {
    return "GeneSplicer";
}

} // namespace pandemic