#include "HeaderFiles/colours.h"
#include "HeaderFiles/game.h"
#include <cstdio>
#include <raylib.h>

const int windowWidth = 530;
const int windowHeight = 620;

int main() {
  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  Game game;

  while (!WindowShouldClose()) {
    UpdateMusicStream(game.music);
    BeginDrawing();
    ClearBackground(deepBlue);

    game.handleInput();
    game.tick();
    game.render();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
