#include "Padle.h"

Paddle::Paddle() { reset(); }

void Paddle::reset() {
    width = PADDLE_START_WIDTH;
    isSticky = false;
    shape.setSize({ width, PADDLE_HEIGHT });
    shape.setFillColor(sf::Color::White);
    shape.setPosition({ (WINDOW_WIDTH - width) / 2.0f, WINDOW_HEIGHT - 40.0f });
}

void Paddle::processInput() {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        shape.move({ -PADDLE_SPEED * 0.016f, 0.0f });
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        shape.move({ PADDLE_SPEED * 0.016f, 0.0f });
    }

    sf::Vector2f pos = shape.getPosition();
    if (pos.x < 0.0f) shape.setPosition({ 0.0f, pos.y });
    if (pos.x + width > WINDOW_WIDTH) shape.setPosition({ WINDOW_WIDTH - width, pos.y });
}

void Paddle::changeSize(float factor) {
    width *= factor;
    if (width < 50.0f) width = 50.0f;
    if (width > 250.0f) width = 250.0f;
    shape.setSize({ width, PADDLE_HEIGHT });
}

void Paddle::setSticky(bool sticky) { isSticky = sticky; }
bool Paddle::getIsSticky() const { return isSticky; }
const sf::RectangleShape& Paddle::getShape() const { return shape; }
void Paddle::draw(sf::RenderWindow& window) { window.draw(shape); }