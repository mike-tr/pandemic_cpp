#pragma once
#include "Player.hpp"

namespace pandemic {
class Researcher : public Player {
public:
    Researcher(Board &board, City city);
    Player &discover_cure(Color disease_color);
    std::string role();
};
} // namespace pandemic