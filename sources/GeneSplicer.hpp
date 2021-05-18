#pragma once
#include "Player.hpp"

namespace pandemic {
class GeneSplicer : public Player {
public:
    GeneSplicer(Board &board, City city);
    Player &discover_cure(Color disease_color);
    std::string role();
};
} // namespace pandemic