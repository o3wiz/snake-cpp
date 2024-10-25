#include "Snake.hpp"

#include "Specs.hpp"

using namespace snake;

Snake::Snake(const Vector2& initialHeadPosition) : _body{initialHeadPosition} {}

Collision Snake::Move(const Direction newDirection,
                      const Vector2& foodPosition) {
  return Collision::None;
}

void Snake::Draw() const {
  static constexpr float BODY_PART_ROUNDNESS{.5F};
  static constexpr int BODY_PART_SEGMENTS{6};
  for (const auto& [x, y] : _body) {
    const Rectangle snakeBodyPart{
        .x = x * specs::cellSize,
        .y = y * specs::cellSize,
        .width = specs::cellSize,
        .height = specs::cellSize,
    };
    DrawRectangleRounded(std::move(snakeBodyPart), BODY_PART_ROUNDNESS,
                         BODY_PART_SEGMENTS, specs::snakeColor);
  }
}
