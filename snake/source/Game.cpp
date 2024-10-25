#include "Game.hpp"

#include <chrono>

#include "Apple.hpp"
#include "Snake.hpp"
#include "Specs.hpp"
#include "Utils.hpp"
#include "raylib.h"

using namespace snake;

Game::Game() {
  InitWindow(specs::windowWidth, specs::windowHeight, specs::windowTitle);
  SetTargetFPS(specs::gameFPS);
}

Game::~Game() { CloseWindow(); }

void Game::Run() {
  _isRunning = true;
  this->createSnake();
  this->spawnNewApple();
  while (!WindowShouldClose() && _isRunning) {
    this->update();
    this->Draw();
  }
  this->Run();
}

void Game::Draw() const {
  BeginDrawing();
  ClearBackground(specs::backgroundColor);
  _apple.Draw();
  _snake.Draw();
  this->displayScore();
  EndDrawing();
}

void Game::update() { this->handleSnakeKeyPress(); }

bool Game::shouldMoveSnake() const {
  using namespace std::chrono;
  static time_point prevSnakeMovementTime = high_resolution_clock::now();
  const time_point now = high_resolution_clock::now();
  const milliseconds timePassed =
      duration_cast<milliseconds>(now - prevSnakeMovementTime);
  if (timePassed >= specs::snakeMoveRate) {
    prevSnakeMovementTime = now;
    return true;
  }
  return false;
}

void Game::handleSnakeMovement(const Collision collision) {
  switch (collision) {
    case Collision::Apple:
      this->spawnNewApple();
      break;
    case Collision::Self:
    case Collision::Wall:
      this->reset();
      break;
    default:
      break;
  }
}

void Game::createSnake() {
  _snake = utils::generateRandomPosition(specs::cellsPerRow -
                                         specs::initialSnakeBodyLength);
}

void Game::spawnNewApple() {
  Vector2 newApplePosition{};
  do {
    newApplePosition = utils::generateRandomPosition();
  } while (_snake.CollidesWith(newApplePosition));
  _apple = newApplePosition;
}

void Game::reset() {
  _isRunning = false;
  _nextSnakeDirection = Direction::None;
}

int Game::currentGameScore() const {
  return _snake.SnakeLength() - specs::initialSnakeBodyLength;
}

void Game::displayScore() const {
  DrawText(TextFormat("score : %d", this->currentGameScore()), specs::cellSize,
           specs::cellSize, specs::scoreFontSize, specs::scoreColor);
}

void Game::handleSnakeKeyPress() {
  switch (GetKeyPressed()) {
    case KEY_UP:
    case KEY_W:
    case KEY_K:
      _nextSnakeDirection = Direction::Up;
      break;
    case KEY_RIGHT:
    case KEY_D:
    case KEY_L:
      _nextSnakeDirection = Direction::Right;
      break;
    case KEY_DOWN:
    case KEY_S:
    case KEY_J:
      _nextSnakeDirection = Direction::Down;
      break;
    case KEY_LEFT:
    case KEY_A:
    case KEY_H:
      _nextSnakeDirection = Direction::Left;
      break;
  }
  if (this->shouldMoveSnake()) {
    const Collision snakeMovementCollision =
        _snake.Move(_nextSnakeDirection, _apple.GetPosition());
    this->handleSnakeMovement(snakeMovementCollision);
  }
}
