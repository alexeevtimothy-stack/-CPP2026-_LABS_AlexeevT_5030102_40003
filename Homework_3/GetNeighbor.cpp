#include "GetNeighbor.h"

std::vector<sf::Vector2i> getNeighborhood(int originC, int originR) {
    std::vector<sf::Vector2i> neighborhood;
    for (int dr = -3; dr <= 3; ++dr) {
        for (int dc = -3; dc <= 3; ++dc) {
            int nr = originR + dr;
            int nc = originC + dc;
            if (nr >= 0 && nr < BOARD_HEIGHT && nc >= 0 && nc < BOARD_WIDTH) {
                neighborhood.push_back({ nc, nr });
            }
        }
    }
    return neighborhood;
}