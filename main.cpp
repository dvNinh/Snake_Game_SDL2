#include <iostream>
#include "./game_engine/GameEngine.h"
#include "renderer/ConsoleRenderer.h"

int main() {
    ConsoleRenderer* renderer = new ConsoleRenderer();
    GameEngine* gameEngine = new GameEngine();
    int status = gameEngine->getStatus();
    while (status == Status::RUNNING) {
        auto key = gameEngine->getKey();
        if (key == KeyPress::ESCAPE) {
            status = Status::EXIT;
        }
        gameEngine->step(key);
        gameEngine->render(renderer);
        status = gameEngine->getStatus();
    }
    if (status == Status::EXIT) {
        std::cout << "Exiting..." << std::endl;
    }
    return 0;
}
