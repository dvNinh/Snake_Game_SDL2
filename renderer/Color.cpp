//
// Created by admin on 4/20/2022.
//

#include "Color.h"
#include <string>

Color::Color(int r, int g, int b) {
    this->r = r;
    this->g = g;
    this->b = b;
    this->a = 255;
}

Color::Color(std::string hex_color) {
    if (hex_color.length() == 7) {
        r = std::stoi(hex_color.substr(1, 2), nullptr, 16);
        g = std::stoi(hex_color.substr(3, 2), nullptr, 16);
        b = std::stoi(hex_color.substr(5, 2), nullptr, 16);
        a = 255;
    } else if (hex_color.length() == 9) {
        r = std::stoi(hex_color.substr(1, 2), nullptr, 16);
        g = std::stoi(hex_color.substr(3, 2), nullptr, 16);
        b = std::stoi(hex_color.substr(5, 2), nullptr, 16);
        a = std::stoi(hex_color.substr(7, 2), nullptr, 16);
    } else {
        r = 0;
        g = 0;
        b = 0;
        a = 0;
    }
}

Color Color::getWallColor() {
    return Color(87, 138, 52);
}

Color Color::getFoodColor() {
    return Color(255, 0, 0);
}

Color Color::getSnakeHeadColor() {
    return Color(26,115,232);
}

Color Color::getSnakeTailColor() {
    return Color(26,115,232);
}

Color Color::getSnakeBodyColor() {
    return Color(26,115,232);
}

Color Color::getEvenBackgroundColor() {
    return Color(162, 209, 73);
}

Color Color::getOddBackgroundColor() {
    return Color(170, 215, 81);
}



