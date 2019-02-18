#include "Deck.h"
#include "Table.h"
#include <iostream>

using namespace std;

Table::Table(int num_seats, int ante) {
    this->num_seats = num_seats;
    this->ante = ante;
    this->seats = 0;
    this->players = {};
    this->losers = {};
}

bool Table::emptySeat() {
    if(this->seats < this->num_seats) return true;
    return false;
}

vector<Player> Table::playRound() {
    this->losers.clear();
    if(this->players.size() == 0) return this->losers;

    Deck deck;
    deck.shuffle();

    for(int i = 0; i < this->seats; i++) {
        this->players[i].bet(this->ante);
        this->players[i].hand = deck.draw();
    }

    this->winner = this->players[0];

    for(int i = 1; i < this->seats; i++) {
        if(this->players[i].hand.getValue() > this->winner.hand.getValue()) {
            this->losers.push_back(this->winner);
            this->winner = this->players[i];
        } else if(this->players[i].hand.getValue() == this->winner.hand.getValue()) {
            if(this->winner.hand.getSuit() < this->players[i].hand.getSuit()) {
                this->losers.push_back(this->winner);
                this->winner = this->players[i];
            } else this->losers.push_back(this->players[i]);
        } else this->losers.push_back(this->players[i]);
    }

    this->winner.collectWinnings(this->ante * this->seats);
    this->players.clear();
    this->players.push_back(this->winner);
    this->seats = 1;
    return this->losers;
}

void Table::addPlayer(Player p) {
    this->seats++;
    this->players.push_back(p);
}

void Table::printWinner() {
    cout << "\n\tThe winner is " << winner.getName() << " with $" << winner.getBudget() << "!" << endl;
}
