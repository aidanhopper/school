#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  char arr[5];
  char map[5];
} Roll;

typedef struct {
  int points;
  char map[12];
} Player;

char print_menu();
void print_rules();
void roll(Roll *roll_info);
void print_roll(Roll roll_info);
void init_roll(Roll *roll_info);
char use_combo(int total_rolls);
void init_player(Player *player);

#endif
