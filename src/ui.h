#pragma once

class UI {
public:
  void paint(int score, bool isGameOver);

private:
  void drawScore(int score);
  void drawNextBlock();
  void drawGameOver(bool isGameOver);
};
