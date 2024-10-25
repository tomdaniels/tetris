#include "colours.h"
#include "game.h"
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

  while (!WindowShouldClose()) {
    UpdateMusicStream(game.music);
    BeginDrawing();
    ClearBackground(deepBlue);
    DrawText("Score", 360, 15, 38, WHITE);
    DrawText("Next", 375, 175, 38, WHITE);
    if (game.isGameOver) {
      DrawText("Game Over!", 320, 450, 38, WHITE);
    }
    DrawRectangleRounded({320, 55, 200, 60}, 0.3, 6, lightBlue);
    DrawRectangleRounded({320, 215, 200, 180}, 0.3, 6, lightBlue);

    char scoreText[10];
    sprintf(scoreText, "%d", game.score);
    int textWidth = MeasureText(scoreText, 38);
    DrawText(scoreText, 360 + (120 - textWidth) / 2, 65, 38, WHITE);

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
