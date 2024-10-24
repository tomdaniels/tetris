#include "game.h"
#include <cstdio>
#include <raylib.h>

const int windowWidth = 300;
const int windowHeight = 600;

double lastUpdatedTime = 0;

bool TimeElapsed(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdatedTime >= interval) {
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}

Color deepBlue = {44, 44, 127, 255};

int main() {
  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(deepBlue);

    game.handleInput();

    game.draw();

    if (TimeElapsed(0.2) && !game.isGameOver) {
      game.moveBlockDown();
    }

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
