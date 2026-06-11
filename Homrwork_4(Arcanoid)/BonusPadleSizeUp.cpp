#include "BonusPadleSizeUp.h"
#include "Padle.h"

BonusPaddleSizeUp::BonusPaddleSizeUp(float x, float y) : Bonus(x, y, sf::Color::Green) {}
void BonusPaddleSizeUp::apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) {
    paddle.changeSize(1.3f);
}