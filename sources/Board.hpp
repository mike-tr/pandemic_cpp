#ifndef BOARD_HPP
#define BOARD_HPP

#include "City.hpp"
#include "Color.hpp"
#include <iostream>
#include <map>
namespace pandemic {
class Board {
private:
    std::map<City, int> spread;
    std::map<City, Color> colors;
    std::map<std::pair<City, City>, bool> adjecencyMap;
    void loadAdjecencyMap();

public:
    int id = 0;
    std::map<City, bool> stations;
    std::map<Color, bool> cures;

    Color getCityColor(City city);

    Board();
    int &operator[](City city);
    bool is_clean();
    void remove_cures();
    void remove_stations();
    bool IsAdjecent(City cityA, City cityB);
    friend std::ostream &operator<<(std::ostream &os, const Board &c);
};
}; // namespace pandemic

#endif