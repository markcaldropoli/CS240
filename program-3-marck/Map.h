#ifndef MAP_H
#define MAP_H

#include "City.h"
#include <vector>
#include <algorithm>
#include <climits>
#include <queue>
#include <functional>

class Map{
    private:
        std::vector<City*> cities;
	bool heap = false;
    public:
        Map(std::string filename);
	Map(std::string filename, bool heap);
	~Map();
        City* findByName(std::string cityName);
        void addAdjacencies(City * city);
	std::vector<City *> shortestPath(City * start, City * dest);
	int pathDistance(City *start, City* end);
};

#endif
