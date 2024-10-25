#pragma once

namespace snake::specs {

constexpr int cellWidth = 25;
constexpr int cellHeight = 25;
constexpr int cellsPerRow = 30;
constexpr int cellsPerColumn = 30;
constexpr int windowWidth = cellWidth * cellsPerRow;
constexpr int windowHeight = cellHeight * cellsPerColumn;
constexpr auto windowTitle = "Snake";

}  // namespace snake::specs
