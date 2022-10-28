#include "header.h"
#include <stdio.h>

char print_menu() {
  printf("1. Game rules\n");
  printf("2. Start agame of Yahtzee\n");
  printf("3. Exit\n");
  int input;
  // credit:
  // https://stackoverflow.com/questions/30987538/getchar-not-working-in-c
  scanf("%d%*c", &input);
  return input;
}

void print_rules() {
  printf("The scorecard used for Yahtzee is composed of two sections. A upper "
         "section and a lower section. A total of thirteen boxes or thirteen "
         "scoring combinations are divided amongst the sections. The upper "
         "section consists of boxes that are scored by summing the value of "
         "the dice matching the faces of the box. If a player rolls four 3's, "
         "then the score placed in the 3's box is the sum of the dice which is "
         "12. Once a player has chosen to score a box, it may not be changed "
         "and the combination is no longer in play for future rounds. If the "
         "sum of the scores in the upper section is greater than or equal to "
         "63, then 35 more points are added to the players overall score as a "
         "bonus. The lower section contains a number of poker like "
         "combinations. See the table provided below:\n");
}

void roll(Roll *roll_info) {
  for (int i = 0; i < 5; i++)
    if (roll_info->map[i] == 0)
      roll_info->arr[i] = (rand() % 6) + 1;
}

void print_roll(Roll roll_info) {
  printf("Rolls : ");
  for (int i = 0; i < 5; i++)
    printf("%d ", roll_info.arr[i]);
  printf("\n");
}

void print_combos() {
  printf("1. Sum of 1's        7. Three-of-a-kind\n"
         "2. Sum of 2's        8. Four-of-a-kind\n"
         "3. Sum of 3's        9. Full house\n"
         "4. Sum of 4's        10. Small straight\n"
         "5. Sum of 5's        11. Large straight\n"
         "6. Sum of 6's        12. Yahtzee\n"
         "13. Chance\n");
}

void init_player(Player *player) {
  player->points = 0;
  for (int i = 0; i < 12; i++)
    player->map[i] = 0;
}

char use_combo(int total_rolls) {
  if (total_rolls < 3) {
    printf("Would you like to use the roll for one of these combinations?\n");
    print_combos();
    printf("(Y/N)\n");
    char input;
    while (input != 'N' && input != 'n' && input != 'Y' && input != 'y')
      scanf("%c%*c", &input);
    if (input == 'N' || input == 'n')
      return 0;
    printf("Select a combinaion\n");
  } else {
    printf("Select a combination\n");
    print_combos();
  }
  int input = -1;
  while (input != 1 && input != 2 && input != 3 && input != 4 && input != 5 &&
         input != 6 && input != 7 && input != 8 && input != 9 && input != 10 &&
         input != 11 && input != 12)
    scanf("%d%*c", &input);
  return input;
}

void init_roll(Roll *roll_info) {
  for (int i = 0; i < 5; i++)
    roll_info->map[i] = 0;
}
