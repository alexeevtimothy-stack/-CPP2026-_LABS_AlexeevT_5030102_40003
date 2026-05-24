#include "Painter.h"
#include "GetNeighbor.h"
#include <iostream>
Painter::Painter(int color) : Square(color) {}

sf::Color Painter::getColor() const {
    return sf::Color::Cyan;
}

void Painter::onDestroy(Board& board, int c, int r, std::mt19937& g) {
    auto neighborhood = getNeighborhood(c, r);
    if (neighborhood.empty()) return;

    sf::Vector2i target = neighborhood[std::rand() % neighborhood.size()];
    if (board[target.y][target.x]) board[target.y][target.x]->colorId = this->colorId;

    std::vector<sf::Vector2i> nonNeighbors;
    for (const auto& pos : neighborhood) {
        if (std::abs(pos.x - target.x) > 1 || std::abs(pos.y - target.y) > 1) {
            nonNeighbors.push_back(pos);
        }
    }

    std::shuffle(nonNeighbors.begin(), nonNeighbors.end(), g);
    int changes = std::min(2, static_cast<int>(nonNeighbors.size()));
    for (int i = 0; i < changes; ++i) {
        if (board[nonNeighbors[i].y][nonNeighbors[i].x]) {
            board[nonNeighbors[i].y][nonNeighbors[i].x]->colorId = this->colorId;
        }
    }
    std::cout << "Перекрашивание окрестности!\n";
}

std::unique_ptr<Square> Painter::clone() const {
    return std::make_unique<Painter>(colorId);
}