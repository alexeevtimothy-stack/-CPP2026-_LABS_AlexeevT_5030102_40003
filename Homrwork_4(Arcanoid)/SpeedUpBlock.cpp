#include "SpeedUpBlock.h"
#include "Ball.h"

SpeedUpBlock::SpeedUpBlock(float x, float y) : Block(x, y, 3, sf::Color::Yellow) {}

void SpeedUpBlock::hitWithBall(int& score, Ball& ball) {
    Block::hit(score);
    if (isDestroyed()) {
        ball.changeSpeed(1.2f);
    }
}