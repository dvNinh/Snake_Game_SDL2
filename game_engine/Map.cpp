//
// Created by admin on 4/3/2022.
//

#include "Map.h"
#include "GameObject.h"

Map::Map(int width, int height) {
    this->width = width;
    this->height = height;
    this->map = new int*[width];
    for (int x = 0; x < width; x++) {
        this->map[x] = new int[height];
    }
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            this->map[x][y] = TYPES::EMPTY;
        }
    }
}

Map::~Map() {
    for (int x = 0; x < this->width; x++) {
        delete[] this->map[x];
    }
    delete[] this->map;
}

void Map::setCell(int x, int y, char c) {
    this->map[x][y] = c;
}

char Map::getCell(int x, int y) {
    return this->map[x][y];
}

int Map::getWidth() {
    return this->width;
}

int Map::getHeight() {
    return this->height;
}

