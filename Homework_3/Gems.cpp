#include "Game.h"
#include <windows.h>
#include <clocale>


int main() {
    SetConsoleCP(65001); SetConsoleOutputCP(65001);
    std::setlocale(LC_ALL, ".UTF-8");
    Game game;
    game.run();
    return 0;
}