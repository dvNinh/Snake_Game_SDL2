//
// Created by admin on 4/11/2022.
//

#ifndef SNAKE_SIMPLEAI_H
#define SNAKE_SIMPLEAI_H


#include "Map.h"
#include "GameObject.h"

class SimpleAI {
public:
    int chooseDirection(Map *map, Coordinate snakeHead);
};


#endif //SNAKE_SIMPLEAI_H
