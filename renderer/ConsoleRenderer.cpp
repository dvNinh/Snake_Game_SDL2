//
// Created by admin on 3/31/2022.
//

#include "ConsoleRenderer.h"
#include "../game_engine/GameObject.h"

void ConsoleRenderer::render(Map* map) {

    // Clear the screen
    int height = map->getHeight();
    int width = map->getWidth();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (map->getCell(x, y) == TYPES::EMPTY) {
                std::cout << "  ";
            } else if (map->getCell(x, y) == TYPES::HEAD) {
                std::cout << "H ";
            } else if (map->getCell(x, y) == TYPES::TAIL) {
                std::cout << "T ";
            } else if (map->getCell(x, y) == TYPES::BODY) {
                std::cout << "B ";
            } else if (map->getCell(x, y) == TYPES::FOOD) {
                std::cout << "F ";
            } else if (map->getCell(x, y) == TYPES::WALL) {
                std::cout << "W ";
            }
        }
        std::cout << std::endl;
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
    system("cls");
}
