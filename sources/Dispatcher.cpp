
#include "Dispatcher.hpp"

using namespace std;

namespace pandemic {

Dispatcher::Dispatcher(Board &board, City city) : Player(board, city) {
}
Player &Dispatcher::fly_direct(City city) {
    if (city == current) {
        throw invalid_argument{"Cannot move to the city we are currently in."};
    }

    if (board.stations[current]) {
        current = city;
        on_arrival();
    } else {
        Player::fly_direct(city);
    }
    return *this;
}

string Dispatcher::role() {
    return "Dispatcher";
}
} // namespace pandemic