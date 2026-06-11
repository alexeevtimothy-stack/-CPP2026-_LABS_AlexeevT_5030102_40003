#pragma once
#include "Bonus.h"

class BonusStickyPaddle : public Bonus {
public:
    BonusStickyPaddle(float x, float y);
    void apply(Paddle& paddle, std::vector<std::unique_ptr<Ball>>& balls, bool& hasOneTimeBottom) override;
};