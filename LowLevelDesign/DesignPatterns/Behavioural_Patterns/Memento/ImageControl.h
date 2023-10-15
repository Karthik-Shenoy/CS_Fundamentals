#pragma once
#include <string>
#include <chrono>
#include "./Memento.h"
#include "./ImageControlMemento.h"
using namespace std;

class ImageControl
{
private:
    int16_t x;
    int16_t y;
    uint16_t rotation;
    uint16_t width;
    uint16_t height;
    
public:
    ImageControl(int16_t x, int16_t y, uint16_t rotation, uint16_t width, uint16_t height)
    {
        
        this->x = x;
        this->y = y;
        this->width = width;
        this->height = height;
        this->rotation = rotation;
    }
    void setX(short x)
    {
        this->x = x;
    }
    void setY(short y)
    {
        this->y = y;
    }
    void setWidth(uint16_t width)
    {
        this->width = width;
    }
    void setHeight(uint16_t height)
    {
        this->height = height;
    }
    void setRotation(uint16_t rotation)
    {
        this->rotation;
    }
    Memento *createSnapshot()
    {
        return new ImageControlMemento(this, this->x, this->y, this->rotation, this->width, this->height);
    }
};