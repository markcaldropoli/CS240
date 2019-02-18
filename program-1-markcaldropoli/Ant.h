#ifndef ANT_H
#define ANT_H

class Ant {
	private:
		int id;
		int x;
		int y;
		int xp;
	public:
		//Constructor & Destructor
		Ant(int);
		Ant(const Ant &);
		//Ant Methods
		bool fight();
		void move();
		void moveInGrid(int);
		//Getters
		inline int getID(){return this->id;}
		inline int getX(){return this->x;}
		inline int getY(){return this->y;}
		inline int getXP(){return this->xp;}
};

#endif
