#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// stats struct
typedef struct {
  char board[10][10];
  char sunk[5];
  int hits;
  int misses;
  int shots;
  double hit_rate;
  int win_status;
} Player;

// inits player like constructor
// pre: player pointer
// post: nothing
void init_player(Player *player);

// places ships
// pre: player pointer and the option chosen
// post: nothing
void place(Player *player, int option);

// prints input board
// pre: player pointer
// post: nothing
void print_board(Player *player);

// prints welcome screen
// pre: nothing
// post: nothing
void welcome_screen();

// clears screen
// pre: nothing
// post: nothing
void clear();

// gets place method from user'
// pre: nothing
// post: option selected
int place_method();

// checks if shot was a hit
// pre: player pointer and shot
// post yes or no
int check_hit(Player *player, int shot[2]);

// prints a shot
// pre: input shot
// post: nothing
void print_shot(int shot[2]);

// checks if new ship was sunk
// pre: player poiner and dummy pointer
// post: returns ship that was sunk or 0
char check_if_sunk(Player * player, Player * dummy);

// checks for winner
// pre: player1 and player2 pointer
// post: returns which player won or 0
int check_win(Player *player1, Player *player2);

#endif
