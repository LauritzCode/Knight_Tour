#include "board.h"
#include "thinking.h"
#include "tour.h"
#include <stddef.h>
#include <stdio.h>

int main(void) {

  // Regular greedy tour

  printf("Welcome to Knight's tour. Let's play around with various "
         "scenarios:\nSelect coordinates X Y, between 0 and 7 for each: ");
  size_t p_y1;
  size_t p_x1;
  scanf("%zu %zu", &p_y1, &p_x1);
  simulate_thinking(500, 1500);
  tour_greedy(p_y1, p_x1);

  printf("\n\nHere's your knight attempting the tour from each square: "
         "(ORIGINAL 8X8 GRID)\n");
  greedy_tour_from_each_square();

  // VLA versions

  printf("\n\nNow choose the size of the grid(ROWS:COLS), and XY "
         "coordinates,\ninclude "
         "one space in between: ");

  size_t p_row, p_col, p_y2, p_x2;

  scanf("%zu %zu %zu %zu", &p_row, &p_col, &p_y2, &p_x2);
  simulate_thinking(1000, 1500);
  tour_greedy_vla(p_row, p_col, p_x2, p_y2);
  simulate_thinking(1000, 1500);

  printf("\n\n And here's your knight attempting the tour from each square: "
         "(YOUR %zux%zu GRID):\n\n",
         p_row, p_col);
  greedy_tour_from_each_square_vla(p_row, p_col);
}