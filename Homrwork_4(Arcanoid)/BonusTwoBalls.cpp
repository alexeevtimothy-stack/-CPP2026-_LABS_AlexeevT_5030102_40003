#include "BonusTwoBalls.h"
#include "Ball.h"

BonusTwoBalls::BonusTwoBalls(float x, float y) : Bonus(x, y, sf::Color::Cyan) {}

void BonusTwoBalls::apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) {
    if (!balls.empty()) {
        auto newBall = std::make_unique<Ball>();

        newBall->setPosition(balls[0]->getPosition());

        newBall->setStuck(false);

        newBall->bounceVelocityX();

        balls.push_back(std::move(newBall));
    }
}