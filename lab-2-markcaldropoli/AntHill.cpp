#include "AntHill.h"
#include <iostream>
#include <cstdlib>

#define BUFFER_MAX 100

using namespace std;

/* Ant */

Ant::Ant(int id) {
	this->id = id;
	this->x = this->y = 0;
}

int Ant::getID() {
	return this->id;
}

void Ant::move() {
	int r = rand() % 4;
	if(r == 0) this->x++;
	else if(r == 1) this->x--;
	else if(r == 2) this->y++;
	else this->y--;
}

int Ant::getX() {
	return this->x;
}

int Ant::getY() {
	return this->y;
}

/* AntHill */

AntHill::AntHill(int max_ants) {
	this->max_ants = max_ants;
	this->current_ants = 0;
	this->next_id = 0;
}

bool AntHill::addAnt() {
	if(this->current_ants < this->max_ants) {
		this->ants[this->current_ants] = Ant(this->next_id);
		this->current_ants++;
		this->next_id++;
		return true;
	}
	return false;
}

Ant AntHill::getAnt(int id) {
	for(int i = 0; i < this->current_ants; i++) {
		if(this->ants[i].getID() == id) return this->ants[i];
	}
	return Ant(id);
}

void AntHill::move() {
	for(int i = 0; i < this->current_ants; i++) {
		this->ants[i].move();
	}
}

bool AntHill::changeMax(int max_ants) {
	if(max_ants >= 0 && max_ants <= 100) {
		this->max_ants = max_ants;
		return true;
	}
	return false;
}

void AntHill::printHillInfo() {
	for(int i = 0; i < this->current_ants; i++) {
		cout << "\tAnt #" << i << " [" << this->ants[i].getX() << "," << this->ants[i].getY() << "]" << endl;
	}
}

int AntHill::getCurrentNumAnts() {
	return this->current_ants;
}

int AntHill::getMaxAnts() {
	return this->max_ants;
}
