#include "BonusOneTimeBottom.h"

BonusOneTimeBottom::BonusOneTimeBottom(float x, float y) : Bonus(x, y, sf::Color::Blue) {}
void BonusOneTimeBottom::apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) {
    hasOneTimeBottom = true;
}