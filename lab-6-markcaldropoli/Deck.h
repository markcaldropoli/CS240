#ifndef DECK_H
#define DECK_H

#include "Card.h"
#include <deque>

class Deck {
    private:
        std::deque<Card *> deck;
    public:
        Deck();
        ~Deck();
        Card draw();
        bool empty();
        std::deque<Card *> & getInternal();
        void shuffle();
};

#endif
