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