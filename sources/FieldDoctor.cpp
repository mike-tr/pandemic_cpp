#include "FieldDoctor.hpp"

using namespace std;

namespace pandemic {

FieldDoctor::FieldDoctor(Board &board, City city) : Player(board, city) {
}
Player &FieldDoctor::treat(City city) {
    if (city != current && !board.IsAdjecent(current, city)) {
        throw invalid_argument{"cannot threat city other then the current one or the neighbours."};
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

string FieldDoctor::role() {
    return "FieldDoctor";
}

} // namespace pandemic