#include "Researcher.hpp"

namespace pandemic {
Researcher ::Researcher(Board board, City city) : Player(board, city) {
}
Player &Researcher::discover_cure(Color disease_color) {
    return *this;
}
} // namespace pandemic