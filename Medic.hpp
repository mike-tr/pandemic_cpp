#pragma once
#include "Player.hpp"

namespace pandemic {
class Medic : public Player {
protected:
    virtual void on_arrival();

public:
    Medic(Board board, City city);
    Player &treat(City city);
};
} // namespace pandemic