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

bool Grid::isOutOfBounds(int row, int column) {
  if (row >= 0 && row < rowCount && column >= 0 && column < colCount) {
    return false;
  }

  return true;
}

bool Grid::isCellEmpty(int row, int column) {
  if (grid[row][column] == 0) {
    return true;
  }
  return false;
}

bool Grid::isRowFull(int row) {
  for (int column = 0; column < colCount; column++) {
    if (grid[row][column] == 0) {
      return false;
    }
  }
  return true;
}

void Grid::clearRow(int row) {
  for (int column = 0; column < colCount; column++) {
    grid[row][column] = 0;
  }
}

void Grid::moveRowDown(int row, int rowOffset) {
  for (int column = 0; column < colCount; column++) {
    grid[row + rowOffset][column] = grid[row][column];
    grid[row][column] = 0;
  }
}

int Grid::clearFullRows() {
  int completed = 0;
  for (int row = rowCount - 1; row >= 0; row--) {
    if (isRowFull(row)) {
      completed++;
      clearRow(row);
    } else if (completed > 0) {
      moveRowDown(row, completed);
    }
  }
  return completed;
}
