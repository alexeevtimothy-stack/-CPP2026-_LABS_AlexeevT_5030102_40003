#include "Bomb.h"
#include "GetNeighbor.h"
#include <iostream>
#include <algorithm>

Bomb::Bomb(int color) : Square(color) {}

sf::Color Bomb::getColor() const {
    return sf::Color::White;
}

void Bomb::onDestroy(Board& board, int c, int r, std::mt19937& g) {
    auto neighborhood = getNeighborhood(c, r);
    std::vector<sf::Vector2i> validNeighbors;
    for (const auto& pos : neighborhood) {
        if (board[pos.y][pos.x]) {
            validNeighbors.push_back(pos);
        }
    }

    sf::Vector2i target = { -1, -1 };
    if (!validNeighbors.empty()) {
        std::uniform_int_distribution<size_t> dist(0, validNeighbors.size() - 1);
        target = validNeighbors[dist(g)];
        board[target.y][target.x]->setMatched(true);
    }
    std::vector<sf::Vector2i> allTiles;
    for (int row = 0; row < BOARD_HEIGHT; ++row) {
        for (int col = 0; col < BOARD_WIDTH; ++col) {
            if (row == r && col == c) continue; 
            if (target.x != -1 && row == target.y && col == target.x) continue;

            if (board[row][col]) {
                allTiles.push_back({ col, row });
            }
        }
    }
    std::shuffle(allTiles.begin(), allTiles.end(), g);
    int toDestroy = std::min(4, static_cast<int>(allTiles.size()));
    for (int i = 0; i < toDestroy; ++i) {
        board[allTiles[i].y][allTiles[i].x]->setMatched(true);
    }

    std::cout << "Взорвалась Бомба!\n";
}

std::unique_ptr<Square> Bomb::clone() const {
    return std::make_unique<Bomb>(getColorId());
}