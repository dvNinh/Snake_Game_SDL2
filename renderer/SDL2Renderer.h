//
// Created by admin on 4/18/2022.
//

#ifndef SNAKE_SDL2RENDERER_H
#define SNAKE_SDL2RENDERER_H


#include "Renderer.h"
#include "SDL2/SDL.h"
#include "Color.h"

class SDL2Renderer : public Renderer{
private:
    int width;
    int height;
    int tileSize;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Texture *foodTexture;
    void drawRectColor(int x, int y, Color color);

public:
    SDL2Renderer();
    SDL2Renderer(int _width, int height);
    ~SDL2Renderer();
    void render(Map* map) override;


    void drawRoundColor(int x, int y, Color color);

    void drawFood(int x, int y);
};


#endif //SNAKE_SDL2RENDERER_H
