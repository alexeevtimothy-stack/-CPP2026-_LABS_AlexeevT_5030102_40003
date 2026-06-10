#pragma once
#include "Bonus.h"

class BonusTwoBalls : public Bonus {
public:
    BonusTwoBalls(float x, float y);
    void apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) override;
};