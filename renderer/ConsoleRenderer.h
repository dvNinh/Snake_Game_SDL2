//
// Created by admin on 3/31/2022.
//

#ifndef SNAKE_CONSOLERENDERER_H
#define SNAKE_CONSOLERENDERER_H


#include "Renderer.h"
#include <iostream>
#include <chrono>
#include <thread>

class ConsoleRenderer: public Renderer {
public:
    void render (Map* map) override;

};


#endif //SNAKE_CONSOLERENDERER_H
