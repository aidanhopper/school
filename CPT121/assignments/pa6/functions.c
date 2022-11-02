#include "header.h"
#include <stdio.h>

void init_board(char board[20][10]) {
  for (int row = 0; row < 20; row++)
    for (int col = 0; col < 10; col++)
      board[row][col] = '-';
}

void print_board(char board[20][10]) {
  for (int row = 0; row < 20; row++) {
    if (row == 10) 
      printf("\n");
    if (row == 10 || row == 0)
      printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int col = 0; col < 10; col++) {
      if (col == 0)
	printf("%d ", row % 10);
      printf("%c ", board[row][col]);
    }
    printf("\n");
  }
}
