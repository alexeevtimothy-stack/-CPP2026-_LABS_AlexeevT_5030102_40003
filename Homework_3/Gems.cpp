#include "Common.h"
#include "Square.h"
#include "InitBoard.h"
#include "CheckMatches.h"
#include "ApplyBonusesAndDestroy.h"
#include "ProcessGameLoop.h"
#include <windows.h>
#include <clocale>

int main() {
    SetConsoleCP(65001); SetConsoleOutputCP(65001);
    std::setlocale(LC_ALL, ".UTF-8");

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    std::random_device rd;
    std::mt19937 g(rd());

    sf::RenderWindow window(sf::VideoMode({ BOARD_WIDTH * static_cast<unsigned int>(TILE_SIZE),BOARD_HEIGHT * static_cast<unsigned int>(TILE_SIZE) }),"GEMS Game");
    window.setFramerateLimit(60);

    Board board(BOARD_HEIGHT);
    for (int r = 0; r < BOARD_HEIGHT; ++r) {
        board[r].resize(BOARD_WIDTH);
    }
    initBoard(board);

    sf::Vector2i selectedTile(-1, -1);
    bool isTileSelected = false;

    while (window.isOpen()) {
        while (const std::optional<sf::Event> event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>()) {
                window.close();
            }
            else if (const auto* mouseButtonEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
                if (mouseButtonEvent->button == sf::Mouse::Button::Left) {

                    int c = mouseButtonEvent->position.x / static_cast<int>(TILE_SIZE);
                    int r = mouseButtonEvent->position.y / static_cast<int>(TILE_SIZE);

                    if (c >= 0 && c < BOARD_WIDTH && r >= 0 && r < BOARD_HEIGHT) {
                        if (!isTileSelected) {
                            selectedTile = { c, r };
                            isTileSelected = true;
                        }
                        else {
                            if ((std::abs(selectedTile.x - c) == 1 && selectedTile.y == r) ||
                                (std::abs(selectedTile.y - r) == 1 && selectedTile.x == c)) {

                                std::swap(board[selectedTile.y][selectedTile.x], board[r][c]);

                                if (!checkMatches(board)) {
                                    std::swap(board[selectedTile.y][selectedTile.x], board[r][c]);
                                }
                                else {
                                    applyBonusesAndDestroy(board, g);
                                    processGameLoop(board, g);
                                }
                            }
                            isTileSelected = false;
                        }
                    }
                }
            }
        }
        window.clear(sf::Color(30, 30, 30));
        sf::RectangleShape shape(sf::Vector2f(TILE_SIZE - 4.f, TILE_SIZE - 4.f));

        for (int r = 0; r < BOARD_HEIGHT; ++r) {
            for (int c = 0; c < BOARD_WIDTH; ++c) {
                if (board[r][c]) {
                    shape.setFillColor(board[r][c]->getColor());
                    shape.setPosition({ c * TILE_SIZE + 2.f, r * TILE_SIZE + 2.f });

                    if (isTileSelected && selectedTile.x == c && selectedTile.y == r) {
                        shape.setOutlineColor(sf::Color::White);
                        shape.setOutlineThickness(3.f);
                    }
                    else {
                        shape.setOutlineThickness(0.f);
                    }
                    window.draw(shape);
                }
            }
        }
        window.display();
    }
    return 0;
}