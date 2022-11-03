/*

    Name: Aidan Hopper
    Date: 10/28/2022
    Class: CPTS 121 Section 1
    Description: 5th programming assignment

*/

#include "header.h"

int main() {

  // seeding rand
  srand(time(NULL));

  // menu loop
  int run = 1;
  while (run) {

    // gets option from user
    int option = menu();
    clear();

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
      Player player[] = {player1, player2};

      char game_finished = 0;
      int total_turns = 0;
      int round_number = 0;
while (!game_finished) {

        Roll roll_info;
        init_roll(&roll_info);
        char turn_finished = 0;
        // hit any key to continue
        printf("Player %d hit any key to continue to roll the dice\n",
               total_turns % 2 + 1);
        getchar();

        // rolls dice
        roll(&roll_info);
        int total_rolls = 1;

        // turn loop
        while (!turn_finished) {

          print_roll(roll_info);

          // gets combination from player
          char combo = get_combo(&player[total_turns % 2], total_rolls);

          // checks that user said yes to combination
          // and adds combo to map
          if (combo != 0) {
            use_combo(&player[total_turns % 2], roll_info, combo);
            turn_finished = 1;
          }

          // reroll
          else {
            update_roll_map(&roll_info);
            roll(&roll_info);
            total_rolls++;
          }
          clear();
        }

        printf("Player 1 points: %d | Player 2 points: %d\n", player[0].points,
               player[1].points);
        total_turns++;
	round_number = total_turns/2;

        if (round_number == 14) {
          // count if upper score card is greater than 65 for both players
          if (player[0].upper >= 63)
            player[0].points += 35;

          if (player[1].upper >= 63)
            player[1].points += 35;

          // select the winner based on who has the most points or if tie
          int winner = (player[0].points > player[1].points) ? 0 : 1;
          if (player[0].points == player[1].points)
            winner = 2;

          // print out winner
          if (winner == 0)
            printf("PLAYER 1 WINS!!\n");
          else if (winner == 1)
            printf("PLAYER 2 WINS!!\n");
          else
            printf("TIE!!\n");

          // end the game
          game_finished = 1;
        }
      }
    }

    // exits program if 3 is selected
    else if (option == 3) {
      printf("GOODBYE!!\n");
      run = 0;
    }
  }

  // program ran successfully
  return 0;
}
