#include "grid.h"
#include <cstdio>
#include <raylib.h>

#include "blocks.cpp"

const int windowWidth = 300;
const int windowHeight = 600;

Color deepBlue = {44, 44, 127, 255};

int main() {
  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  Grid grid;
  IBlock block;
  grid.debug();

  while (!WindowShouldClose()) {
    BeginDrawing();
    ClearBackground(deepBlue);
    grid.draw();
    block.draw();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
