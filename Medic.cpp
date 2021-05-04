#include "Medic.hpp"

namespace pandemic {
Medic::Medic(Board board, City city) : Player(board, city) {
}
void Medic::on_arrival() {
}
Player &Medic::treat(City city) {
    return *this;
}

} // namespace pandemic