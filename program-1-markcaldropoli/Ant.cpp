#include "Ant.h"
#include <cstdlib>

//Constructor
Ant::Ant(int id) {
	this->id = id;
	this->x = this->y = 0;
	this->xp = 10;
}

//Copy Constructor
Ant::Ant(const Ant &copy) {
	this->id = copy.id;
	this->x = copy.x;
	this->y = copy.y;
	this->xp = copy.xp;
}

//Randomly moves the ant
void Ant::move() {
	int r = rand() % 4;
	if(r == 0) this->x++;
	else if(r == 1) this->x--;
	else if(r == 2) this->y++;
	else this->y--;
}

//Returns either true or false based on random number
bool Ant::fight() {
	int strone = this->xp;
	int strtwo = 10;
	int r = rand() % (strone+strtwo);

	if(r <= strone-1) {
		this->xp += strtwo;
		return false;
	}
	this->xp = 5;
	return true;
}

//Moves the ant back onto the grid
void Ant::moveInGrid(int size) {
	if(this->x > size/2) this->x--;
	else if(this->x < -size/2) this->x++;
	else if(this->y > size/2) this->y--;
	else if(this->y < -size/2) this->y++;
}
