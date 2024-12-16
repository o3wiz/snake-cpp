#pragma once

#include <chrono>
#include <filesystem>

#include "raylib.h"

namespace snake::specs
{

constexpr int cellSize = 64;
constexpr int cellsPerRow = 12;
constexpr int cellsPerColumn = 12;
constexpr int windowWidth = cellSize * cellsPerRow;
constexpr int windowHeight = cellSize * cellsPerColumn;
constexpr auto windowTitle = "Snake";
constexpr int gameFPS = 60;
constexpr Color backgroundColor{0xdf, 0xff, 0x94, 0xff};
constexpr Color snakeHeadColor{0x64, 0x8f, 0x00, 0xff};
constexpr Color snakeColor{0x40, 0x5c, 0x00, 0xff};
constexpr Color snakeTailColor{0x2b, 0x3d, 0x00, 0xff};
constexpr Color appleColor{0xff, 0x48, 0x24, 0xff};
constexpr int initialSnakeBodyLength = 3;
constexpr std::chrono::milliseconds snakeMoveRate{90};
constexpr int scoreFontSize = 42;
constexpr Color scoreColor = DARKGRAY;
inline const std::filesystem::path resourcesDir = SNAKE_RESOURCES;
inline const std::filesystem::path soundsDir = resourcesDir / "sounds";
inline const std::filesystem::path snakeEatSound = soundsDir / "snake_eat.wav";
inline const std::filesystem::path snakeSelfCollision = soundsDir / "snake_self_collision.wav";
inline const std::filesystem::path snakeWallCollision = soundsDir / "snake_wall_collision.wav";

} // namespace snake::specs
