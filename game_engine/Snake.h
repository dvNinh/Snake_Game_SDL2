//
// Created by admin on 3/31/2022.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H


#include "GameObject.h"
#include <vector>

class Snake {
private:
    std::vector<GameObject> nodes;
    Coordinate direction;
    int length;
public:
    Snake(int x, int y, Coordinate _direction){
        this->direction = _direction;
        length = 1;
        auto head = new GameObject(x, y, TYPES::HEAD);
        auto tail = new GameObject(x, y-1, TYPES::TAIL);
        nodes.push_back(*head);
        nodes.push_back(*tail);
    }
    ~Snake();
    void move();
    void grow();
    void setDirection(Coordinate direction);
    int getDirection();
    int getLength();
    GameObject* getHead();
    GameObject* getTail();

    std::vector<GameObject> getNodes();
};



#endif //SNAKE_SNAKE_H
