#include "BonusStickyPadle.h"
#include "Padle.h"

BonusStickyPaddle::BonusStickyPaddle(float x, float y) : Bonus(x, y, sf::Color::Magenta) {}
void BonusStickyPaddle::apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) {
    paddle.setSticky(true);
}