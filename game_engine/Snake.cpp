//
// Created by admin on 3/31/2022.
//

#include "Snake.h"

Snake::~Snake() {

}

void Snake::move() {
    for (int i = nodes.size() - 1; i > 0; i--) {
        nodes[i].moveTo(nodes[i-1].getPosition());
    }
    nodes[0].move(direction);
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
    return &nodes[0];
}

GameObject *Snake::getTail() {
    return &nodes[nodes.size()-1];
}

void Snake::grow() {
    auto newNodePosition = getTail()->getPosition();
    nodes[nodes.size()-1] = GameObject(newNodePosition,TYPES::BODY);
    newNodePosition.y -= 1;
    nodes.emplace_back(newNodePosition,TYPES::TAIL);
}

std::vector<GameObject> Snake::getNodes() {
    return nodes;
}

