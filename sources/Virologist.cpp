#include "Virologist.hpp"

using namespace std;

namespace pandemic {
Virologist::Virologist(Board &board, City city) : Player(board, city) {
}
Player &Virologist::treat(City city) {
    if (city != current) {
        if (!removeCard(city)) {
            throw invalid_argument{"cannot threat other city if no cards of that city."};
        }
    }

    if (board[city] == 0) {
        throw invalid_argument{"disease level is already 0."};
    }

    auto color = board.getCityColor(city);
    if (board.cures[color]) {
        board[city] = 0;
    } else {
        board[city]--;
    }
    return *this;
}

string Virologist::role() {
    return "Virologist";
}
} // namespace pandemic