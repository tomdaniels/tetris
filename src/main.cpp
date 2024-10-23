#include "game.h"
#include <cstdio>
#include <raylib.h>

const int windowWidth = 300;
const int windowHeight = 600;

Color deepBlue = {44, 44, 127, 255};

int main() {
  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(deepBlue);
    game.draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
