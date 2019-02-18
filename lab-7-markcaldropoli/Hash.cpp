#include "Hash.h"
#include <iostream>

using namespace std;

Hash::Hash(unsigned int size) {
    this->hash.reserve(size);
    this->maxSize = size;
    this->currSize = 0;

    for(int i = 0; i < this->maxSize; i++) {
        this->hash.push_back(std::make_pair("",""));
    }
}

bool Hash::insert(string key, string value) {
    if(this->maxSize == this->currSize) return false;

    int index = hasher(key);

    while(hash.at(index).first != "") {
        ++index;
        index %= this->maxSize;
    }

    hash.at(index) = std::make_pair(key,value);
    this->currSize++;
    return true;
}

bool Hash::remove(string key) {
    int index = hasher(key);

    for(int i = 0; i < this->maxSize; i++) {
        if(hash[i].first == key) {
            hash[i] = make_pair("","");
            this->currSize--;
            return true;
        }
        ++index;
        index %= this->maxSize;
    }
    return false;
}

string Hash::find(string key) {
    int index = hasher(key);

    for(int i = 0; i < this->maxSize; i++) {
        if(hash[i].first == key) return hash[i].second;
        ++index;
        index %= this->maxSize;
    }
    return "";
}

bool Hash::empty() {
    for(int i = 0; i < this->maxSize; i++) {
        if(hash[i].first != "") return false;
    }
    return true;
}

int Hash::size() {
    return this->maxSize;
}

void Hash::printHash() {
    for(int i = 0; i < this->maxSize; i++) {
        cout << "\tIndex:" << i << "\tKey:" << hash[i].first << "\tValue:" << hash[i].second << endl;
    }
}

int Hash::hasher(string key) {
    int keyToValue = 0;

    for(int i = 0; i < key.length(); i++) {
        keyToValue += static_cast<int>(key.at(i));
    }

    return keyToValue % this->maxSize;
}
