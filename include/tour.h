#include <stddef.h>

unsigned int tour_greedy(size_t start_x, size_t start_y);

unsigned int
tour_greedy_silent(size_t start_x,
                   size_t start_y); // same function, but doesn't print, thus
                                    // silent to prevent spam output.

void greedy_tour_from_each_square(
    void); // tries every possible start and prints the counts grid.
