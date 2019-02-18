#include "Deck.h"
#include <random>

using namespace std;

Deck::Deck() {
    //iterate through suits and values
    for(int i = 1; i < 5; i++) {
        for(int j = 2; j < 15; j++) {
            this->deck.push_front(new Card(i,j));
        }
    }
}

Deck::~Deck() {
    while(!this->deck.empty()) {
        Card * temp = this->deck.front();
        delete temp;
        this->deck.pop_front();
    }
}

Card Deck::draw() {
    Card * c = this->deck.front();
    Card temp = *c;
    this->deck.pop_front();
    delete c;
    return temp;
}

bool Deck::empty() {
    return this->deck.empty();
}

std::deque<Card *> & Deck::getInternal() {
    return this->deck;
}

void Deck::shuffle() {
    for(unsigned int i = 0; i < deck.size(); i++) {
        int random = rand() % 52;
        Card * card = deck[i];
        deck[i] = deck[random];
        deck[random] = card;
    }
}
