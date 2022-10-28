#include "header.h"

int main(void) {

  srand(time(NULL)); // seeding the rand function
  double initial_balance;
  double balance;
  int rolls;
  while (1) {
    int choice;
    printf("What would you like to do?\n1. play\n2. display rules\n3. exit\n");
    scanf("%d", &choice);
    if (choice == 2)
      print_game_rules();
    else if (choice == 1) {
      initial_balance = get_bank_balance();
      balance = initial_balance;
      rolls = 0;
    }
    else break;
    while (choice == 1) {
      // get a wager amount
      if (balance == 0) {
        printf("Your balance is $0... you lose!\n");
	break;
      }
      chatter_messages(0, 10, initial_balance, balance);
      // getting wager
      double wager = get_and_print_wager(balance);

      // check if wager is less than the balance
      // if not then restart the loop and get a new wager
      if (check_wager_amount(wager, balance)) {
	// getting the point or win and incrementing rolls
	int point = roll_and_get_point();
	rolls++;

	chatter_messages(rolls, point, initial_balance, balance);

	// check if win or lose on the first roll
	int win = 0;
	if (point == 1) { // if win
	  balance = adjust_bank_balance(balance, wager, point);
	  printf("You win $%.02lf, your balance is now $%.02lf\n", wager,
		 balance);
	  win = 1;
	} else if (point == 0) { // if lose
	  balance = adjust_bank_balance(balance, wager, point);
	  printf("You lose $%.02lf, your balance is now $%.02lf\n", wager, balance);
	  win = 1;
	}
	// if there wasnt a win or loss on the first roll
	// then keep rolling until loss or sum hits point
	while (!win) {
	  // getting the roll or win and incrementing rolls
	  int roll = roll_and_check_point(point);
	  rolls++;

	  chatter_messages(rolls, point, initial_balance, balance);
	  if (roll == 1) { // if win
	    adjust_and_print_balance(&balance, wager, roll);
	    break;
	  } else if (roll == 0) { // if lose
	    adjust_and_print_balance(&balance, wager, roll);
	    break;
	  }
	}
      } else {
	// prints if wager is invalid
	printf("Your wager is more than your balance!\n");
      }
    }
  }
  return 0;
}
