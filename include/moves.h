#include "board.h"
#include <stdbool.h>
#include <stddef.h>

#define MOVE_COUNT 8

extern const int MOVES_X[MOVE_COUNT];
extern const int MOVES_Y[MOVE_COUNT];

bool move_is_possible(size_t move_id, size_t x, size_t y,
                      const board_t visited);

bool move_is_possible_VLA(size_t move_id, size_t x, size_t y, size_t rows,
                          size_t cols, unsigned int board[rows][cols]);