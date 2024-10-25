#include "Game.hpp"

#include "Specs.hpp"
#include "raylib.h"

using namespace snake;

Game::Game() {
  InitWindow(specs::windowWidth, specs::windowHeight, specs::windowTitle);
}

Game::~Game() { CloseWindow(); }

void Game::Run() {
  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(RAYWHITE);
    EndDrawing();
  }
}
