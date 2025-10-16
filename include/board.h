#include <stddef.h>

#define SIZE 8

typedef unsigned int board_t[SIZE][SIZE];

void clearBoard(board_t b);
void printBoard(const board_t b);

// VLA Board version declaration

void clearBoardVLA(size_t rows, size_t cols, unsigned int board[rows][cols]);
void printBoardVLA(size_t rows, size_t cols, unsigned int board[rows][cols]);