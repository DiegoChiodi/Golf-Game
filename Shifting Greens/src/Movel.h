#pragma once

#include "Square.h"

class Movel : public Square {
protected:
    vector speed;
public:
    Movel(float x, float y, float width, float height, SDL_Color color, vector speed);
};