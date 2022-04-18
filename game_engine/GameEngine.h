//
// Created by admin on 3/31/2022.
//

#ifndef SNAKE_GAMEENGINE_H
#define SNAKE_GAMEENGINE_H


#include "Snake.h"
#include "../renderer/Renderer.h"
#include "Map.h"
#include "SimpleAI.h"

enum KeyPress
{
    UP,
    DOWN,
    LEFT,
    RIGHT,
    ESCAPE,
    SPACE,
    ENTER
};

enum Status
{
    EXIT,
    RUNNING,
};

class GameEngine {
private:
    Map* map;
    Snake* snake;
    GameObject* food;
    SimpleAI *ai;
    std::vector<GameObject> walls;

    int status;
    int width;
    int height;
public:
    GameEngine(int _width, int _height);
    ~GameEngine() = default;
    void step(int key);
    int getStatus();
    int getKey();
    void render(Renderer *renderer);

    void generateWall();
    void generateFood();

    bool isFoodOnSnake(Coordinate coordinate);
    bool isFoodOnWall(Coordinate coordinate);

    void generateMap();

};


#endif //SNAKE_GAMEENGINE_H
