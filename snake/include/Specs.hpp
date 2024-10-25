#pragma once

#include <chrono>

#include "raylib.h"

namespace snake::specs {

constexpr int cellSize = 64;
constexpr int cellsPerRow = 12;
constexpr int cellsPerColumn = 12;
constexpr int windowWidth = cellSize * cellsPerRow;
constexpr int windowHeight = cellSize * cellsPerColumn;
constexpr auto windowTitle = "Snake";
constexpr int gameFPS = 60;
constexpr Color backgroundColor{0xdf, 0xff, 0x94, 0xff};
constexpr Color snakeColor{0x40, 0x5c, 0x00, 0xff};
constexpr Color appleColor{0xff, 0x48, 0x24, 0xff};
constexpr int initialSnakeBodyLength = 3;
constexpr std::chrono::milliseconds snakeMoveRate{200};

}  // namespace snake::specs
