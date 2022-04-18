#include <iostream>
#include "./game_engine/GameEngine.h"
#include "renderer/ConsoleRenderer.h"

int main() {
    int width = 10;
    int height = 25;
    ConsoleRenderer* renderer = new ConsoleRenderer();
    GameEngine* gameEngine = new GameEngine(width, height);
    int status = gameEngine->getStatus();
    while (status == Status::RUNNING) {
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
