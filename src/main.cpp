#include "colours.h"
#include "game.h"
#include "ui.h"
#include <cstdio>
#include <raylib.h>

const int windowWidth = 530;
const int windowHeight = 620;

int main() {
  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  UI ui;
  Game game;

  while (!WindowShouldClose()) {
    UpdateMusicStream(game.music);
    BeginDrawing();
    ClearBackground(deepBlue);

    ui.paint(game.score, game.isGameOver);
    game.handleInput();
    game.draw();
    game.tick();

    EndDrawing();
  }

  CloseWindow();
  return 0;
}
