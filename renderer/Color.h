//
// Created by admin on 4/20/2022.
//

#ifndef SNAKE_COLOR_H
#define SNAKE_COLOR_H

#include <string>


struct Color {
public:
    Color(int r, int g, int b);
    Color(std::string hex_color);
    int r;
    int g;
    int b;
    int a;
    static Color getWallColor();
    static Color getFoodColor();
    static Color getSnakeHeadColor();
    static Color getSnakeTailColor();
    static Color getSnakeBodyColor();
    static Color getEvenBackgroundColor();
    static Color getOddBackgroundColor();
};



#endif //SNAKE_COLOR_H
