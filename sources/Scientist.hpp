#pragma once
#include "Player.hpp"

namespace pandemic {
class Scientist : public Player {
private:
    int cards_needed;

public:
    Scientist(Board &board, City city, int n);
    Player &discover_cure(Color disease_color);
    std::string role();
};
} // namespace pandemic