//
// Created by admin on 4/11/2022.
//

#include "SimpleAI.h"
#include "GameEngine.h"

int SimpleAI::chooseDirection(Map *map, Coordinate snakeHead) {
    int direction = rand() % 4;
    // find head of snake
    // not choosing the direction that the snake is currently moving in
    Coordinate directionCoordinates[4] = {
            {snakeHead.x + 1, snakeHead.y},
            {snakeHead.x - 1, snakeHead.y},
            {snakeHead.x, snakeHead.y + 1},
            {snakeHead.x, snakeHead.y - 1}
    };
    for (int i = 0; i < 4; i++) {
        auto &coordinate = directionCoordinates[i];
        if (map->getCell(coordinate.x, coordinate.y) == TYPES::EMPTY ||
        map->getCell(coordinate.x, coordinate.y) == TYPES::FOOD) {
            direction = i;
            break;
        }
    }
    switch (direction) {
        case 0:
            return KeyPress::RIGHT;
        case 1:
            return KeyPress::LEFT;
        case 2:
            return KeyPress::DOWN;
        case 3:
            return KeyPress::UP;
    }
}
