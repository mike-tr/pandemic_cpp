#include "Scientist.hpp"

namespace pandemic {
Scientist::Scientist(Board board, City city, int n) : Player(board, city) {
}
Player &Scientist::discover_cure(Color disease_color) {
    return *this;
}
} // namespace pandemic