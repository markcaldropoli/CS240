#include "Ant.h"
#include <iostream>
#include <cstdlib>

using namespace std;

Ant::Ant(int id) {
	this->id = id;
	this->x = this->y = 0;
	this->xp = 10;
}

void Ant::move() {
	int r = rand() % 4;
	if(r == 0) this->x++;
	else if(r == 1) this->x--;
	else if(r == 2) this->y++;
	else this->y--;
}

Ant * Ant::fight(Ant * ant) {
	int strone = this->xp;
	int strtwo = ant->xp;

	int r = rand() % (strone+strtwo);

	if(r <= strone-1) {
		this->xp += ant->xp;
		ant->xp = 5;
		return ant;
	}
	ant->xp += this->xp;
	this->xp = 5;
	return this;
}
