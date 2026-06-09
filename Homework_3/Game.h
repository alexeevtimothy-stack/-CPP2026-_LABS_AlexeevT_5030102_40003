#pragma once
#include "Common.h"
#include "Square.h"
#include <random>

class Game {
private:
    sf::RenderWindow window;
    Board board;
    std::mt19937 g;

    sf::Vector2i selectedTile;
    bool isTileSelected;

    sf::RectangleShape tileShape;

    void initWindow();
    void initGameBoard();
    void processEvents();
    void handleMouseClick(int mouseX, int mouseY);
    void render();

public:
    Game();
    ~Game() = default;
    void run();
};