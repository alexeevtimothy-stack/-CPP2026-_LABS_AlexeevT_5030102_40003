#include "Square.h"

Square::Square(int color) : colorId(color) {}

int Square::getColorId() const { return colorId; }
void Square::setColorId(int color) { colorId = color; }

bool Square::getIsMatched() const { return isMatched; }
void Square::setMatched(bool matched) { isMatched = matched; }

sf::Color Square::getColor() const {
    return Colors[colorId];
}

void Square::onDestroy(Board& board, int c, int r, std::mt19937& g) {}

std::unique_ptr<Square> Square::clone() const {
    return std::make_unique<Square>(colorId);
}