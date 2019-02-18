#ifndef HASH_H
#define HASH_H

#include <string>
#include <vector>

class Hash {
    private:
        std::vector<std::pair<std::string, std::string>> hash;
        int maxSize;
        int currSize;
    public:
        Hash(unsigned int size);
        bool insert(std::string key, std::string value);
        bool remove(std::string key);
        std::string find(std::string key);
        bool empty();
        int size();
        void printHash();
        int hasher(std::string key);
};

#endif
