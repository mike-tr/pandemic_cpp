#include "GeneSplicer.hpp"

namespace pandemic {

GeneSplicer::GeneSplicer(Board board, City city) : Player(board, city) {
}
Player &GeneSplicer::discover_cure(Color disease_color) {
    return *this;
}

} // namespace pandemic