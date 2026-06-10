#pragma once
#include "Bonus.h"

class BonusBallSpeedUp : public Bonus {
public:
    BonusBallSpeedUp(float x, float y);
    void apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) override;
};