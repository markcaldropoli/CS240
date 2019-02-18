#include "Heap.h"

#include <algorithm>
#include <fstream>

using namespace std;

Heap::Heap() {
    this->players = {};
}

Heap::Heap(string filename) {
    string line;
    ifstream file(filename);

    if(file.is_open()) {
        while(getline(file, line)) {
            string temp = line;
            getline(file, line);
            Player tempPlayer(temp, stoi(line));
            addPlayer(tempPlayer);
        }
        file.close();
    }
}

Heap::Heap(Heap &copy) {
    if(copy.empty()) return;
    for(unsigned int i = 0; i < copy.size(); i++) {
        this->players.push_back((copy.getArray())[i]);
    }
}

bool Heap::isLeaf(int i) {
    unsigned int x = i*2 + 1;
    unsigned int y = i*2 + 2;
    if(x >= this->players.size() && y >= this->players.size()) return true;
    return false;
}

void Heap::heapify() {
    int size = this->players.size()-1;
    for(int i = ((size-1)/2); i >= 0; i--) {
        siftdown(i);
    }
}

void Heap::siftdown(int i) {
    if(i < 0 || i >= this->players.size()) return;
    while(!isLeaf(i)) {
        int child = 2*i + 1;

        if(child+1 < this->players.size() && this->players[child].getBudget() < this->players[child+1].getBudget()) {
            child += 1;
        }

        if(this->players[i].getBudget() < this->players[child].getBudget()) {
            swap(this->players[i], this->players[child]);
        } else return;
        i = child;
    }
}

void Heap::addPlayer(Player newPlayer) {
    this->players.push_back(newPlayer);
    heapify();
}

Player Heap::getPlayer() {
    heapify();
    swap(this->players[0], this->players[this->players.size()-1]);
    Player tempPlayer = this->players.back();
    this->players.pop_back();
    heapify();
    return tempPlayer;
}

bool Heap::empty() {
    if(this->players.size() == 0) return true;
    return false;
}
