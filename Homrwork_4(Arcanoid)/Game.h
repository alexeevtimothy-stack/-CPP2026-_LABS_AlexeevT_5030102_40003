#pragma once
#include "Common.h"
#include "Padle.h"
#include "Ball.h"
#include "Block.h"
#include "Bonus.h"

class Game {
private:
    sf::RenderWindow window;
    Paddle paddle;
    std::vector<std::unique_ptr<Ball>> balls;
    std::vector<std::unique_ptr<Block>> blocks;
    std::vector<std::unique_ptr<Bonus>> bonuses;
    std::mt19937 g;

    int score;
    int lives;
    bool hasOneTimeBottom;
    sf::RectangleShape bottomLineVisual;

    sf::Font font;
    sf::Text uiText;

    void initWindow();
    void generateBlocks();
    void processEvents();
    void update(float deltaTime);
    void checkCollisions();
    void render();
    void updateUI(); 

public:
    Game();
    ~Game();
    void run();
};