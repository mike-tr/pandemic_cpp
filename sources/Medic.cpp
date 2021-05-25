#include "Medic.hpp"

using namespace std;

namespace pandemic {
Medic::Medic(Board &board, City city) : Player(board, city) {
}
void Medic::on_arrival() {
    auto color = board.getCityColor(current);
    if (board.cures[color]) {
        board[current] = 0;
    }
}

Player &Medic::treat(City city) {
    if (city != current) {
        throw invalid_argument{"cannot threat city other then the current one."};
    }

    if (board[city] == 0) {
        throw invalid_argument{"disease level is already 0."};
    }
    board[city] = 0;
    return *this;
}

string Medic::role() {
    return "Medic";
}

} // namespace pandemic