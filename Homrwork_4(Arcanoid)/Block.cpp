#include "Block.h"

Block::Block(float x, float y, int hp, sf::Color color)
    : health(hp), destroyed(false), baseColor(color) {
    shape.setPosition({ x, y });
    shape.setSize({ BLOCK_WIDTH, BLOCK_HEIGHT });
    shape.setFillColor(color);
    shape.setOutlineColor(sf::Color::Black);
    shape.setOutlineThickness(1.0f);
}

void Block::hit(int& score) {
    if (health > 0) {
        health--;
        score += 1;

        if (health == 0) {
            destroyed = true;
        }
        else {
    
            sf::Color currentC = baseColor;
            currentC.a = static_cast<uint8_t>(85 * health);
            shape.setFillColor(currentC);
        }
    }
}

bool Block::isDestroyed() const { return destroyed; }
const sf::RectangleShape& Block::getShape() const { return shape; }
void Block::draw(sf::RenderWindow& window) { window.draw(shape); }