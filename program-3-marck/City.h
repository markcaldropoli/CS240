#ifndef CITY_H
#define CITY_H

#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <climits>

class City {
    private:
        std::string name;
        int x;
        int y;
        std::list<City*> adjacency;
    public:
        City(std::string cityName, int xCoor, int yCoor);
        std::string getName();
        int getXCoor();
        int getYCoor();
        std::list<City*> getAdjacent();
        bool operator<(City &c);
        void addAdjacent(City * city);
	int distance = INT_MAX;
	bool visited = false;
	City * previous;
};

#endif
