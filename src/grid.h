#pragma once

#include "colours.h"
#include <raylib.h>
#include <vector>

class Grid {
public:
  Grid();
  void initialize();
  void draw();
  void debug();
  int grid[20][10];
  std::vector<Color> colours = cellColours;

  bool isOutOfBounds(int row, int column);
  bool isCellEmpty(int row, int column);
  int clearFullRows();

private:
  int rowCount = 20;
  int colCount = 10;
  int cellSize = 30;

  bool isRowFull(int row);
  void clearRow(int row);
  void moveRowDown(int row, int rowOffset);
};
