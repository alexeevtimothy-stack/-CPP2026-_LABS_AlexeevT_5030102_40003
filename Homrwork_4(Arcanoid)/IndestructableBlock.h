#pragma once
#include "Block.h"

class IndestructibleBlock : public Block {
public:
    IndestructibleBlock(float x, float y);
    void hit(int& score) override;
};