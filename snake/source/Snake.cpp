#include "Snake.hpp"

#include <algorithm>
#include <iterator>
#include <unordered_map>

#include "Specs.hpp"
#include "Utils.hpp"
#include "raylib.h"
#include "raymath.h"

using namespace snake;

static bool isPerpDirections(const Direction dirA, const Direction dirB) {
  return ((dirA == Direction::Up || dirA == Direction::Down) &&
          (dirB == Direction::Right || dirB == Direction::Left)) ||
         ((dirB == Direction::Up || dirB == Direction::Down) &&
          (dirA == Direction::Right || dirA == Direction::Left));
}

Snake::Snake(const Vector2& initialHeadPosition) {
  for (int i = 0; i < specs::initialSnakeBodyLength; ++i) {
    const Vector2 bodyPart = Vector2Add(initialHeadPosition, Vector2(i, 0));
    _body.emplace_back(std::move(bodyPart));
  }
}

Collision Snake::Move(const Direction newDirection,
                      const Vector2& applePosition) {
  if (newDirection == Direction::None) return Collision::None;
  if (!this->hasDirection() && newDirection == Direction::Left)
    return Collision::None;  // ignore invalid snake movement
  const Vector2 moveVec = this->getDirectionVector(newDirection);
  if (!this->hasDirection() || isPerpDirections(newDirection, _headDirection))
    _headDirection = newDirection;
  const Vector2 newHeadPosition = Vector2Add(this->getHeadPosition(), moveVec);
  _body.emplace_back(std::move(newHeadPosition));
  const Collision coll = this->detectCollision(applePosition);
  if (coll != Collision::Apple) this->removeTail();
  return coll;
}

Vector2 Snake::getDirectionVector(const Direction direction) {
  static const std::unordered_map<Direction, Vector2> DIRECTION_TO_VEC2{
      {Direction::None, Vector2{0, 0}},  {Direction::Up, Vector2{0, -1}},
      {Direction::Right, Vector2{1, 0}}, {Direction::Down, Vector2{0, 1}},
      {Direction::Left, Vector2{-1, 0}},
  };
  if (this->hasDirection() && !isPerpDirections(direction, _headDirection))
    return DIRECTION_TO_VEC2.at(_headDirection);
  return DIRECTION_TO_VEC2.at(direction);
}

Vector2 Snake::getHeadPosition() const { return _body.back(); }

void Snake::removeTail() { _body.pop_front(); }

bool Snake::hasDirection() const { return _headDirection != Direction::None; }

Collision Snake::detectCollision(const Vector2& applePosition) const {
  const Vector2 headPosition = this->getHeadPosition();
  if (Vector2Equals(headPosition, applePosition)) return Collision::Apple;
  if (!utils::inBounds(headPosition)) return Collision::Wall;
  const auto collidesWithHead = [&headPosition](const auto& pos) {
    return Vector2Equals(pos, headPosition);
  };
  if (this->hasDirection() &&
      std::any_of(std::next(_body.rbegin()), _body.rend(), collidesWithHead))
    return Collision::Self;
  return Collision::None;
}

bool Snake::CollidesWith(const Vector2& position) const {
  return std::ranges::any_of(_body, [&position](const auto& bodyPos) {
    return Vector2Equals(position, bodyPos);
  });
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
