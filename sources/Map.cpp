#include "Board.hpp"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>

using namespace std;

namespace pandemic {

static int nextID = 0;
const map<string, City> stringToCity{
    {"Algiers", City::Algiers},
    {"Atlanta", City::Atlanta},
    {"Baghdad", City::Baghdad},
    {"Bangkok", City::Bangkok},
    {"Beijing", City::Beijing},
    {"Bogota", City::Bogota},
    {"BuenosAires", City::BuenosAires},
    {"Cairo", City::Cairo},
    {"Chennai", City::Chennai},
    {"Chicago", City::Chicago},
    {"Delhi", City::Delhi},
    {"Essen", City::Essen},
    {"HoChiMinhCity", City::HoChiMinhCity},
    {"HongKong", City::HongKong},
    {"Istanbul", City::Istanbul},
    {"Jakarta", City::Jakarta},
    {"Johannesburg", City::Johannesburg},
    {"Karachi", City::Karachi},
    {"Khartoum", City::Khartoum},
    {"Kinshasa", City::Kinshasa},
    {"Kolkata", City::Kolkata},
    {"Lagos", City::Lagos},
    {"Lima", City::Lima},
    {"London", City::London},
    {"LosAngeles", City::LosAngeles},
    {"Madrid", City::Madrid},
    {"Manila", City::Manila},
    {"MexicoCity", City::MexicoCity},
    {"Miami", City::Miami},
    {"Milan", City::Milan},
    {"Montreal", City::Montreal},
    {"Moscow", City::Moscow},
    {"Mumbai", City::Mumbai},
    {"NewYork", City::NewYork},
    {"Osaka", City::Osaka},
    {"Paris", City::Paris},
    {"Riyadh", City::Riyadh},
    {"SanFrancisco", City::SanFrancisco},
    {"Santiago", City::Santiago},
    {"SaoPaulo", City::SaoPaulo},
    {"Seoul", City::Seoul},
    {"Shanghai", City::Shanghai},
    {"StPetersburg", City::StPetersburg},
    {"Sydney", City::Sydney},
    {"Taipei", City::Taipei},
    {"Tehran", City::Tehran},
    {"Tokyo", City::Tokyo},
    {"Washington", City::Washington},
};

const map<string, Color> stringToColor{
    {"Black", Color::Black},
    {"Blue", Color::Blue},
    {"Red", Color::Red},
    {"Yellow", Color::Yellow},
};

Board::Board() {
    loadAdjecencyMap();
    this->id = nextID;
    nextID++;
}

bool Board::IsAdjecent(City cityA, City cityB) {
    return adjecencyMap[{cityA, cityB}];
}

void Board::loadAdjecencyMap() {
    // read the cities file put colors and neighbours for all cities on board.
    ifstream pmap{"cities_map.txt"};
    if (pmap.is_open()) {
        std::string linestring;
        while (getline(pmap, linestring)) {
            istringstream line(linestring);

            string current;
            string scolor;
            line >> current;
            line >> scolor;

            auto ca = stringToCity.at(current);
            auto color = stringToColor.at(scolor);

            colors[ca] = color;

            while (!line.eof()) {
                string n;
                line >> n;

                auto cb = stringToCity.at(n);

                adjecencyMap[{ca, cb}] = true;
                adjecencyMap[{cb, ca}] = true;
            }
        }
        pmap.close();
    }
}
} // namespace pandemic