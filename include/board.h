#include <stddef.h>

#define SIZE 8

typedef unsigned int board_t[SIZE][SIZE];

void clearBoard(board_t b);
void printBoard(const board_t b);