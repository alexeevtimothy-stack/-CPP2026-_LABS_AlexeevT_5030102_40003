#include "ApplyBonusesAndDestroy.h"
#include "Bomb.h"
#include "Painter.h"

void applyBonusesAndDestroy(Board& board, std::mt19937& g) {
    struct NewBonus { int c, r, color; bool isBomb; };
    std::vector<NewBonus> bonusesToSpawn;

    for (int r = 0; r < BOARD_HEIGHT; ++r) {
        for (int c = 0; c < BOARD_WIDTH; ++c) {
            if (board[r][c] && board[r][c]->isMatched) {

                board[r][c]->onDestroy(board, c, r, g);

                if (dynamic_cast<Bomb*>(board[r][c].get()) == nullptr &&
                    dynamic_cast<Painter*>(board[r][c].get()) == nullptr) {

                    if (std::rand() % 100 < BONUS_DROP_CHANCE) {
                        bool makeBomb = (std::rand() % 100 < BOMB_PROBABILITY);
                        bonusesToSpawn.push_back({ c, r, board[r][c]->colorId, makeBomb });
                    }
                }
                board[r][c].reset();
            }
        }
    }
    for (const auto& b : bonusesToSpawn) {
        if (b.isBomb) {
            board[b.r][b.c] = std::make_unique<Bomb>(b.color);
        }
        else {
            board[b.r][b.c] = std::make_unique<Painter>(b.color);
        }
    }
}