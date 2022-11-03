#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char board[10][10];
} Player;

void init_player(Player *player);
void print_board(char board[20][10]);
void welcome_screen();
void clear();
int place_method();


#endif
