#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS // telling scanf to shutup

#include <time.h> // need this for rand function
#include <stdio.h> // has usefule i/o functions
#include <stdlib.h> // has useful functions like rand

// pre: must have balance wager and point variables before calling
// post: adjusts the balance
// prints out messages and adjusts balance
void adjust_and_print_balance(double *balance, double wager, int point);

// pre: nothing
// post: nothing
// prints a message based on these variables
void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);

// pre: must have point variable
// post: returns true or false or nothing
// rolls die and checks if it hits the point
int roll_and_check_point(int point);

// pre: nothing
// post: returns the point
// gets the point for later use
int roll_and_get_point(void);

// pre: needs balance
// post: returns the wager 
// prints and returns wager
double get_and_print_wager(double balance);

// pre: nothing
// post: nothing
// prints the rules to craps
void print_game_rules(void);

// pre: nothing
// post returns the bank balance as a double
// gets the bank balance from the user
double get_bank_balance(void);

// pre: nothing
// post: returns the wager as a double
// gets the wager from the user
double get_wager_amount(void);

// pre: needs a wager and a balance
// post: returns true or false
// checks if wager is less than the balance
int check_wager_amount(double wager, double balance);

// pre: nothing
// post: returns an integer between 1 and 6
// rolls a simulated die
int roll_die(void);

// pre: two integers
// post: an integer
// calculates the sum and returns the sum 
int calculate_sum_dice(int die_value1, int die_value2);

// pre: the sum of the dice
// post returns true, false, or the point as an integer
// checks if rolls were a win loss or point
int is_win_loss_or_point(int sum_dice);

// pre: needs the dice sum and point
// post: returns true, false, or -1
// checks if the sum hits the point value or if its a loss
int is_point_loss_or_neither(int sum_dice, int point_value);

// pre: needs balance, wage, and a true or false value
// post returns the new bank balance
// adds or subracts the wage from the balance
double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract);

#endif
