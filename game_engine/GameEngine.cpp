//
// Created by admin on 3/31/2022.
//

#include "GameEngine.h"
#include "../renderer/Renderer.h"
# include <iostream>

int GameEngine::getKey() {
    // random choice of key
    char keys[]{'a','w','s','d'};
    char key = keys[int( rand() % 4)];

    switch (key){
        case 'w':
            return KeyPress::UP;
        case 's':
            return KeyPress::DOWN;
        case 'a':
            return KeyPress::LEFT;
        case 'd':
            return KeyPress::RIGHT;
    }
}

void GameEngine::render(Renderer* renderer) {
    // refill map with empty cells
    for (int i = 0; i < map->getHeight(); i++) {
        for (int j = 0; j < map->getWidth(); j++) {
            map->setCell(i, j, TYPES::EMPTY);
        }
    }

    for(auto bodyCell: snake->getNodes()){
        Coordinate bodyPosition = bodyCell.getPosition();
        map->setCell(bodyPosition.x, bodyPosition.y, bodyCell.getSymbol());
    }

    renderer->render(map);
}

void GameEngine::step(int key) {
    Coordinate direction{0, 0};
    switch (key) {
        case KeyPress::UP:
            direction = Coordinate{0, -1};
            break;
        case KeyPress::DOWN:
            direction = Coordinate{0, 1};
            break;
        case KeyPress::LEFT:
            direction = Coordinate{-1, 0};
            break;
        case KeyPress::RIGHT:
            direction = Coordinate{1, 0};
            break;
    }
    snake->setDirection(direction);
    snake->move();
}

int GameEngine::getStatus() {
    return Status::RUNNING;
}

GameEngine::GameEngine() {
    width = 20;
    height = 20;
    snake = new Snake(height / 2, width / 2, Coordinate{0, 1});
    snake->grow();
    snake->grow();
    snake->grow();
    status = Status::RUNNING;
    map = new Map(height, width);
}

