//
// Created by admin on 4/18/2022.
//

#include "SDL2Renderer.h"
#include "../game_engine/GameObject.h"
#include "Color.h"
#include <iostream>

SDL2Renderer::SDL2Renderer(int _width, int _height) {
    this->tileSize = 24;
    this->width = (_width) * tileSize;
    this->height = _height * tileSize;
    this->window = SDL_CreateWindow("SDL2Renderer", 100, 100,
                                    width, height, SDL_WINDOW_SHOWN);
    this->renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
}



void SDL2Renderer::render(Map *map) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderClear(renderer);

    int height = map->getHeight();
    int width = map->getWidth();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            {
                if ((x + y) % 2 == 0) {
                    drawRectColor(x, y, Color::getEvenBackgroundColor());
                } else {
                    drawRectColor(x, y, Color::getOddBackgroundColor());
                }
                switch (map->getCell(x, y)){
                    case TYPES::HEAD:
                        drawRectColor(x, y, Color::getSnakeHeadColor());
                        break;
                    case TYPES::BODY:
                        drawRectColor(x, y, Color::getSnakeBodyColor());
                        break;
                    case TYPES::TAIL:
                        drawRectColor(x, y, Color::getSnakeTailColor());
                        break;
                    case TYPES::FOOD:
                        drawRectColor(x, y, Color::getFoodColor());
                        break;
                    case TYPES::WALL:
                        drawRectColor(x, y, Color::getWallColor());
                        break;
                    default:
                        break;
                }

            }
        }
    }


    SDL_RenderPresent(renderer);
    SDL_Delay(50);
}

SDL2Renderer::~SDL2Renderer() {
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
}

void SDL2Renderer::drawRectColor(int x, int y, Color color) {
    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);
    SDL_Rect rect = {x * tileSize, y * tileSize, tileSize, tileSize};
    SDL_RenderFillRect(renderer, &rect);
}
