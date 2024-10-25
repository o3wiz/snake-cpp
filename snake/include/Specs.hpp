#pragma once

#include "raylib.h"

namespace snake::specs {

constexpr int cellWidth = 25;
constexpr int cellHeight = 25;
constexpr int cellsPerRow = 30;
constexpr int cellsPerColumn = 30;
constexpr int windowWidth = cellWidth * cellsPerRow;
constexpr int windowHeight = cellHeight * cellsPerColumn;
constexpr auto windowTitle = "Snake";
constexpr int gameFPS = 60;
constexpr Color backgroundColor{0xdf, 0xff, 0x94, 0xff};
constexpr Color snakeColor{0x40, 0x5c, 0x00, 0xff};
constexpr Color appleColor{0xff, 0x48, 0x24, 0xff};

}  // namespace snake::specs
