//
// Created by admin on 3/31/2022.
//

#include "ConsoleRenderer.h"
#include "../game_engine/GameObject.h"

void ConsoleRenderer::render(Map* map) {

    // Clear the screen
    int height = map->getHeight();
    int width = map->getWidth();
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (map->getCell(i,j) == TYPES::EMPTY) {
                std::cout << "# ";
            } else if (map->getCell(i,j) == TYPES::HEAD) {
                std::cout << "H ";
            } else if (map->getCell(i,j) == TYPES::TAIL) {
                std::cout << "T ";
            }
        }
        std::cout << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    system("cls");
}
