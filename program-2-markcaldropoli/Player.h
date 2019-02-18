#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>

class Player {
    private:
        std::string name;
        int budget;
    public:
        Card hand;
        Player();
        Player(std::string name, int budget);
        std::string getName() { return this->name; }
        int getBudget() { return this->budget; }
        bool bet(int amount);
        void collectWinnings(int amount);
};

#endif
