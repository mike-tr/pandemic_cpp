#include "FieldDoctor.hpp"

namespace pandemic {

FieldDoctor::FieldDoctor(Board board, City city) : Player(board, city) {
}
Player &FieldDoctor::treat(City city) {
    return *this;
}

} // namespace pandemic