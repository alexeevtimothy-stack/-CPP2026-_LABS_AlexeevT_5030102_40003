#pragma once
#include "Square.h"

class Painter : public Square {
public:
    Painter(int color);
    sf::Color getColor() const override;
    void onDestroy(Board& board, int c, int r, std::mt19937& g) override;
    std::unique_ptr<Square> clone() const override;
};