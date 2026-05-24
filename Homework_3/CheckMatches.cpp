#include "CheckMatches.h"
#include "Square.h"

bool checkMatches(Board& board) {
    bool hasMatches = false;
    for (int r = 0; r < BOARD_HEIGHT; ++r) {
        for (int c = 0; c < BOARD_WIDTH - 2; ++c) {
            if (!board[r][c] || !board[r][c + 1] || !board[r][c + 2]) continue;
            int color = board[r][c]->colorId;
            if (color != -1 && board[r][c + 1]->colorId == color && board[r][c + 2]->colorId == color) {
                board[r][c]->isMatched = board[r][c + 1]->isMatched = board[r][c + 2]->isMatched = true;
                hasMatches = true;
            }
        }
    }
    for (int c = 0; c < BOARD_WIDTH; ++c) {
        for (int r = 0; r < BOARD_HEIGHT - 2; ++r) {
            if (!board[r][c] || !board[r + 1][c] || !board[r + 2][c]) continue;
            int color = board[r][c]->colorId;
            if (color != -1 && board[r + 1][c]->colorId == color && board[r + 2][c]->colorId == color) {
                board[r][c]->isMatched = board[r + 1][c]->isMatched = board[r + 2][c]->isMatched = true;
                hasMatches = true;
            }
        }
    }
    return hasMatches;
}