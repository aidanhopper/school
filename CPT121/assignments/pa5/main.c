#include "header.h"

int main() {

  // seeding rand
  srand(time(NULL));

  // menu loop
  char run = 1;
  while (run) {

    // gets option from user
    int option = print_menu();
    system("clear");

    // prints rules if 1 is selected
    if (option == 1)
      print_rules();

    // starts game loop if 2 is selected
    else if (option == 2) {

      // game data for player1 and player2
      Player player1;
      init_player(&player1);
      Player player2;
      init_player(&player2);

      // turn loop
      char turn = 0;
      int total_rolls = 0;
      Roll roll_info;
      init_roll(&roll_info);

      while (turn) {

        // hit any key to continue
	printf("Hit any key to continue on to roll the dice\n");
	getchar();

        // rolls dice
	roll(&roll_info);
	total_rolls++;
	print_roll(roll_info);

	// gets combination from player
	char combo = use_combo(total_rolls);

	// checks that user said yes to combination
	// and adds combo to map
	if (combo != 0) {
	  player1.map[combo - 1] = 1;
	  turn = 0;
	}
	 
      }
    }

    // exits program if 3 is selected
    else if (option == 3) run = 0;
  }
  
  return 0;
}
