#pragma once
#include "Player.hpp"

namespace pandemic {
class Virologist : public Player {
public:
    Virologist(Board &board, City city);
    Player &treat(City city);
    std::string role();
};
} // namespace pandemic