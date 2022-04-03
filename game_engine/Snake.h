//
// Created by admin on 3/31/2022.
//

#ifndef SNAKE_SNAKE_H
#define SNAKE_SNAKE_H


#include "GameObject.h"

class Snake: public GameObject {
private:
    GameObject *head;
    GameObject *tail;
    Coordinate direction;
    int length;
public:
    Snake(int x, int y, Coordinate _direction): GameObject(x, y, TYPES::SNAKE){
        this->direction = _direction;
        length = 1;
        head = new GameObject(x, y, TYPES::HEAD);
        tail = new GameObject(x, y-1, TYPES::TAIL);
    }
    ~Snake();
    void move();
    void grow();
    void setDirection(Coordinate direction);
    int getDirection();
    int getLength();
    GameObject* getHead();
    GameObject* getTail();
};



#endif //SNAKE_SNAKE_H
