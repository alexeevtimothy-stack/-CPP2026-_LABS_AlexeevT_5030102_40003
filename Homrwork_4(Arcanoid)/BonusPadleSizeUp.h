#pragma once
#include "Bonus.h"

class BonusPaddleSizeUp : public Bonus {
public:
    BonusPaddleSizeUp(float x, float y);
    void apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) override;
};