#ifndef CARD_H
#define CARD_H

class Card {
    private:
        int suit;
        int value;
    public:
        Card(int suit, int value);
        int getSuit() { return suit; }
        int getValue() { return value; }
        bool operator==(const Card &other);
};

#endif
