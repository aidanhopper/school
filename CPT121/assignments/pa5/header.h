#ifndef HEADER_H // header guard
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS // tells scanf to shutup

#include <stdio.h>  // includes useful io functions
#include <stdlib.h> // includes the rand function
#include <time.h>   // useful to seed rand with time

// wrapper struct for dice rolls that contains info on which die to roll
// and the face values of the die
typedef struct {
  char arr[5];
  char map[5];
} Roll;

// wrapper struct for player info which includes point info
// and which combinations have been used
typedef struct {
  int points;
  int upper;
  char map[13];
} Player;

// clears screen
// pre: nothing
// post: nothing
void clear();

// menu function
// pre: nothing
// post: returns selected menu option
char menu();

// prints rules of yahtzee
// pre: nothing
// post: nothing
void print_rules();

// generates die faces
// pre: roll info struct
// post: nothing 
void roll(Roll *roll_info);

// prints numbers in roll
// pre: roll info struct 
// post: nothing 
void print_roll(Roll roll_info);

// updates the roll map based on inputs from player
// pre: roll struct
// post: nothing
void update_roll_map(Roll *roll);

// roll struct constructor
// pre: roll struct
// post: nothing
void init_roll(Roll *roll_info);

// gets the combo option from player
// pre: need player input and total number of rolls
// post: returns the selected combo or 0
char get_combo(Player *player, int total_rolls);

// uses combo on player adding to points
// pre: needs player pointer, roll, and selected combo
// post: nothing
void use_combo(Player *player, Roll roll, int combo);

// player struct constructor
// pre: player struct
// post: nothing
void init_player(Player *player);

// sums num in roll
// pre: roll and selected number
// post: returns points gained
int sum_of_num(Roll roll, int num);

// checks for three of a kind
// pre: roll info
// post: returns points gained
int three_of_a_kind(Roll roll);

// checks for four of a kind
// pre: roll info
// post: returns points gained
int four_of_a_kind(Roll roll);

// checks for full house
// pre: roll info
// post: returns points gained
int full_house(Roll roll);

// checks for small straight
// pre: roll info
// post: returns points gained
int small_straight(Roll roll);

// checks for large straight
// pre: roll info
// post: returns points gained
int large_straight(Roll roll);

// checks for yahtzee
// pre: roll info
// post: returns points gained
int yahtzee(Roll roll);

// chance combo
// pre: roll info
// post: returns points gained
int chance(Roll roll);

#endif
