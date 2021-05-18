#include "Player.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

namespace pandemic {

Player::Player(Board &board, City city) : board(board) {
    current = city;
}

void Player::on_arrival() {
    // do nothing;
}

bool Player::removeCard(City city) {
    auto color = board.getCityColor(city);
    auto position = std::find(cards[color].begin(), cards[color].end(), city);
    if (position != cards[color].end()) {
        cards[color].erase(position);
    } else {
        return false;
    }
    return true;
}

bool Player::removeKCards(Color color, int k) {
    if (cards[color].size() >= k) {
        cards[color].erase(cards[color].begin(), cards[color].begin() + k);
    } else {
        return false;
    }
    return true;
}

Player &Player::drive(City city) {
    if (city == current) {
        throw invalid_argument{"Cannot move to the city we are currently in."};
    }

    if (board.IsAdjecent(current, city)) {
        current = city;
        on_arrival();
    } else {
        throw invalid_argument{"Cannot drive to a city that is not adjecent."};
    }
    return *this;
}

Player &Player::fly_direct(City city) {
    if (city == current) {
        throw invalid_argument{"Cannot move to the city we are currently in."};
    }

    if (removeCard(city)) {
        current = city;
        on_arrival();
    } else {
        throw invalid_argument{"Cannot direct fly to city without that city card."};
    }
    return *this;
}

Player &Player::fly_charter(City city) {
    if (city == current) {
        throw invalid_argument{"Cannot move to the city we are currently in."};
    }

    if (removeCard(current)) {
        current = city;
        on_arrival();
    } else {
        throw invalid_argument{"Cannot charter fly to city without current city card."};
    }
    return *this;
}

Player &Player::fly_shuttle(City city) {
    if (city == current) {
        throw invalid_argument{"Cannot move to the city we are currently in."};
    }

    if (board.stations[city] && board.stations[current]) {
        current = city;
        on_arrival();
    } else {
        throw invalid_argument{"Cannot shuttle fly both cities must have a science station."};
    }
    return *this;
}

Player &Player::build() {
    if (board.stations[current]) {
        return *this;
    }
    if (removeCard(current)) {
        board.stations[current] = true;
    } else {
        throw invalid_argument{"Cannot build a science station without a card."};
    }
    return *this;
}

Player &Player::discover_cure(Color disease_color) {
    if (board.cures[disease_color]) {
        return *this;
    }

    if (board.stations[current]) {
        if (removeKCards(disease_color, CARDS_FOR_CURE)) {
            board.cures[disease_color] = true;
        } else {
            throw invalid_argument{"needs 5 cards in ourder to discorver a cure."};
        }
    } else {
        throw invalid_argument{"Cannot discover cure without a science station."};
    }
    return *this;
}

Player &Player::treat(City city) {
    if (city != current) {
        throw invalid_argument{"cannot threat city other then the current one."};
    }

    if (board[city] == 0) {
        throw invalid_argument{"disease level is already 0."};
    }

    auto color = board.getCityColor(city);
    if (board.cures[color]) {
        board[city] = 0;
    } else {
        board[city]--;
    }
    return *this;
}

string Player::role() {
    return "none";
}

Player &Player::take_card(City city) {
    auto color = board.getCityColor(city);
    auto position = std::find(cards[color].begin(), cards[color].end(), city);
    if (position == cards[color].end()) {
        cards[color].push_back(city);
    }
    return *this;
}

void Player::remove_cards() {
    cards.clear();
}

} // namespace pandemic