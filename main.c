#include "board.h"
#include "thinking.h"
#include "tour.h"
#include <stddef.h>
#include <stdio.h>

int main(void) {

  // Regular greedy tour

  printf("Welcome to Knight's tour. Let's play around with various "
         "scenarios:\nSelect coordinates X Y, between 0 and %d for each: ",
         SIZE - 1);
  size_t p_y1;
  size_t p_x1;

  if (scanf("%zu %zu", &p_y1, &p_x1) != 2) {
    printf("Invalid input.\n");
    return 1;
  }

  if (p_x1 >= SIZE || p_y1 >= SIZE) {
    printf("Out of bounds.\n");
    return 1;
  }

  simulate_thinking(500, 1500);
  tour_greedy(p_x1, p_y1);

  printf("\n\nHere's your knight attempting the tour from each square: "
         "(ORIGINAL 8X8 GRID)\n");
  greedy_tour_from_each_square();

  // VLA versions

  printf("\n\nNow choose the size of the grid and coords(ROWS COLS X Y). "
         "\ninclude one space in between: ");

  size_t p_row, p_col, p_y2, p_x2;

  if (scanf("%zu %zu %zu %zu", &p_row, &p_col, &p_x2, &p_y2) != 4) {
    printf("Invalid input.\n");
    return 1;
  }

  // Validate sizes to protect stack overflow.

  const size_t MAX = 64;

  if (p_row == 0 || p_col == 0 || p_col > MAX || p_row > MAX) {
    printf("Grid must be within limits. 1x%zu", MAX);
    return 1;
  }

  if (p_x2 >= p_col || p_y2 >= p_row) {
    printf("Start out of bounds for %zux%zu.\n", p_row, p_col);
    return 1;
  }

  simulate_thinking(1000, 1500);
  tour_greedy_vla(p_row, p_col, p_x2, p_y2);
  simulate_thinking(1000, 1500);

  printf("\n\n And here's your knight attempting the tour from each square: "
         "(YOUR %zux%zu GRID):\n\n",
         p_row, p_col);
  greedy_tour_from_each_square_vla(p_row, p_col);

  return 0;
}