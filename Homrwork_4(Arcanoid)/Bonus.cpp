#include "Bonus.h"

Bonus::Bonus(float x, float y, sf::Color color) {
    shape.setRadius(BONUS_RADIUS);
    shape.setPosition({ x, y });
    shape.setFillColor(color);
}

void Bonus::update(float deltaTime) {
    shape.move({ 0.0f, BONUS_SPEED * deltaTime }); 
}

bool Bonus::isOutOfBounds() const { return shape.getPosition().y > WINDOW_HEIGHT; }
const sf::CircleShape& Bonus::getShape() const { return shape; }
void Bonus::draw(sf::RenderWindow& window) { window.draw(shape); }