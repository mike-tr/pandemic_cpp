#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"

namespace pandemic {
class Player {
protected:
    virtual void on_arrival();

public:
    Player(Board board, City city);

    /**
     * drive to adjacent city
     * */
    Player &drive(City city);

    /**
     * fly to any city.
     * cost : throw away the card of target city.
     * 
     * Dispatcher - cost is nothing if hes in a city with a science center.
     * */
    virtual Player &fly_direct(City city);

    /**
     * fly to any city.
     * cost : throw away the card of current city ( the one the player is in ).
     * 
     * */
    Player &fly_charter(City city);

    /**
     * direct flight to target city.
     * cost : nothing.
     * needs : science center on both sides.
     * */
    Player &fly_shuttle(City city);

    /**
     * if the city has science center do nothing.
     * 
     * otherwise - build a science center in the city we are in.
     * 
     * cost : throw away a card of that city.
     * 
     * 
     * OperationsExpert - cost is nothing. ( doesn't need a card )
     * */
    virtual Player &build();

    /**
     * discorver a cure for a disease of some color.
     * needs : science center.
     * cost : throw away 5 cards of that color.
     * 
     * Scientist - cost is n cards instead of 5.
     * GeneSplicer - can throw away 5 cards of any color ( instead of the disease color )
     * */
    virtual Player &discover_cure(Color disease_color);

    /**
     * remove the level of disease cubes in city by 1.
     * if disease cure is discovered set the level to 0.
     * cost : nothing.
     * 
     * [ Medic - set the disease level to 0 ]
     * [ Virologist - can threat a disease in any city 
     *   Cost - card of target city                    ]
     * [ FieldDoctor - can threat disease in adjacent cities too. ]
     * if disease level is 0, before the treat throw exception
     * */
    virtual Player &treat(City city);

    /**
     * return the role time of the player.
     * */
    virtual std::string role();

    /**
     * Take card of target city, there is exactly 1 card for each city.
     * */
    Player &take_card(City city);
};
} // namespace pandemic