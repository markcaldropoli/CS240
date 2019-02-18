#ifndef HEAP_H
#define HEAP_H

#include "Player.h"
#include <string>
#include <vector>

class Heap {
    private:
        std::vector<Player> players;
    public:
        Heap();
        Heap(std::string filename);
        Heap(Heap &copy);
        bool isLeaf(int i);
        void heapify();
        void siftdown(int i);
        void addPlayer(Player newPlayer);
        Player getPlayer();
        std::vector<Player> getArray() { return this->players; }
        bool empty();
        unsigned int size() { return this->players.size(); }
};

#endif
