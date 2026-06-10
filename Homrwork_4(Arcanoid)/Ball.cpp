#include "Ball.h"

Ball::Ball() {
    stuckToPaddle = true;
    shape.setRadius(BALL_RADIUS);
    shape.setFillColor(sf::Color::Red);
    velocity = { BALL_START_SPEED * 0.707f, -BALL_START_SPEED * 0.707f };
}

void Ball::reset(sf::Vector2f paddlePos, float paddleWidth) {
    stuckToPaddle = true;
    velocity = { BALL_START_SPEED * 0.707f, -BALL_START_SPEED * 0.707f };
    shape.setPosition({ paddlePos.x + paddleWidth / 2.0f - BALL_RADIUS, paddlePos.y - BALL_RADIUS * 2.0f });
}

void Ball::update(float deltaTime) {
    if (!stuckToPaddle) {
        shape.move(velocity * deltaTime);

        sf::Vector2f pos = shape.getPosition();
        if (pos.x <= 0.0f || pos.x + BALL_RADIUS * 2.0f >= WINDOW_WIDTH) {
            velocity.x = -velocity.x;
        }
        if (pos.y <= 0.0f) {
            velocity.y = -velocity.y;
        }
    }
}

void Ball::bounceVelocityX() { velocity.x = -velocity.x; }
void Ball::bounceVelocityY() { velocity.y = -velocity.y; }
void Ball::setPosition(sf::Vector2f pos) { shape.setPosition(pos); }
sf::Vector2f Ball::getPosition() const { return shape.getPosition(); }
void Ball::changeSpeed(float factor) { velocity *= factor; }
void Ball::setStuck(bool stuck) { stuckToPaddle = stuck; }
bool Ball::isStuck() const { return stuckToPaddle; }
const sf::CircleShape& Ball::getShape() const { return shape; }
void Ball::draw(sf::RenderWindow& window) { window.draw(shape); }