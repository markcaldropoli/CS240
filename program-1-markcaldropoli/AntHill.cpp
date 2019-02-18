#include "Ant.h"
#include "AntHill.h"
#include "LinkedList.h"
#include <iostream>
#include <cstdlib>
#include <fstream>

#define GRID 20

using namespace std;

//Constructor
AntHill::AntHill() {
	//Open Log File
	this->file.open("anthill.log");

	//Set Default Values
	this->current_ants = 0;
	this->next_id = 0;
	this->food = 0;
	this->turns = 0;
	this->attacks = 0;
	this->wins = 0;
	this->losses = 0;

	//Default 3 Ants
	this->ants = new LinkedList();
	this->addAnt();
	this->addAnt();
	this->addAnt();
}

//Destructor
AntHill::~AntHill() {
	//Delete All Ants
	this->ants->reset();
	Ant * tempAnt = this->ants->get();

	while(tempAnt) {
		delete tempAnt;
		tempAnt = this->ants->get();
	}

	delete this->ants;
	//Close Log File
	this->file.close();
}

//Adds an ant to the list and returns it's id
int AntHill::addAnt() {
	int ret = this->next_id;
	this->ants->add(new Ant(this->next_id));
	this->current_ants++;
	this->next_id++;
	return ret;
}

//Removes an ant with the specified id and returns a boolean based on the id
bool AntHill::removeAnt(int id) {
	bool rem = this->ants->remove(id);
	if(rem) this->current_ants--;
	return rem;
}

//Gets an ant with a specified id and returns a pointer to it
Ant * AntHill::getAnt(int id) {
	return this->ants->get(id);
}

//Moves all of the ants iteratively
void AntHill::move() {
	Ant * tempAnt = this->ants->get();

	while(tempAnt) {
		tempAnt->move();
		tempAnt->moveInGrid(GRID);

		int r = rand() % 5;

		//Check if ant encountered another ant
		if(r == 0) {
			//Print to console and log
			printf("Ant #%d has run into a rival ant\n", tempAnt->getID());
			file << "Ant #" << tempAnt->getID() << " has run into a rival ant" << endl;

			if(tempAnt->fight() == true) {
				//Print to console and log
				printf("Ant #%d wins the fight\n", tempAnt->getID());
				file << "Ant #" << tempAnt->getID() << " wins the fight" << endl;
			} else {
				//Print to console and log
				printf("Ant #%d loses the fight and dies\n", tempAnt->getID());
				file << "Ant #" << tempAnt->getID() << " loses the fight and dies" << endl;

				//Update ants after loss
				this->ants->reset();

				Ant * tempAnt2 = this->ants->get();

				if(tempAnt == tempAnt2) {
					this->removeAnt(tempAnt->getID());
					delete tempAnt;
					this->ants->reset();
				} else {
					this->ants->reset();

					while(this->ants->getCurrent() != tempAnt && this->ants->next() != tempAnt) {
						tempAnt2 = this->ants->get();
					}

					this->removeAnt(tempAnt->getID());
					delete tempAnt;
					this->ants->reset();

					while(this->ants->getCurrent() != tempAnt2 && this->ants->next() != tempAnt2) {
						this->ants->get();
					}
				}
			}
		} else {
			//Random food chance
			r = rand() % 5;
			if(r == 0) this->food++;
		}
		tempAnt = this->ants->get();
	}
	this->ants->reset();
}

//Prints the ant farm info to the terminal
void AntHill::print() {
	printf("\t=============== Turn #%d ===============\n", this->turns);
	printf("The hill current has:\n");
	printf("\tFood: %d\n", this->food);
	printf("\tAnts: %d\n", this->current_ants);
	printf("The hill has been attacked %d times.\n", this->attacks);
	printf("\tSuccessfully defended: %d\n", this->wins);
	printf("\tFailed to defend: %d\n", this->losses);
}

//Logs the ant farm info in anthill.log
void AntHill::printFarmInfo() {
	file << "\t=============== Turn #" << this->turns << " ===============" << endl;
	file << "The hill currently has:" << endl;
	file << "\tFood: " << this->food << endl;
	file << "\tAnts: " << this->current_ants << endl;
	file << "The hill has been attacked " << this->attacks << " times." << endl;
	file << "\tSuccessfully defended: " << this->wins << endl;
	file << "\tFailed to defend: " << this->losses << endl;
}

//Controls each turn
void AntHill::turn() {
	//Print to console and log
	print();
	printFarmInfo();

	//Create new ants
	while(this->food > 0 && this->current_ants > 0) {
		this->addAnt();
		this->food--;
	}

	//Possible attack on AntHill
	int r = rand() % 5;

	if(r == 0) {
		this->attacks++;
		int attackers = rand() % this->current_ants + 1;
		int defenders = 0;
		this->ants->reset();

		Ant * tempAnt = this->ants->get();

		//Determine # of defenders
		while(tempAnt) {
			if(tempAnt->getX() >= -(GRID/4) && tempAnt->getX() <= (GRID/4) &&
			   tempAnt->getY() >= -(GRID/4) && tempAnt->getY() <= (GRID/4)) {
				defenders++;
			}

			tempAnt = this->ants->get();
		}

		//Determine outcome
		if(attackers > defenders) {
			this->losses++;
			this->food = 0;
			this->ants->reset();
			tempAnt = this->ants->get();

			//Print to console and log
			printf("The AntHill was attacked and the following ants died:\n");
			file << "The AntHill was attacked and the following ants died:" << endl;

			while(tempAnt) {
				if(tempAnt->getX() >= -(GRID/4) && tempAnt->getX() <= (GRID/4) &&
				   tempAnt->getY() >= -(GRID/4) && tempAnt->getY() <= (GRID/4)) {
					//Print to console and log
					printf("\tAnt #%d\n", tempAnt->getID());
					file << "\tAnt #" << tempAnt->getID() << endl;

					//Update ants
					this->removeAnt(tempAnt->getID());
					delete tempAnt;
					this->ants->reset();
				}

				tempAnt = this->ants->get();
			}
		} else this->wins++;
	}

	//Move and update turn count
	this->move();
	this->turns++;
}
