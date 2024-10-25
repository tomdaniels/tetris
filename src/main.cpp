#include "colours.h"
#include "game.h"
#include "ui.h"
#include <cstdio>
#include <raylib.h>

const int windowWidth = 530;
const int windowHeight = 620;

double lastUpdatedTime = 0;

bool TimeElapsed(double interval) {
  double currentTime = GetTime();
  if (currentTime - lastUpdatedTime >= interval) {
    lastUpdatedTime = currentTime;
    return true;
  }
  return false;
}

int main() {
  InitWindow(windowWidth, windowHeight, "Tetris");
  SetTargetFPS(60);

  Game game;
  UI ui;

  while (!WindowShouldClose()) {
    UpdateMusicStream(game.music);
    BeginDrawing();
    ClearBackground(deepBlue);

    ui.paint(game.score, game.isGameOver);

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
