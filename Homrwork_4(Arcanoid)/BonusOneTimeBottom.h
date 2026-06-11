#pragma once
#include "Bonus.h"

class BonusOneTimeBottom : public Bonus {
public:
    BonusOneTimeBottom(float x, float y);
    void apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) override;
};