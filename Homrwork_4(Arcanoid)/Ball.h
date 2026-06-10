#pragma once
#include "Common.h"

class Ball {
private:
    sf::CircleShape shape;
    sf::Vector2f velocity;
    bool stuckToPaddle;

public:
    Ball();
    void reset(sf::Vector2f paddlePos, float paddleWidth);
    void update(float deltaTime);

    void bounceVelocityX();
    void bounceVelocityY();

    void setPosition(sf::Vector2f pos);
    sf::Vector2f getPosition() const;

    void changeSpeed(float factor);
    void setStuck(bool stuck);
    bool isStuck() const;

    const sf::CircleShape& getShape() const;
    void draw(sf::RenderWindow& window);
};