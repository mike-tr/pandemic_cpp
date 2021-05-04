#include "Virologist.hpp"

namespace pandemic {
Virologist::Virologist(Board board, City city) : Player(board, city) {
}
Player &Virologist::treat(City city) {
    return *this;
}
} // namespace pandemic