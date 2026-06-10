#include "BonusBlock.h"
#include "BonusPadleSizeUp.h"
#include "BonusBallSpeedUp.h"
#include "BonusOneTimeBottom.h"
#include "BonusTwoBalls.h"
#include "BonusStickyPadle.h"

BonusBlock::BonusBlock(float x, float y) : Block(x, y, 3, sf::Color::Green) {}
void BonusBlock::hit(int& score) { Block::hit(score); }

void BonusBlock::spawnBonus(std::vector<std::unique_ptr<Bonus>>& bonuses, std::mt19937& g) {
    float bx = shape.getPosition().x + BLOCK_WIDTH / 2.0f;
    float by = shape.getPosition().y + BLOCK_HEIGHT;

    std::uniform_int_distribution<int> dist(0, 4);
    int roll = dist(g);

    if (roll == 0) bonuses.push_back(std::make_unique<BonusPaddleSizeUp>(bx, by));
    else if (roll == 1) bonuses.push_back(std::make_unique<BonusBallSpeedUp>(bx, by));
    else if (roll == 2) bonuses.push_back(std::make_unique<BonusOneTimeBottom>(bx, by));
    else if (roll == 3) bonuses.push_back(std::make_unique<BonusTwoBalls>(bx, by));
    else if (roll == 4) bonuses.push_back(std::make_unique<BonusStickyPaddle>(bx, by));
}