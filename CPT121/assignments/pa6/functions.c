#include "header.h"
#include <stdio.h>

void init_player(Player *player) {for (int row = 0; row < 10; row++)
    for (int col = 0; col < 10; col++)
      player->board[row][col] = '-';
}

void print_board(Player *player) {
  for (int row = 0; row < 10; row++) {
    if (row == 0)
      printf("  0 1 2 3 4 5 6 7 8 9\n");
    for (int col = 0; col < 10; col++) {
      if (col == 0)
	printf("%d ", row % 10);
      printf("%c ", player->board[row][col]);
    }
    printf("\n");
  }
}

void clear() {
  system("clear");
}

void welcome_screen() {
  printf("Rules of the Game:\n"
	 "1. This is a two player game.\n"
	 "2. Player1 is you and Player2 is the computer.\n"
	 "3. Etc. (You need to list the rest of the rules here.)\n"
	 "Hit enter to start the game!\n");
  getchar();
}

int place_method() {
  printf("Please select from the following menu\n"
	 "1. Enter the positions of the ships manually.\n"
	 "2. Allow the program to randomly select the positions of the ships\n");
  int num;
  scanf("%d%*c", &num);
  return num;
}

void manually_place_ships(Player *player) {
  // get carrier positions
  printf("Please enter 5 cells to place the carrier accross\n");
  int carrier[10];
  scanf("%d%d%d%d%d%d%d%d%d%d", &carrier[0], &carrier[1], &carrier[2],
  &carrier[3], &carrier[4], &carrier[5], &carrier[6], &carrier[7],
  &carrier[8], &carrier[9]);

  // place carrier
  for (int i = 0; i < 10; i+=2)
    player->board[i][i + 1] = 'c';
  
  // get carrier positions
  printf("Please enter 5 cells to place the carrier accross\n");
  int carrier[10];
  scanf("%d%d%d%d%d%d%d%d%d%d", &carrier[0], &carrier[1], &carrier[2],
  &carrier[3], &carrier[4], &carrier[5], &carrier[6], &carrier[7],
  &carrier[8], &carrier[9]);

  // place carrier
  for (int i = 0; i < 10; i+=2)
    player->board[i][i + 1] = 'c';
  
}

void place(Player *player, int option) {
  // manually place
  if (option == 1)
    manually_place_ships(player);

  // auto place
  else if (option == 2);
}
