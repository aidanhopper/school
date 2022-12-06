#include "header.h"
#include <stdio.h>

void init_player(Player *player) {
  for (int row = 0; row < 10; row++)
    for (int col = 0; col < 10; col++)
      player->board[row][col] = '-';
  for (int i = 0; i < 5; i++)
    player->sunk[i] = 0;
}

  void print_board(Player * player) {
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

  void clear() { system("clear"); }

  void welcome_screen() {
    printf("Rules of the Game:\n"
           "1. This is a two player game.\n"
           "2. Player1 is you and Player2 is the computer.\n"
           "3. Etc. (You need to list the rest of the rules here.)\n"
           "Hit enter to start the game!\n");
    getchar();
  }

  int place_method() {
    printf(
        "Please select from the following menu\n"
        "1. Enter the positions of the ships manually.\n"
        "2. Allow the program to randomly select the positions of the ships\n");
    int num;
    scanf("%d%*c", &num);
    return num;
  }

  int overlap(Player * player, int ship[10], int size) {
    for (int i = 0; i < size; i += 2)
      if (player->board[ship[i]][ship[i + 1]] != '-')
        return 1;
    return 0;
  }

  void manually_place_ships(Player * player) {
    // get carrier positions
    int ship[10];
    int o;

    do {
      printf("Please enter 5 cells to place the carrier accross\n");
      scanf("%d%d%d%d%d%d%d%d%d%d", &ship[0], &ship[1], &ship[2], &ship[3],
            &ship[4], &ship[5], &ship[6], &ship[7], &ship[8], &ship[9]);
      o = overlap(player, ship, 10);
    } while (o);

    // place carrier
    for (int i = 0; i < 10; i += 2)
      player->board[ship[i]][ship[i + 1]] = 'c';

    do {
      // get battleship positions
      printf("Please enter 4 cells to place the battleship accross\n");
      scanf("%d%d%d%d%d%d%d%d", &ship[0], &ship[1], &ship[2], &ship[3],
            &ship[4], &ship[5], &ship[6], &ship[7]);
      o = overlap(player, ship, 8);
    } while (o); // place battleship
    for (int i = 0; i < 8; i += 2)
      player->board[ship[i]][ship[i + 1]] = 'b';

    do {
      // get cruiser positions
      printf("Please enter 3 cells to place the cruiser accross\n");
      scanf("%d%d%d%d%d%d", &ship[0], &ship[1], &ship[2], &ship[3], &ship[4],
            &ship[5]);
      o = overlap(player, ship, 6);
    } while (o);

    // place cruiser
    for (int i = 0; i < 6; i += 2)
      player->board[ship[i]][ship[i + 1]] = 'r';

    do {
      // get submarine positions
      printf("Please enter 3 cells to place the submarine accross\n");
      scanf("%d%d%d%d%d%d", &ship[0], &ship[1], &ship[2], &ship[3], &ship[4],
            &ship[5]);
      o = overlap(player, ship, 6);
    } while (o);

    // place submarine
    for (int i = 0; i < 6; i += 2)
      player->board[ship[i]][ship[i + 1]] = 's';

    do {
      // get destroyer positions
      printf("Please enter 2 cells to place the destroyer accross\n");
      scanf("%d%d%d%d", &ship[0], &ship[1], &ship[2], &ship[3]);
      o = overlap(player, ship, 4);
    } while (o);

    // place destroyer
    for (int i = 0; i < 4; i += 2)
      player->board[ship[i]][ship[i + 1]] = 'd';
  }

  int over(Player * player, int row, int col, int orientation, int len) {
    int end_row = row + 1;
    int end_col = col + 1;
    if (orientation == 0)
      end_col += len;
    else if (orientation == 1)
      end_row += len;

    for (int r = row; r < end_row; r++)
      for (int c = col; c < end_col; c++)
        if (player->board[r][c] != '-')
          return 1;
    return 0;
  }

  void plac(Player * player, int row, int col, int orientation, int len,
            char ch) {
    int end_row = row;
    int end_col = col;
    if (orientation == 0)
      end_col += (len - 1);
    else if (orientation == 1)
      end_row += (len - 1);

    for (int r = row; r <= end_row; r++)
      for (int c = col; c <= end_col; c++)
        // printf("board[%d][%d]\n", r, c);
        player->board[r][c] = ch;
  }

  void randomly_place_ships(Player * player) {

    int o;
    int row;
    int col;
    int orientation;

    // carrier
    do {
      orientation = rand() % 2;
      // 0 for left to right
      // 1 for up and down
      if (orientation == 0) {
        row = rand() % 10;
        col = rand() % 5;
      }
      if (orientation == 1) {
        row = rand() % 5;
        col = rand() % 10;
      }
      o = over(player, row, col, orientation, 5);
    } while (o);
    plac(player, row, col, orientation, 5, 'c');

    // battleship
    do {
      orientation = rand() % 2;
      // 0 for left to right
      // 1 for up and down
      if (orientation == 0) {
        row = rand() % 10;
        col = rand() % 6;
      }
      if (orientation == 1) {
        row = rand() % 6;
        col = rand() % 10;
      }
      o = over(player, row, col, orientation, 4);
    } while (o);
    plac(player, row, col, orientation, 4, 'b');

    // cruiser
    do {
      orientation = rand() % 2;
      // 0 for left to right
      // 1 for up and down
      if (orientation == 0) {
        row = rand() % 10;
        col = rand() % 7;
      }
      if (orientation == 1) {
        row = rand() % 7;
        col = rand() % 10;
      }
      o = over(player, row, col, orientation, 3);
    } while (o);
    plac(player, row, col, orientation, 3, 'r');

    // submarine
    do {
      orientation = rand() % 2;
      // 0 for left to right
      // 1 for up and down
      if (orientation == 0) {
        row = rand() % 10;
        col = rand() % 7;
      }
      if (orientation == 1) {
        row = rand() % 7;
        col = rand() % 10;
      }
      o = over(player, row, col, orientation, 3);
    } while (o);
    plac(player, row, col, orientation, 3, 's');

    // destroyer
    do {
      orientation = rand() % 2;
      // 0 for left to right
      // 1 for up and down
      if (orientation == 0) {
        row = rand() % 10;
        col = rand() % 8;
      }
      if (orientation == 1) {
        row = rand() % 8;
        col = rand() % 10;
      }
      o = over(player, row, col, orientation, 2);
    } while (o);
    plac(player, row, col, orientation, 2, 'd');
  }

  void place(Player *player, int option) {
    // manually place
    if (option == 1)
      manually_place_ships(player);

    // auto place
    else if (option == 2)
      randomly_place_ships(player);
  }

  int check_hit(Player *player, int shot[2]) {
    player->shots++;
    if (player->board[shot[0]][shot[1]] != '-') {
      player->hits++;
      printf("HIT!\n");
      return 1;
    }

    else {
      player->misses++;

      printf("NOT A HIT!\n");
      return 0;
    }
  }

  void print_shot(int shot[2]) {
    printf("Shot row: %d, column: %d\n", shot[0], shot[1]);
  }

char check_if_sunk(Player * player, Player * dummy) {

  char map['s' + 1] = {0};

  for (int row = 0; row < 10; row++)
    for (int col = 0; col < 10; col++)
      if (player->board[row][col] != '-' && dummy->board[row][col] == '*')
	map[player->board[row][col]]++;

  // carrier
  if (player->sunk[0] == 0)
    if (map['c'] == 5) {
      player->sunk[0] = 1;
      return 'c';
    }
    
  // battleship
  if (player->sunk[1] == 0)
    if (map['b'] == 4) {
      player->sunk[1] = 1;
      return 'b';
    }

  // cruiser
  if (player->sunk[2] == 0)
    if (map['r'] == 3) {
      player->sunk[2] = 1;
      return 'r';
    }

  // submarine
  if (player->sunk[3] == 0)
    if (map['s'] == 3) {
      player->sunk[3] = 1;
      return 's';
    }

  // destroyer
  if (player->sunk[4] == 0)
    if (map['d'] == 3) {
      player->sunk[4] = 1;
      return 'd';
    }

  return 0;
}

int check_win(Player *player1, Player *player2) {
  int sunk1 = 0;
  for (int i = 0; i < 5; i++)
    sunk1+=player1->sunk[i];
  if (sunk1 == 4)
    return 2;

  int sunk2 = 0;
  for (int i = 0; i < 5; i++)
    sunk2+=player2->sunk[i];
  if (sunk2 == 4)
    return 1;

  return 0;
} 
  
