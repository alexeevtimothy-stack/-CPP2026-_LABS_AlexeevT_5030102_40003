#include "InitBoard.h"
#include "Square.h"
#include "CheckMatches.h"

void initBoard(Board& board) {
    do {
        for (int r = 0; r < BOARD_HEIGHT; ++r) {
            for (int c = 0; c < BOARD_WIDTH; ++c) {
                board[r][c] = std::make_unique<Square>(std::rand() % NUM_COLORS);
            }
        }
    } while (checkMatches(board));
}