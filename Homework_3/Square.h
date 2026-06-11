#pragma once
#include "Common.h"

class Square {
protected:
    int colorId;
    bool isMatched = false;

public:
    Square(int color);
    virtual ~Square() = default;

    int getColorId() const;
    void setColorId(int color);

    bool getIsMatched() const;
    void setMatched(bool matched);

    virtual sf::Color getColor() const;
    virtual void onDestroy(Board& board, int c, int r, std::mt19937& g);
    virtual std::unique_ptr<Square> clone() const;
};