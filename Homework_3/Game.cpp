#include "Game.h"
#include "InitBoard.h"
#include "CheckMatches.h"
#include "ApplyBonusesAndDestroy.h"
#include "ProcessGameLoop.h"
#include "Square.h"
#include <cmath>

Game::Game() : selectedTile(-1, -1), isTileSelected(false) {
    std::random_device rd;
    g.seed(rd());
    tileShape.setSize(sf::Vector2f(TILE_SIZE - 4.f, TILE_SIZE - 4.f));
    initWindow();
    initGameBoard();
}

void Game::initWindow() {
    window.create(sf::VideoMode({ BOARD_WIDTH * static_cast<unsigned int>(TILE_SIZE),
                                 BOARD_HEIGHT * static_cast<unsigned int>(TILE_SIZE) }),
        "GEMS");
    window.setFramerateLimit(60);
}

void Game::initGameBoard() {
    board.resize(BOARD_HEIGHT);
    for (int r = 0; r < BOARD_HEIGHT; ++r) {
        board[r].resize(BOARD_WIDTH);
    }
    initBoard(board);
}

void Game::handleMouseClick(int mouseX, int mouseY) {
    int c = mouseX / static_cast<int>(TILE_SIZE);
    int r = mouseY / static_cast<int>(TILE_SIZE);

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

void Game::processEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) {
            window.close();
        }
        else if (const auto* mouseButtonEvent = event->getIf<sf::Event::MouseButtonPressed>()) {
            if (mouseButtonEvent->button == sf::Mouse::Button::Left) {
                handleMouseClick(mouseButtonEvent->position.x, mouseButtonEvent->position.y);
            }
        }
    }
}

void Game::render() {
    window.clear(sf::Color(30, 30, 30)); 

    for (int r = 0; r < BOARD_HEIGHT; ++r) {
        for (int c = 0; c < BOARD_WIDTH; ++c) {
            if (board[r][c]) {
                tileShape.setFillColor(board[r][c]->getColor());
                tileShape.setPosition({ c * TILE_SIZE + 2.f, r * TILE_SIZE + 2.f });

                if (isTileSelected && selectedTile.x == c && selectedTile.y == r) {
                    tileShape.setOutlineColor(sf::Color::White);
                    tileShape.setOutlineThickness(3.f);
                }
                else {
                    tileShape.setOutlineThickness(0.f);
                }

                window.draw(tileShape);
            }
        }
    }
    window.display();
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        render();
    }
}