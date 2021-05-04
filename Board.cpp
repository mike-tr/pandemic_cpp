#include "Board.hpp"

namespace pandemic {
int &Board::operator[](City city) {
    return spread[city];
}

bool Board::is_clean() {
    return true;
}

void Board::remove_cures() {
}

std::ostream &operator<<(std::ostream &os, const Board &c) {
    return os;
}
} // namespace pandemic