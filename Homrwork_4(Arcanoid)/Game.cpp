#include "Game.h"
#include "IndestructableBlock.h"
#include "SpeedUpBlock.h"
#include "BonusBlock.h"
#include <sstream>

Game::Game() : score(0), lives(50), hasOneTimeBottom(false), uiText(font) {
    std::random_device rd;
    g.seed(rd());
    initWindow();

    if (!font.openFromFile("Arial.ttf")) {
        auto status = font.openFromFile("C:/Windows/Fonts/arial.ttf");
        (void)status;
    }

    uiText.setCharacterSize(20);
    uiText.setFillColor(sf::Color::White);
    uiText.setPosition({ 15.0f, 15.0f });
    updateUI();

    generateBlocks();

    auto firstBall = std::make_unique<Ball>();
    firstBall->reset(paddle.getShape().getPosition(), paddle.getShape().getSize().x);
    balls.push_back(std::move(firstBall));

    bottomLineVisual.setSize({ static_cast<float>(WINDOW_WIDTH), 6.0f });
    bottomLineVisual.setPosition({ 0.0f, WINDOW_HEIGHT - 8.0f });
    bottomLineVisual.setFillColor(sf::Color::Blue);
}

Game::~Game() = default;

void Game::initWindow() {
    window.create(sf::VideoMode({ WINDOW_WIDTH, WINDOW_HEIGHT }), "Arkanoid");
    window.setFramerateLimit(60);
}

void Game::generateBlocks() {
    std::uniform_int_distribution<int> typeDist(0, 3);
    for (int r = 0; r < BLOCK_ROWS; ++r) {
        for (int c = 0; c < BLOCK_COLS; ++c) {
            float x = c * (BLOCK_WIDTH + BLOCK_MARGIN) + 10.0f;
            float y = r * (BLOCK_HEIGHT + BLOCK_MARGIN) + BLOCK_TOP_OFFSET;

            int roll = typeDist(g);
            if (roll == 0) {
                blocks.push_back(std::make_unique<IndestructibleBlock>(x, y));
            }
            else if (roll == 1) {
                blocks.push_back(std::make_unique<SpeedUpBlock>(x, y));
            }
            else if (roll == 2) {
                blocks.push_back(std::make_unique<BonusBlock>(x, y));
            }
            else {
                blocks.push_back(std::make_unique<Block>(x, y, 3, sf::Color::Cyan));
            }
        }
    }
}

void Game::updateUI() {
    std::stringstream ss;
    ss << "SCORE: " << score << "   LIVES: " << lives;
    uiText.setString(ss.str());
}

void Game::checkCollisions() {
    for (auto ballIt = balls.begin(); ballIt != balls.end();) {
        Ball& ball = **ballIt;
        bool ballRemoved = false;

        if (ball.getShape().getGlobalBounds().findIntersection(paddle.getShape().getGlobalBounds())) {
            ball.bounceVelocityY();
            if (paddle.getIsSticky()) ball.setStuck(true);
        }

        for (auto& block : blocks) {
            if (!block->isDestroyed() && ball.getShape().getGlobalBounds().findIntersection(block->getShape().getGlobalBounds())) {
                ball.bounceVelocityY();

                if (auto* speedUpBlk = dynamic_cast<SpeedUpBlock*>(block.get())) {
                    speedUpBlk->hitWithBall(score, ball);
                }
                else if (auto* bonusBlk = dynamic_cast<BonusBlock*>(block.get())) {
                    bonusBlk->hit(score);
                    if (bonusBlk->isDestroyed()) bonusBlk->spawnBonus(bonuses, g);
                }
                else {
                    block->hit(score);
                }

                updateUI(); 
                break;
            }
        }

        if (ball.getPosition().y + BALL_RADIUS * 2.0f >= WINDOW_HEIGHT) {
            if (hasOneTimeBottom) {
                ball.bounceVelocityY();
                hasOneTimeBottom = false;
                updateUI();
            }
            else {
                if (balls.size() > 1) {
                    ballIt = balls.erase(ballIt);
                    ballRemoved = true;
                }
                else {
                    lives--; 
                    updateUI();
                    paddle.reset();
                    balls[0]->reset(paddle.getShape().getPosition(), paddle.getShape().getSize().x);
                    bonuses.clear();
                    if (lives <= 0) window.close();
                    return;
                }
            }
        }
        if (!ballRemoved) ++ballIt;
    }

    for (auto it = bonuses.begin(); it != bonuses.end();) {
        if ((*it)->getShape().getGlobalBounds().findIntersection(paddle.getShape().getGlobalBounds())) {
            (*it)->apply(paddle, balls, hasOneTimeBottom);
            updateUI();
            it = bonuses.erase(it);
        }
        else if ((*it)->isOutOfBounds()) {
            it = bonuses.erase(it);
        }
        else {
            ++it;
        }
    }
}

void Game::processEvents() {
    while (const std::optional<sf::Event> event = window.pollEvent()) {
        if (event->is<sf::Event::Closed>()) window.close();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
            for (auto& ball : balls) if (ball->isStuck()) ball->setStuck(false);
        }
    }
}

void Game::update(float deltaTime) {
    paddle.processInput();
    for (auto& ball : balls) {
        if (ball->isStuck()) ball->reset(paddle.getShape().getPosition(), paddle.getShape().getSize().x);
        else ball->update(deltaTime);
    }
    for (auto& bonus : bonuses) bonus->update(deltaTime);
    checkCollisions();
}

void Game::render() {
    window.clear(sf::Color(20, 20, 20));

    paddle.draw(window);
    for (auto& ball : balls) ball->draw(window);
    for (const auto& block : blocks) if (!block->isDestroyed()) block->draw(window);
    for (auto& bonus : bonuses) bonus->draw(window);
    if (hasOneTimeBottom) window.draw(bottomLineVisual);

    window.draw(uiText);

    window.display();
}

void Game::run() {
    sf::Clock clock;
    while (window.isOpen()) {
        float deltaTime = clock.restart().asSeconds();
        processEvents();
        update(deltaTime);
        render();
    }
}