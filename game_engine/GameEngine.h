//
// Created by admin on 3/31/2022.
//

#ifndef SNAKE_GAMEENGINE_H
#define SNAKE_GAMEENGINE_H


#include "Snake.h"
#include "../renderer/Renderer.h"
#include "Map.h"

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
//    Food* foods;
//    Wall* walls;
    int status;
    int width;
    int height;
public:
    GameEngine();
    ~GameEngine() = default;
    void step(int key);
    int getStatus();
    int getKey();
    void render(Renderer *renderer);
};


#endif //SNAKE_GAMEENGINE_H
