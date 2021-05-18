#include "Board.hpp"

namespace pandemic {
int &Board::operator[](City city) {
    return spread[city];
}

bool Board::is_clean() {
    for (auto [city, v] : spread) {
        if (v > 0) {
            return false;
        }
    }
    return true;
}

Color Board::getCityColor(City city) {
    return colors[city];
}

void Board::remove_cures() {
    cures.clear();
}

void Board::remove_stations() {
    stations.clear();
}

std::ostream &operator<<(std::ostream &os, const Board &c) {
    return os;
}
} // namespace pandemic