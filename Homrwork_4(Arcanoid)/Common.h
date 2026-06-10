#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <random>

constexpr unsigned int WINDOW_WIDTH = 800;
constexpr unsigned int WINDOW_HEIGHT = 600;

constexpr float PADDLE_START_WIDTH = 120.0f;
constexpr float PADDLE_HEIGHT = 20.0f;
constexpr float PADDLE_SPEED = 500.0f;

constexpr float BALL_RADIUS = 8.0f;
constexpr float BALL_START_SPEED = 300.0f;

constexpr int BLOCK_ROWS = 5;
constexpr int BLOCK_COLS = 10;
constexpr float BLOCK_WIDTH = 76.0f;
constexpr float BLOCK_HEIGHT = 25.0f;
constexpr float BLOCK_MARGIN = 4.0f;
constexpr float BLOCK_TOP_OFFSET = 60.0f;

constexpr float BONUS_RADIUS = 10.0f;
constexpr float BONUS_SPEED = 150.0f;