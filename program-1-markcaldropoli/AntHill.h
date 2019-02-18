#ifndef ANTHILL_H
#define ANTHILL_H

#include "Ant.h"
#include "LinkedList.h"
#include <iostream>
#include <fstream>

class AntHill {
	private:
		LinkedList * ants;
		int turns;
		int food;
		int current_ants;
		int next_id;
		int attacks;
		int wins;
		int losses;
		std::ofstream file;
	public:
		//Constructor & Destructor
		AntHill();
		~AntHill();
		//CRUD Operations
		int addAnt();
		bool removeAnt(int);
		Ant * getAnt(int);
		void print();
		void printFarmInfo();
		//AntHill Methods
		void move();
		void turn();
		//Getter
		inline int getCurrentNumAnts() {return this->current_ants;}
};

#endif
