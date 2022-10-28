#include "header.h"
#include <stdio.h>

void print_game_rules(void) {
  printf(
    "A player rolls two dice. Each die has six faces. These faces contain 1, \n"
    "2, 3, 4, 5, and 6 spots. After the dice have come to rest, the sum of the \n"
    "spots on the two upward faces is calculated. If the sum is 7 or 11 on the \n"
    "first throw, the player wins. If the sum is 2, 3, or 12 on the first \n"
    "throw (called \"craps\"), the player loses (i.e. the \"house\" wins). If \n"
    "the sum is 4, 5, 6, 8, 9, or 10 on the first throw, then the sum becomes \n"
    "the player's \"point.\" To win, you must continue rolling the dice until \n"
    "you \"make your point.\" The player loses by rolling a 7 before making "
    "the point.\n"
  );
}

double get_bank_balance(void) {
  double balance = 0;
  printf("Enter a bank balance in $: ");
  scanf("%lf", &balance);
  return balance;
}

double get_wager_amount(void) {
  double wager = 0;
  scanf("%lf", &wager);
  return wager;
}

int check_wager_amount(double wager, double balance) {
  return wager > balance ? 0 : 1;
}

int roll_die(void) {
  return (rand() % 6) + 1;
}

int calculate_sum_dice(int die_value1, int die_value2) {
  return die_value1 + die_value2;
}

int is_win_loss_or_point(int sum_dice) {
  if (sum_dice == 7 || sum_dice == 11)
    return 1;
  if (sum_dice == 2 || sum_dice == 3 || sum_dice == 12)
    return 0;
  return sum_dice;
}

int is_point_loss_or_neither(int sum_dice, int point_value) {
  if (sum_dice == point_value)
    return 1;
  if (sum_dice == 7)
    return 0;
  return -1;
}

double adjust_bank_balance(double bank_balance, double wager_amount, int add_or_subtract) {
  if (add_or_subtract == 1)
    bank_balance += wager_amount;
  else if (add_or_subtract == 0)
    bank_balance -= wager_amount;
  return bank_balance;
}

double get_and_print_wager(double balance) {
  printf("Enter a wager amount less than"
	 " or equal to %.2lf$ : ",
	 balance);
  return get_wager_amount();
}

int roll_and_get_point(void) {
  int die1 = roll_die();
  int die2 = roll_die();
  int sum_dice = calculate_sum_dice(die1, die2);
  int point = is_win_loss_or_point(sum_dice);
  printf("roll 1: %d, roll 2: %d, sum: %d\n", die1, die2, sum_dice);
  return point;
}

int roll_and_check_point(int point) {
  int die1 = roll_die();
  int die2 = roll_die();
  int sum_dice = calculate_sum_dice(die1, die2);
  int roll = is_point_loss_or_neither(sum_dice, point);
  printf("roll 1: %d, roll 2: %d, sum: %d, point: %d\n", die1, die2, sum_dice, point);
  return roll;
}

void adjust_and_print_balance(double *balance, double wager, int point) {
  *balance = adjust_bank_balance(*balance, wager, point);
  if (point == 1) {
    printf("You win $%.02lf, your balance is now $%.02lf\n", wager, *balance);
  }
  else if (point == 0) {
    printf("You lose $%.02lf, your balance is now $%.02lf\n", wager, *balance);
  }
}

void chatter_messages(int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance) {
  if (number_rolls == 10) {
    printf("Thats a lot of rolls!\n");
  }
  else if (win_loss_neither == 1) {
    printf("BIG WIN!\n"); 
  }
  else if (win_loss_neither == 0) {
    printf("YOURE AN IDIOT!!!\n");
  }
  else if (current_bank_balance < (initial_bank_balance/3)) {
    printf("Your gambling addiction is the reason your wife left you\n");
  }
}
