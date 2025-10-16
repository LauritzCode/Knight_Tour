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

// VLA version

unsigned int tour_greedy_vla(size_t rows, size_t cols, size_t start_x,
                             size_t start_y) {

  unsigned int board[rows][cols];
  clearBoardVLA(rows, cols, board);

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

  printf("Visited %u squares on %zux%zu.\n", step, rows, cols);
  printBoardVLA(rows, cols, board);
  return step;
}

unsigned int tour_greedy_silent_vla(size_t rows, size_t cols, size_t start_x,
                                    size_t start_y) {

  unsigned int board[rows][cols];
  clearBoardVLA(rows, cols, board);

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

void greedy_tour_from_each_square_vla(size_t rows, size_t cols) {
  unsigned int counts[rows][cols];

  for (size_t y = 0; y < rows; y++) {
    for (size_t x = 0; x < cols; x++) {
      counts[y][x] = tour_greedy_silent_vla(rows, cols, x, y);
    }
  }

  // Printing

  for (size_t y = 0; y < rows; y++) {
    for (size_t x = 0; x < cols; x++) {
      printf("%3u ", counts[y][x]);
    }
    puts("");
  }
}