#include "grid.h"
#include <iostream>
#include <raylib.h>

Grid::Grid() { Initialize(); }

void Grid::Initialize() {
  for (int row = 0; row < rowCount; row++) {
    for (int col = 0; col < colCount; col++) {
      grid[row][col] = 0;
    };
  };
}

void Grid::Draw() {
  for (int row = 0; row < rowCount; row++) {
    for (int col = 0; col < colCount; col++) {
      int cellValue = grid[row][col];

      DrawRectangle(col * cellSize + 11, row * cellSize + 11, cellSize - 1,
                    cellSize - 1, colours[cellValue]);
    };
  };
}

void Grid::Debug() {
  for (int row = 0; row < rowCount; row++) {
    for (int col = 0; col < colCount; col++) {
      std::cout << grid[row][col] << " ";
    };
    std::cout << std::endl;
  };
}

bool Grid::IsOutOfBounds(int row, int column) {
  if (row >= 0 && row < rowCount && column >= 0 && column < colCount) {
    return false;
  }

  return true;
}

bool Grid::IsCellEmpty(int row, int column) {
  if (grid[row][column] == 0) {
    return true;
  }
  return false;
}

bool Grid::IsRowFull(int row) {
  for (int column = 0; column < colCount; column++) {
    if (grid[row][column] == 0) {
      return false;
    }
  }
  return true;
}

void Grid::ClearRow(int row) {
  for (int column = 0; column < colCount; column++) {
    grid[row][column] = 0;
  }
}

void Grid::MoveRowDown(int row, int rowOffset) {
  for (int column = 0; column < colCount; column++) {
    grid[row + rowOffset][column] = grid[row][column];
    grid[row][column] = 0;
  }
}

int Grid::ClearFullRows() {
  int completed = 0;
  for (int row = rowCount - 1; row >= 0; row--) {
    if (IsRowFull(row)) {
      completed++;
      ClearRow(row);
    } else if (completed > 0) {
      MoveRowDown(row, completed);
    }
  }
  return completed;
}
