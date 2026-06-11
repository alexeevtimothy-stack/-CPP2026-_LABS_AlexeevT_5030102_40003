#pragma once
#include "Block.h"
class Ball;

class SpeedUpBlock : public Block {
public:
    SpeedUpBlock(float x, float y);
    void hitWithBall(int& score, Ball& ball);
};
