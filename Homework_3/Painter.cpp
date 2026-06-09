#include "Painter.h"
#include "GetNeighbor.h" 
#include <iostream>
#include <algorithm>

Painter::Painter(int color) : Square(color) {}

sf::Color Painter::getColor() const {
    return sf::Color::Cyan;
}

void Painter::onDestroy(Board& board, int c, int r, std::mt19937& g) {
    auto neighborhood = getNeighborhood(c, r);
    std::vector<sf::Vector2i> validNeighbors;
    for (const auto& pos : neighborhood) {
        if (board[pos.y][pos.x]) {
            validNeighbors.push_back(pos);
        }
    }

    if (validNeighbors.empty()) return;
    std::uniform_int_distribution<size_t> dist(0, validNeighbors.size() - 1);
    size_t targetIndex = dist(g);
    sf::Vector2i target = validNeighbors[targetIndex];

    board[target.y][target.x]->setColorId(this->getColorId());

    std::vector<sf::Vector2i> otherNeighbors;
    for (const auto& pos : validNeighbors) {
        if (pos.x != target.x || pos.y != target.y) {
            otherNeighbors.push_back(pos);
        }
    }

    std::shuffle(otherNeighbors.begin(), otherNeighbors.end(), g);
    int changes = std::min(2, static_cast<int>(otherNeighbors.size()));
    for (int i = 0; i < changes; ++i) {
        board[otherNeighbors[i].y][otherNeighbors[i].x]->setColorId(this->getColorId());
    }

    std::cout << "Перекрашивание окрестности!\n";
}

std::unique_ptr<Square> Painter::clone() const {
    return std::make_unique<Painter>(getColorId());
}