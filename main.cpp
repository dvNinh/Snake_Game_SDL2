#define SDL_MAIN_HANDLED

#include <iostream>
#include "./game_engine/GameEngine.h"
#include "renderer/ConsoleRenderer.h"
#include "renderer/SDL2Renderer.h"


int main() {
    int width = 15;
    int height = 15;
//    ConsoleRenderer* renderer = new ConsoleRenderer();
    Renderer* renderer = new SDL2Renderer(width, height);
    GameEngine* gameEngine = new GameEngine(width, height);
    int step = 0;
    int status = gameEngine->getStatus();
    while (status == Status::RUNNING) {
        step++;
        if (step == 157) {
            std::cout << "step: " << step << std::endl;
        }
        std::cout << "Step: " << step << std::endl;
        auto key = gameEngine->getKey();
        if (key == KeyPress::ESCAPE) {
            status = Status::EXIT;
        }
        gameEngine->step(key);
        gameEngine->render(renderer);
        status = gameEngine->getStatus();
        if (status == Status::EXIT) {
            std::cout << "Exiting..." << std::endl;
            return 1;
        }
    }
    return 0;
}
