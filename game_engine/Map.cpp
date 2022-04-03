//
// Created by admin on 4/3/2022.
//

#include "Map.h"
#include "GameObject.h"

Map::Map(int width, int height) {
    this->width = width;
    this->height = height;
    this->map = new int*[height];
    for (int i = 0; i < height; i++) {
        this->map[i] = new int[width];
    }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            this->map[i][j] = TYPES::EMPTY;
        }
    }
}

Map::~Map() {
    for (int i = 0; i < this->height; i++) {
        delete[] this->map[i];
    }
    delete[] this->map;
}

void Map::setCell(int x, int y, char c) {
    this->map[y][x] = c;
}

char Map::getCell(int x, int y) {
    return this->map[y][x];
}

int Map::getWidth() {
    return this->width;
}

int Map::getHeight() {
    return this->height;
}

