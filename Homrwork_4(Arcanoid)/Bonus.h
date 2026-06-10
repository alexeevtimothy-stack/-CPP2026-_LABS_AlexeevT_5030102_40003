#pragma once
#include "Common.h"

class Paddle;
class Ball;

class Bonus {
protected:
    sf::CircleShape shape;

public:
    Bonus(float x, float y, sf::Color color);
    virtual ~Bonus() = default;

    void update(float deltaTime);
    bool isOutOfBounds() const;
    const sf::CircleShape& getShape() const;
    void draw(sf::RenderWindow& window);

    virtual void apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) = 0;
};