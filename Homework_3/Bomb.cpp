#include "Bomb.h"
#include "GetNeighbor.h"
#include <iostream>
Bomb::Bomb(int color) : Square(color) {}

sf::Color Bomb::getColor() const {
    return sf::Color::White;
}

void Bomb::onDestroy(Board& board, int c, int r, std::mt19937& g) {
    auto neighborhood = getNeighborhood(c, r);
    if (neighborhood.empty()) return;

    sf::Vector2i target = neighborhood[std::rand() % neighborhood.size()];
    if (board[target.y][target.x]) board[target.y][target.x]->isMatched = true;

    std::vector<sf::Vector2i> allTiles;
    for (int row = 0; row < BOARD_HEIGHT; ++row) {
        for (int col = 0; col < BOARD_WIDTH; ++col) {
            if (row != target.y || col != target.x) allTiles.push_back({ col, row });
        }
    }

    std::shuffle(allTiles.begin(), allTiles.end(), g);
    int toDestroy = std::min(4, static_cast<int>(allTiles.size()));
    for (int i = 0; i < toDestroy; ++i) {
        if (board[allTiles[i].y][allTiles[i].x]) {
            board[allTiles[i].y][allTiles[i].x]->isMatched = true;
        }
    }
    std::cout <<"Взорвалась Бомба!\n";
}

std::unique_ptr<Square> Bomb::clone() const {
    return std::make_unique<Bomb>(colorId);
}