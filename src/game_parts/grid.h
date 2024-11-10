#pragma once

#include "colours.h"
#include <raylib.h>
#include <vector>

class Grid {
public:
  Grid();
  void Initialize();
  void Draw();
  void Debug();
  int grid[20][10];
  std::vector<Color> colours = cellColours;

  bool IsOutOfBounds(int row, int column);
  bool IsCellEmpty(int row, int column);
  int ClearFullRows();

private:
  int rowCount = 20;
  int colCount = 10;
  int cellSize = 30;

  bool IsRowFull(int row);
  void ClearRow(int row);
  void MoveRowDown(int row, int rowOffset);
};
