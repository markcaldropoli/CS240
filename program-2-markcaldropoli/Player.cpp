#include "Player.h"

using namespace std;

Player::Player() {}

Player::Player(string name, int budget) {
    this->name = name;
    this->budget = budget;
}

bool Player::bet(int amount) {
    if(this->budget > amount) {
        this->budget -= amount;
        return true;
    }
    return false;
}

void Player::collectWinnings(int amount) {
    this->budget += amount;
}
