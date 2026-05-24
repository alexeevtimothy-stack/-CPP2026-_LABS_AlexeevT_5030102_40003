#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <memory>
#include <algorithm>
#include <random>
#include <cmath>
#include <cstdlib>
#include <ctime>

const int BOARD_WIDTH = 8;
const int BOARD_HEIGHT = 8;

const float TILE_SIZE = 60.f;

const int NUM_COLORS = 5;

const int BONUS_DROP_CHANCE = 5;
const int BOMB_PROBABILITY = 50;

const sf::Color Colors[] = {sf::Color::Red, sf::Color::Blue, sf::Color::Green, sf::Color::Yellow, sf::Color::Magenta};

class Square;

using Board = std::vector<std::vector<std::unique_ptr<Square>>>;