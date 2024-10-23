#include "grid.h"
#include <iostream>
#include <raylib.h>

Grid::Grid() { initialize(); }

void Grid::initialize() {
  for (int row = 0; row < rowCount; row++) {
    for (int col = 0; col < colCount; col++) {
      grid[row][col] = 0;
    };
  };
}

void Grid::draw() {
  for (int row = 0; row < rowCount; row++) {
    for (int col = 0; col < colCount; col++) {
      int cellValue = grid[row][col];

      DrawRectangle(col * cellSize + 1, row * cellSize + 1, cellSize - 1,
                    cellSize - 1, colours[cellValue]);
    };
  };
}

void Grid::debug() {
  for (int row = 0; row < rowCount; row++) {
    for (int col = 0; col < colCount; col++) {
      std::cout << grid[row][col] << " ";
    };
    std::cout << std::endl;
  };
}
