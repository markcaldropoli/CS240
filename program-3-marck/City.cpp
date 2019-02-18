#include "City.h"

using namespace std;

City::City(string cityName, int xCoor, int yCoor) {
	this->name = cityName;
	this->x = xCoor;
	this->y = yCoor;
}

string City::getName() {
	return this->name;
}

int City::getXCoor() {
	return this->x;
}

int City::getYCoor() {
	return this->y;
}

list<City*> City::getAdjacent() {
	return adjacency;
}

bool City::operator<(City &c) {
	if(this->getName() == c.getName()) return true;
	return false;
}

void City::addAdjacent(City * city) {
    this->adjacency.push_back(city);
}
