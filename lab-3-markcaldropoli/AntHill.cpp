#include "AntHill.h"
//#include "Ant.h"
#include <iostream>
#include <cstdlib>

#define BUFFER_MAX 100

using namespace std;

AntHill::AntHill() {
	this->current_ants = 0;
	this->ants = NULL;
	this->next_id = 0;
}

AntHill::~AntHill() {
	for(int i = 0; i < this->current_ants; i++) {
		delete this->ants[i];
	}
	delete[] this->ants;
}

int AntHill::addAnt() {
	Ant ** antlist = new Ant*[this->current_ants+1];

	if(this->ants != NULL) {
		for(int i = 0; i < this->current_ants; i++) {
			antlist[i] = this->ants[i];
		}
	}

	antlist[this->current_ants] = new Ant(this->next_id);

	this->next_id++;
	this->current_ants++;
	delete[] this->ants;
	this->ants = antlist;
	return this->next_id-1;
}

bool AntHill::removeAnt(int antid) {
	if(antid < 0) return false;

	Ant ** antlist = new Ant*[this->current_ants - 1];
	bool end = false;

	for(int i = 0; i < this->current_ants; i++) {
		if(this->ants[i]->getID() == antid) {
			delete ants[i];
			end = true;
		} else {
			if(end) antlist[i-1] = this->ants[i];
			else antlist[i] = this->ants[i];
		}
	}

	this->current_ants--;
	delete[] this->ants;
	this->ants = antlist;
	return true;
}

Ant * AntHill::getAnt(int id) {
	Ant * temp;
	for(int i = 0; i < this->current_ants; i++) {
		if(this->ants[i]->getID() == id) {
			temp = this->ants[i];
			return temp;
		}
	}
	return NULL;
}

void AntHill::move() {
	for(int i = 0; i < this->current_ants; i++) {
		this->ants[i]->move();
	}
}

void AntHill::printHillInfo() {
	for(int i = 0; i < this->current_ants; i++) {
		cout << "\tAnt #" << this->ants[i]->getID() << " [" << this->ants[i]->getX() << "," << this->ants[i]->getY() << "]" << endl;
	}
}
