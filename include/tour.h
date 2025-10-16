#include <stddef.h>

unsigned int tour_greedy(size_t start_x, size_t start_y);

unsigned int
tour_greedy_silent(size_t start_x,
                   size_t start_y); // same function, but doesn't print, thus
                                    // silent to prevent spam output.

void greedy_tour_from_each_square(
    void); // tries every possible start and prints the counts grid.

// VLA

unsigned int tour_greedy_vla(size_t rows, size_t cols, size_t start_x,
                             size_t start_y);

unsigned int tour_greedy_silent_vla(size_t rows, size_t cols, size_t start_x,
                                    size_t start_y);

void greedy_tour_from_each_square_vla(size_t rows, size_t cols);