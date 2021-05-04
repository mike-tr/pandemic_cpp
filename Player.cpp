#include "Player.hpp"
#include <iostream>

using namespace std;

namespace pandemic {

Player::Player(Board board, City city) {
}

void Player::on_arrival() {
}

Player &Player::drive(City city) {
    on_arrival();
    return *this;
}
Player &Player::fly_direct(City city) {
    on_arrival();
    return *this;
}
Player &Player::fly_charter(City city) {
    on_arrival();
    return *this;
}
Player &Player::fly_shuttle(City city) {
    on_arrival();
    return *this;
}
Player &Player::build() {
    return *this;
}
Player &Player::discover_cure(Color disease_color) {
    return *this;
}
Player &Player::treat(City city) {
    return *this;
}

string Player::role() {
    return "none";
}
Player &Player::take_card(City city) {
    return *this;
}
} // namespace pandemic