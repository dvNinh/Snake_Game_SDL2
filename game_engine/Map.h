//
// Created by admin on 4/3/2022.
//

#ifndef SNAKE_MAP_H
#define SNAKE_MAP_H


class Map {
    int** map;
    int width;
    int height;
public:
    Map(int width, int height);
    ~Map();
    void setCell(int x, int y, char c);
    char getCell(int x, int y);
    int getWidth();
    int getHeight();
};


#endif //SNAKE_MAP_H
