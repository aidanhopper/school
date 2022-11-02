#include "header.h"

int main() {

  // rows 0-9 are player1, rows 10-19 are player2
  char board[20][10];
  init_board(board);

  print_board(board);


  return 0;
}
