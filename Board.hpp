#ifndef BOARD_HPP
#define BOARD_HPP

#include "City.hpp"
#include <iostream>
#include <map>
namespace pandemic {
class Board {
private:
    std::map<City, int> spread;

public:
    int &operator[](City city);
    bool is_clean();
    void remove_cures();
    friend std::ostream &operator<<(std::ostream &os, const Board &c);
};
}; // namespace pandemic

#endif