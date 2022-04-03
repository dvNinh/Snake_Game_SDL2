//
// Created by admin on 3/31/2022.
//

#include "Snake.h"

Snake::~Snake() {
    delete[] head;
    delete[] tail;
}

void Snake::move() {
    tail->moveTo(head->getPosition());
    head->move(direction);
}

void Snake::setDirection(Coordinate direction) {
    // if the snake is moving in the opposite direction, don't allow it
    if (this->direction.x * direction.x < 0 ||
        this->direction.y * direction.y < 0) {
        return;
    }
    this->direction = direction;
}

GameObject *Snake::getHead() {
    return head;
}

GameObject *Snake::getTail() {
    return tail;
}

