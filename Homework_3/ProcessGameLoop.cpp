#include "ProcessGameLoop.h"
#include "CheckMatches.h"
#include "ApplyBonusesAndDestroy.h"
#include "DropTiles.h"

void processGameLoop(Board& board, std::mt19937& g) {
    bool process = true;
    while (process) {
        dropTiles(board);
        if (checkMatches(board)) {
            applyBonusesAndDestroy(board, g);
            process = true;
        }
        else {
            process = false;
        }
    }
}