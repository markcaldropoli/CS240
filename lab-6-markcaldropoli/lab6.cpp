#include "Deck.h"
#include "Card.h"
#include "Deck.h"
#include "Card.h"
#include <iostream>
#include <cassert>
#include <string>
#include <ctime>
#include <cstdlib>

#define EXTRA_CREDIT 1

using namespace std;


int main(){
	srand(time(NULL));
	cerr << "\n\tTEST #1: Card does not allow invalid values" << endl;

	Card c1(0, 0);
	assert(c1.getValue() == 2 && c1.getSuit() == 1);
	Card c2(5, 15);
	assert(c2.getValue() == 2 && c2.getSuit() == 1);
	Card c3(2, 14);
	assert(c3.getValue() == 14 && c3.getSuit() == 2);

	cerr << "\n\t========================PASS========================\n" << endl;
	cerr << "\n\tTEST #2: Overloaded equal operator" << endl;

	Card c5(2, 14);
	Card c6(1, 14);
	assert(c5 == c6);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #3: Uses STL deque" << endl;
	Deck deck;
	std::deque<Card *> & test = deck.getInternal();

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #4: Create Deck" << endl;
	int last_suit = -1, last_val = -1;
	int num_cards = 1;
	for(Card draw_card = deck.draw();!deck.empty(); draw_card = deck.draw()){
		assert(draw_card.getSuit() != last_suit || draw_card.getValue() != last_val);
		assert(draw_card.getSuit() > 0 && draw_card.getSuit() < 5);
		assert(draw_card.getValue() > 1 && draw_card.getValue() < 15);
		last_suit = draw_card.getSuit();
		last_val = draw_card.getValue();
		num_cards++;
	}
	assert(num_cards == 52);

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tTEST #5: Shuffle" << endl;
	Deck deck2, deck3, deck4;
	deck3.shuffle();
	deck4.shuffle();
	int unshuffled = 45;
	for(Card card2 = deck2.draw(), card3 = deck3.draw(), card4 = deck4.draw();
		!deck2.empty() && !deck3.empty() && !deck4.empty();
			card2 = deck2.draw(), card3 = deck3.draw(), card4 = deck4.draw()){
		if(card2 == card3 || card3 == card4 || card2 == card4){
			unshuffled--;
		}
		assert(unshuffled > 0);
	}

	cerr << "\n\t========================PASS========================\n" << endl;

	cerr << "\n\tAll Tests Passed.\nDon't forget to run with Valgrind and commit to Github!\n" << endl;
	return 0;
}
