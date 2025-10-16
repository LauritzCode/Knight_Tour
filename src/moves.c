#include "moves.h"
#include <stddef.h>

const int MOVES_X[MOVE_COUNT] = {2, 1, -1, -2, -2, -1, 1, 2};
const int MOVES_Y[MOVE_COUNT] = {1, 2, 2, 1, -1, -2, -2, -1};

bool move_is_possible(size_t move_id, size_t x, size_t y,
                      const board_t visited) {

  int nx = (int)x + MOVES_X[move_id];
  int ny = (int)y + MOVES_Y[move_id];

  // check boundaries
  if (nx < 0 || ny < 0 || nx >= (int)SIZE || ny >= (int)SIZE)
    return false;

  // check if target cell is unvisited.

  if (visited[ny][nx] != 0)
    return false;

  return true;
}