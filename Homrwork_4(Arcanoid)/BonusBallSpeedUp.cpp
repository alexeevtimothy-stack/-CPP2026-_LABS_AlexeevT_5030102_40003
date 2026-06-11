#include "BonusBallSpeedUp.h"
#include "Ball.h"

BonusBallSpeedUp::BonusBallSpeedUp(float x, float y) : Bonus(x, y, sf::Color::Yellow) {}
void BonusBallSpeedUp::apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) {
    for (auto& ball : balls) ball->changeSpeed(1.2f);
}