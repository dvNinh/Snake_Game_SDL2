//
// Created by admin on 3/31/2022.
//

#include "GameEngine.h"
#include "../renderer/Renderer.h"
#include "SimpleAI.h"
# include <iostream>

int GameEngine::getKey() {
    // generate map
    generateMap();
    // using simple AI to generate path
    return ai->chooseDirection(map,snake->getHead()->getPosition());
}


void GameEngine::render(Renderer* renderer) {
    // regenerate map for next step
    generateMap();
    // render map
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
    if(snake->getHead()->getPosition() == food->getPosition()) {
        snake->grow();
        generateFood();
    }
}

int GameEngine::getStatus() {
    return Status::RUNNING;
}

GameEngine::GameEngine() {
    width = 10;
    height = 25;
    snake = new Snake(width / 2, height / 2, Coordinate{0, 1});
    snake->grow();
    snake->grow();
    snake->grow();
    generateWall();
    generateFood();
    ai = new SimpleAI();
    status = Status::RUNNING;
    map = new Map(width, height);
}

void GameEngine::generateWall() {
    // generate wall around the map
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            if (x == 0 || x == width - 1 || y == 0 || y == height - 1) {
                walls.emplace_back(x, y, TYPES::WALL);
            }
        }
    }

}

void GameEngine::generateFood() {
    // select random position for food that is not occupied by snake and wall
    int x = rand() % width;
    int y = rand() % height;
    Coordinate foodPosition{x, y};
    if (!isFoodOnWall(foodPosition) && !isFoodOnSnake(foodPosition)) {
        food = new GameObject(foodPosition, TYPES::FOOD);
    } else {
        generateFood();
    }
}

bool GameEngine::isFoodOnSnake(Coordinate coordinate) {
    for (auto node: snake->getNodes()) {
        if (node.getPosition() == coordinate) {
            return true;
        }
    }
    return false;
}

bool GameEngine::isFoodOnWall(Coordinate coordinate) {
    for (auto wall: walls) {
        if (wall.getPosition() == coordinate) {
            return true;
        }
    }
    return false;
}

void GameEngine::generateMap() {
    // refill map with empty cells
    for (int y = 0; y < map->getHeight(); y++) {
        for (int x = 0; x < map->getWidth(); x++) {
            map->setCell(x, y, TYPES::EMPTY);
        }
    }
    // fill map with snake cells
    for(auto node: snake->getNodes()){
        Coordinate tailPosition = node.getPosition();
        map->setCell(tailPosition.x, tailPosition.y, node.getSymbol());
    }
    // fill map with food cells
    map -> setCell(food->getPosition().x, food->getPosition().y, food->getSymbol());
    // fill map with wall cells
    for(auto wall: walls){
        map->setCell(wall.getPosition().x, wall.getPosition().y, wall.getSymbol());
    }
}


