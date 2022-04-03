//
// Created by admin on 4/3/2022.
//

#ifndef SNAKE_RENDERER_H
#define SNAKE_RENDERER_H

#include "../game_engine/Map.h"

class Renderer{
public:
    virtual void render(Map* map) = 0;
};

#endif //SNAKE_RENDERER_H
