#include "Square.h"

Square::Square(int color) : colorId(color) {}

sf::Color Square::getColor() const {
    return Colors[colorId];
}

std::unique_ptr<Square> Square::clone() const {
    return std::make_unique<Square>(colorId);
}