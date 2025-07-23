#ifndef STATICTEXTCOMPONENT_H
#define STATICTEXTCOMPONENT_H

#include "Component.h"

class TextField: public Component
{
private:
    std::string text;

    int width;
    int height;

    int x;
    int y;
public:
    TextField(std::string text, int width, int height)
    {
        this->text = text;

        this->width = width;
        this->height = height;

        this->x = 0;
        this->y = 0;
    }

    void setSize(int width, int height)
    {
        this->width = width;
        this->height = height;
    }

    void setPosition(int x, int y) { this->x = x; this->y = y; }

    std::string getText() { return this->text; }

    int getWidth() { return this->width; }
    int getHeight() { return this->height; }

    int getX() { return this->x; }
    int getY() { return this->y; }
};

#endif