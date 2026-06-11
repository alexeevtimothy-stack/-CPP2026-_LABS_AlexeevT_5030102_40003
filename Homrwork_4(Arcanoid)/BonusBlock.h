#pragma once
#include "Block.h"

class BonusBlock : public Block {
public:
    BonusBlock(float x, float y);
    void hit(int& score) override;
    void spawnBonus(std::vector<std::unique_ptr<class Bonus>>& bonuses, std::mt19937& g);
};