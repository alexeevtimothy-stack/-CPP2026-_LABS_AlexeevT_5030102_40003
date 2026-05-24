#pragma once
#include "Common.h"

class Square {
public:
    int colorId;
    bool isMatched = false;
    Square(int color);
    virtual ~Square() = default;
    virtual sf::Color getColor() const;
    virtual void onDestroy(Board& board, int c, int r, std::mt19937& g) {};
    virtual std::unique_ptr<Square> clone() const;
};