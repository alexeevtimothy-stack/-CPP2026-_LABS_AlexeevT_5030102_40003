#pragma once
#include "Common.h"

class Paddle {
private:
    sf::RectangleShape shape;
    float width;
    bool isSticky;

public:
    Paddle();
    void reset();
    void processInput();
    void changeSize(float factor);

    void setSticky(bool sticky);
    bool getIsSticky() const;

    const sf::RectangleShape& getShape() const;
    void draw(sf::RenderWindow& window);
};
