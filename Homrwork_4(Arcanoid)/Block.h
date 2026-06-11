#pragma once
#include "Common.h"

class Block {
protected:
    sf::RectangleShape shape;
    int health;
    bool destroyed;
    sf::Color baseColor; 

public:
    Block(float x, float y, int hp, sf::Color color);
    virtual ~Block() = default;

    virtual void hit(int& score);
    bool isDestroyed() const;
    const sf::RectangleShape& getShape() const;
    virtual void draw(sf::RenderWindow& window);
};