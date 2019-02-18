#include "Map.h"

using namespace std;
typedef pair<int, City *> iPair;

Map::Map(string filename){
	ifstream inFile(filename);
	string name;
	int x;
	int y;
	while(inFile >> name >> x >> y) cities.push_back(new City(name,x,y));

        for(unsigned int i = 0; i < this->cities.size(); i++) {
            City * temp = this->cities[i];
            this->addAdjacencies(temp);
        }
}

Map::Map(string filename, bool heap){
	ifstream inFile(filename);
	string name;
	int x;
	int y;
	this->heap = heap;
	while(inFile >> name >> x >> y) cities.push_back(new City(name,x,y));

        for(unsigned int i = 0; i < this->cities.size(); i++) {
            City * temp = this->cities[i];
            this->addAdjacencies(temp);
        }
}

Map::~Map(){
	for(auto iter:cities) delete iter;
}

City* Map::findByName(string cityName){
	for(auto i = cities.begin(); i < cities.end(); i++){
	    if((*i)->getName() == cityName) return (*i);
	}
	return NULL;
}

void Map::addAdjacencies(City * city) {
    City * temp;
    City * north = NULL;
    City * south = NULL;
    City * east = NULL;
    City * west = NULL;
    int x = city->getXCoor();
    int y = city->getYCoor();

    for(unsigned int i = 0; i < this->cities.size(); i++) {
        temp = this->cities[i];

        if(temp->getXCoor() == x) {
            if(temp->getYCoor() > y) {
                if(north == NULL) north = temp;
                else if(north->getYCoor() > temp->getYCoor()) north = temp;
            } else if(temp->getYCoor() < y) {
                if(south == NULL) south = temp;
                else if(south->getYCoor() < temp->getYCoor()) south = temp;
            }
        }

        if(temp->getYCoor() == y) {
            if(temp->getXCoor() > x) {
                if(east == NULL) east = temp;
                else if(east->getXCoor() > temp->getXCoor()) east = temp;
            } else if(temp->getXCoor() < x) {
                if(west == NULL) west = temp;
                else if(west->getXCoor() < temp->getXCoor()) west = temp;
            }
        }
    }

    if(north) city->addAdjacent(north);
    if(south) city->addAdjacent(south);
    if(east) city->addAdjacent(east);
    if(west) city->addAdjacent(west);
}

vector<City *> Map::shortestPath(City * start, City * dest){
    if(heap){
        City * current;
        priority_queue< iPair, vector<iPair> , greater<iPair> > pq;
        vector<City*> path;
        list<City *> adjacent;
        start->distance = 0;
        unsigned int x;
        pq.push(make_pair(start->distance, start));
            
        while(!pq.empty()) {
            current = pq.top().second;
	    pq.pop();
	    adjacent = current->getAdjacent();
	    for(auto iter:adjacent){
                x = current->distance + pathDistance(current, iter);
                if(x < iter->distance){
                    iter->distance = x;
                    iter->previous = current;
                }
                if(!(iter->visited)){ 
                    pq.push(make_pair(iter->distance, iter));
                    iter->visited = true;
                }
	    }
        }
            
        current = dest;
	if(dest->distance != INT_MAX){
	    while(path.empty() || path[0] != start){
		path.insert(path.begin(), current);
		current = current->previous;
	    }
	}

	return path;
    }else{
	City* current;
	vector<City*> path(cities.size());
	list<City *> adjacent;
	cities.erase(find(cities.begin(), cities.end(), start));
	int l = 0;
	unsigned int x;
	
	path[0] = start;
	
	
	for(int i = 0; i < path.size(); i++){
	    if(path[i] != NULL){
		adjacent = path[i]->getAdjacent();
		for(auto iter = adjacent.begin(); iter != adjacent.end(); iter++){
		    if(find(path.begin(), path.end(), *iter) == path.end()){
			l++;
			path[l] = *iter;
			path[l]->distance = INT_MAX;
		    }
		}
	    }
	}
	
	for(auto iter = cities.begin(); iter != cities.end(); iter++){
	    if(find(path.begin(), path.end(), *iter) == path.end()){
		l++;
		path[l] = *iter;
		path[l]->distance = INT_MAX;
	    }
	}

	path[0]->distance = 0;
	cities.push_back(start);

	while(!path.empty()){
	    current = path.front();
	    path.erase(path.begin());
	    adjacent = current->getAdjacent();
	    for(auto iter:adjacent){
		x = current->distance + pathDistance(current, iter);
		if(x < iter->distance){
		    iter->distance = x;
		    iter->previous = current;
		}
	    }
	}

	current = dest;
	if(dest->distance != INT_MAX){
	    while(path[0] != start){
		path.insert(path.begin(), current);
		current = current->previous;
	    }
	}
	else path.clear();
	return path;	
    }	 			
}


int Map::pathDistance(City *start, City* dest){
    int x1 = start->getXCoor();
    int x2 = dest->getXCoor();
    int y1 = start->getYCoor();
    int y2 = dest->getYCoor();

    if(start == dest) return 0;
    if(x1 == x2) return abs(y2-y1);
    if(y1 == y2) return abs(x2-x1);

    shortestPath(start, dest);

    if(dest->distance == INT_MAX) return -1;
    return dest->distance;
    
}

