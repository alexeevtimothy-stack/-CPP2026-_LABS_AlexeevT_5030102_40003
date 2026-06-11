#include "IndestructableBlock.h"

IndestructibleBlock::IndestructibleBlock(float x, float y) : Block(x, y, 1, sf::Color(128, 128, 128)) {}
void IndestructibleBlock::hit(int& score) {}