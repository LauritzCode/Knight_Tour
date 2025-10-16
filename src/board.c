#include "board.h"
#include <stddef.h>
#include <stdio.h>

void clearBoard(board_t b) {
  for (size_t y = 0; y < SIZE; y++) {
    for (size_t x = 0; x < SIZE; x++) {
      b[y][x] = 0;
    }
  }
}

void printBoard(const board_t b) {
  for (size_t y = 0; y < SIZE; y++) {
    for (size_t x = 0; x < SIZE; x++) {
      printf("%3u ", b[y][x]);
    }
    puts("");
  }
}

void clearBoardVLA(size_t rows, size_t cols, unsigned int board[rows][cols]) {
  for (size_t y = 0; y < rows; y++) {
    for (size_t x = 0; x < cols; x++) {
      board[y][x] = 0;
    }
  }
}
void printBoardVLA(size_t rows, size_t cols, unsigned int board[rows][cols]) {
  for (size_t y = 0; y < rows; y++) {
    for (size_t x = 0; x < cols; x++) {
      printf("%3u ", board[y][x]);
    }
    puts("");
  }
}