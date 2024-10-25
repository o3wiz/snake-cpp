#include "Game.hpp"

#include "Specs.hpp"
#include "raylib.h"

using namespace snake;

Game::Game() {
  InitWindow(specs::windowWidth, specs::windowHeight, specs::windowTitle);
  SetTargetFPS(specs::gameFPS);
}

Game::~Game() { CloseWindow(); }

void Game::Run() {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(specs::backgroundColor);
    EndDrawing();
  }
}
