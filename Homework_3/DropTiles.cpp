#include "DropTiles.h"
#include "Square.h"

void dropTiles(Board& board) {
    for (int c = 0; c < BOARD_WIDTH; ++c) {
        int emptyRow = BOARD_HEIGHT - 1;
        for (int r = BOARD_HEIGHT - 1; r >= 0; --r) {
            if (board[r][c]) {
                if (r != emptyRow) {
                    board[emptyRow][c] = std::move(board[r][c]);
                }
                emptyRow--;
            }
        }
        for (int r = emptyRow; r >= 0; --r) {
            board[r][c] = std::make_unique<Square>(std::rand() % NUM_COLORS);
        }
    }
}