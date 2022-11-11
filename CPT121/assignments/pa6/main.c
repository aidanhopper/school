/*

    Name: Aidn Hopper
    Date: 11/09/22
    Class: CPTS 121 Section 1
    Description: 6st programming assignment

*/

#include "header.h"
#include <stdio.h>

int main() {

  // seeding rand
  srand(time(NULL));

  // menu loop
  int run = 1;
  while (run) {

    run = 0;

    // outputs welcome screen
    welcome_screen();

    // creates both players
    Player player[2];
    init_player(&player[0]);
    init_player(&player[1]);

    // creates dummy players to track the hits
    Player dummy[2];
    init_player(&dummy[0]);
    init_player(&dummy[1]);

    // opening log file
    FILE *log;
    log = fopen("battleship.log", "w");

    clear();

    // gets placement method
    printf("Generate player 1s board\n");
    char method = place_method();
    place(&player[0], method);

    printf("Generate computers board\n");
    place(&player[1], 2);

    int first = rand() % 2;
    int turn = 0;
    int winner = 0;
    int play = 1;

    // game loop
    while (play) {
      //clear();

      // gets current player and prints board and dummyboard
      int cur_player = (turn + first) % 2;
      int other_player = 0;
      if (cur_player == 0)
	other_player = 1;
      printf("Player %d's board\n", cur_player + 1);
      print_board(&player[cur_player]);
      printf("Player %d's board\n", other_player + 1);
      print_board(&dummy[cur_player]);

      // users turn
      if (cur_player == 0) {
	printf("enter a shot\n");
	int shot[2];
	// gets valid input
	do {
	  scanf("%d%d%*c", &shot[0], &shot[1]);
	} while (dummy[cur_player].board[shot[0]][shot[1]] == '*');
	// sets dummy board
	dummy[cur_player].board[shot[0]][shot[1]] = '*';
        print_shot(shot);
	int hit = check_hit(&player[other_player], shot);
	char sunk = check_if_sunk(&player[other_player], &dummy[cur_player]);
	// prints to file
	if (sunk != 0)
	  printf("%c was sunk!\n", sunk);
	fprintf(log, "%d %d, ", shot[0], shot[1]);
	if (hit)
	  fprintf(log, "HIT, ");
	else
	  fprintf(log, "NOT A HIT, ");
	if (sunk != 0)
	  fprintf(log, "%c WAS SUNK\n", sunk);
	else
	  fprintf(log, "NOTHING WAS SUNK\n");
	printf("Press any key to continue\n");
	getchar();
      }

      // computers turn
      else {
	int shot[2];
	// gets valid input
	do {
	  shot[0] = rand() % 10;
	  shot[1] = rand() % 10;
	} while (dummy[cur_player].board[shot[0]][shot[1]] == '*');
	dummy[cur_player].board[shot[0]][shot[1]] = '*';
        print_shot(shot);
	int hit = check_hit(&player[other_player], shot);
	char sunk = check_if_sunk(&player[other_player], &dummy[other_player]);
	// writes to file
	if (sunk != 0)
	  printf("%c was sunk!\n", sunk);
	fprintf(log, "%d %d, ", shot[0], shot[1]);
	if (hit)
	  fprintf(log, "HIT, ");
	else
	  fprintf(log, "NOT A HIT, ");
	if (sunk != 0)
	  fprintf(log, "%c WAS SUNK\n", sunk);
	else
	  fprintf(log, "NOTHING WAS SUNK\n");
	printf("Press any key to continue\n");
	getchar();
      }

      // checks for winner
      winner = check_win(&player[0], &player[1]);
      printf("%d\n", winner);

      // if there is a winner write stats fo file
      if (winner != 0) {
	printf("Player %d wins!\n", winner);
	player[winner-1].win_status = 1;
	if (winner == 1)
	  player[1].win_status = 0;
	else
	  player[0].win_status = 0;
	play = 0;
      }

      // increments turn
      turn++;
    }

    // calcualtes hit rate
    player[0].hit_rate = (double) player[0].hits / (double) player[0].shots;
    player[1].hit_rate = (double) player[1].hits / (double) player[1].shots;

    // outputs stats 
    fprintf(log, "\nSTATS\n");
    fprintf(log, "Player1 hits: %d\n", player[0].hits);
    fprintf(log, "Player2 hits: %d\n", player[1].hits);
    fprintf(log, "Player1 misses: %d\n", player[0].misses);
    fprintf(log, "Player2 misses: %d\n", player[1].misses);
    fprintf(log, "Player1 total shots: %d\n", player[0].shots);
    fprintf(log, "Player2 total shots: %d\n", player[1].shots);
    fprintf(log, "Player1 hit rate: %lf\n", player[0].hit_rate);
    fprintf(log, "Player2 hit rate: %lf\n", player[1].hit_rate);

    // closing file
    fclose(log);

  }
  return 0;
}
