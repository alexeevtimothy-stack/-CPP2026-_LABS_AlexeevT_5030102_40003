#include "CheckMatches.h"
#include "Square.h"
#include <queue>

bool checkMatches(Board& board) {
    bool hasMatches = false;
    std::vector<std::vector<bool>> visited(BOARD_HEIGHT, std::vector<bool>(BOARD_WIDTH, false));
    int dr[] = { -1, 1, 0, 0 };
    int dc[] = { 0, 0, -1, 1 };

    for (int r = 0; r < BOARD_HEIGHT; ++r) {
        for (int c = 0; c < BOARD_WIDTH; ++c) {
            if (visited[r][c] || !board[r][c] || board[r][c]->getColorId() == -1) continue;

            int targetColor = board[r][c]->getColorId();
            std::vector<sf::Vector2i> component;
            std::queue<sf::Vector2i> q;
            q.push({ c, r });
            visited[r][c] = true;

            while (!q.empty()) {
                sf::Vector2i curr = q.front();
                q.pop();
                component.push_back(curr);

                for (int i = 0; i < 4; ++i) {
                    int nr = curr.y + dr[i];
                    int nc = curr.x + dc[i];

                    if (nr >= 0 && nr < BOARD_HEIGHT && nc >= 0 && nc < BOARD_WIDTH) {
                        if (!visited[nr][nc] && board[nr][nc] && board[nr][nc]->getColorId() == targetColor) {
                            visited[nr][nc] = true;
                            q.push({ nc, nr });
                        }
                    }
                }
            }
            if (component.size() >= 3) {
                for (const auto& pos : component) {
                    board[pos.y][pos.x]->setMatched(true);
                }
                hasMatches = true;
            }
        }
    }
    return hasMatches;
}