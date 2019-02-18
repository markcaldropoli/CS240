#include "Card.h"

using namespace std;

Card::Card(int suit, int value) {
    //default value
    this->suit = 1;
    this->value = 2;

    //suit must be between 1-4, value must be between 2-14
    if((suit > 0 && suit < 5) && (value > 1 && value < 15)) {
        this->suit = suit;
        this->value = value;
    }
}

bool Card::operator==(const Card &other) {
    //compare the values of the cards
    return (this->value == other.value);
}
