
#include "Dispatcher.hpp"

namespace pandemic {

Dispatcher::Dispatcher(Board board, City city) : Player(board, city) {
}
Player &Dispatcher::fly_direct(City city) {
    return *this;
}
} // namespace pandemic