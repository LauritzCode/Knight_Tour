#include "tour.h"
#include "board.h"
#include "moves.h"
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

unsigned int tour_greedy(size_t start_x, size_t start_y) {
  // setup board
  board_t board;
  clearBoard(board);

  board[start_x][start_y] = 1;
  size_t x = start_x;
  size_t y = start_y;

  unsigned int step = 1;
  board[y][x] = step;

  while (true) {
    bool moved = false;

    for (size_t move_id = 0; move_id < MOVE_COUNT; move_id++) {
      if (move_is_possible(move_id, x, y, board)) {
        int nx = (int)x + MOVES_X[move_id];
        int ny = (int)y + MOVES_Y[move_id];

        step++;
        x = (size_t)nx;
        y = (size_t)ny;
        board[y][x] = step;
        moved = true;
        break;
      }
    }
    if (!moved)
      break;
  }

  printf("Visited %u squares.\n", step);
  printBoard(board);
  return step;
}

unsigned int tour_greedy_silent(size_t start_x, size_t start_y) {
  // setup board
  board_t board;
  clearBoard(board);

  board[start_x][start_y] = 1;
  size_t x = start_x;
  size_t y = start_y;

  unsigned int step = 1;
  board[y][x] = step;

  while (true) {
    bool moved = false;

    for (size_t move_id = 0; move_id < MOVE_COUNT; move_id++) {
      if (move_is_possible(move_id, x, y, board)) {
        int nx = (int)x + MOVES_X[move_id];
        int ny = (int)y + MOVES_Y[move_id];

        step++;
        x = (size_t)nx;
        y = (size_t)ny;
        board[y][x] = step;
        moved = true;
        break;
      }
    }
    if (!moved)
      break;
  }

  return step;
}

void greedy_tour_from_each_square(void) {
  //
  unsigned int counts[SIZE][SIZE] = {0};

  for (size_t y = 0; y < SIZE; y++) {
    for (size_t x = 0; x < SIZE; x++) {
      counts[y][x] = tour_greedy_silent(x, y);
    }
  }

  // Printing

  for (size_t y = 0; y < SIZE; y++) {
    for (size_t x = 0; x < SIZE; x++) {
      printf("%3u ", counts[y][x]);
    }
    puts("");
  }
}