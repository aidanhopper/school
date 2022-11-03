#include "header.h"
#include <stdio.h>
#include <stdlib.h>

void clear() {
  system("clear");
}

char menu() {
  printf("\nGAME MENU\n------------------\n");
  printf("1. Game rules\n");
  printf("2. Start a game of Yahtzee\n");
  printf("3. Exit\n");
  int input;

  // credit: https://stackoverflow.com/questions/30987538/getchar-not-working-in-c
  scanf("%d%*c", &input);
  return input;
}

void print_rules() {
  clear();
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
         "combinations. See the table provided below:\n\n");

  printf("+-----------------+--------------------------------------+--------------------------------------+\n"
         "| Name            | Combination                          | Score                                |\n"
	 "+-----------------+--------------------------------------+--------------------------------------+\n"
	 "| Three-of-a-kind | Three dice with the same face        | Sum of all face values on the 5 dice |\n"
	 "| Four-of-a-kind  | Four dice with the same face         | Sum of all face values on the 5 dice |\n"
	 "| Full house      | One pair and a three-of-a kind       | 25                                   |\n"
	 "| Small straight  | A sequence of four dice              | 30                                   |\n"
	 "| Large straight  | A sequence of five dice              | 40                                   |\n"
	 "| Yahtzee         | Five dice with the same face         | 50                                   |\n"
	 "| Chance          | May be used for any sequence of dice | Sum of all face values on the 5 dice |\n"
	 "+-----------------+--------------------------------------+--------------------------------------+\n");
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
  player->upper = 0;
  for (int i = 0; i < 12; i++)
    player->map[i] = 0;
}

char get_combo(Player *player, int total_rolls) {
  if (total_rolls < 3) {
    printf("Would you like to use the roll for one of these combinations?\n");
    print_combos();
    printf("(Y/N)\n");
    char input = '0';
    while (input != 'N' && input != 'n' && input != 'Y' && input != 'y') 
      scanf("%c", &input);
    if (input == 'N' || input == 'n')
      return 0;
    printf("Select a combination (1-13)\n");
  } else {
    printf("Select a combination (1-13)\n");
    print_combos();
  }
  int input = -1;
  while (input > 13 || input < 1 || player->map[input - 1] == 1) {
    scanf("%d%*c", &input);
    if (!(input > 13 || input < 1) && player->map[input - 1] == 1)
      printf("This combo has already been used. Try another!\n");
    else if(input > 13 || input < 1)
      printf("Not a valid input!\n");
  }
  return input;
}

void use_combo(Player *player, Roll roll, int combo) {
  player->map[combo - 1] = 1;
  int points = 0;
  switch (combo) {
  case 1:;
  case 2:;
  case 3:;
  case 4:;
  case 5:;
  case 6:
    points = sum_of_num(roll, combo);
    player->upper += points;
    break;
  case 7:
    points = three_of_a_kind(roll);
    break;
  case 8:
    points = four_of_a_kind(roll);
    break;
  case 9:
    points = full_house(roll);
    break;
  case 10:
    points = small_straight(roll);
    break;
  case 11:
    points = large_straight(roll);
    break;
  case 12:
    points = yahtzee(roll);
    break;
  case 13:
    points = chance(roll);
  }

  player->points += points;

}

void init_roll(Roll *roll_info) {
  for (int i = 0; i < 5; i++)
    roll_info->map[i] = 0;
}

int sum_of_num(Roll roll, int num) {
  int sum = 0;
  int map[6] = {0};
  for (int i = 0; i < 6; i++)
    map[roll.arr[i] - 1]++;
  for (int i = 0; i < 6; i++)
    if (roll.arr[i] == num)
      sum += num;
  return sum;
}

int three_of_a_kind(Roll roll) {
  int map[6] = {0};
  int sum = 0;

  for (int i = 0; i < 6; i++) {
    map[roll.arr[i] - 1]++;
    sum += roll.arr[i];
  }

  for (int i = 0; i < 6; i++)
    if (map[i] >= 3)
      return sum;
      
  return 0;
}

int four_of_a_kind(Roll roll) {
  int map[6] = {0};
  int sum = 0;

  for (int i = 0; i < 6; i++) {
    map[roll.arr[i] - 1]++;
    sum += roll.arr[i];
  }

  for (int i = 0; i < 6; i++)
    if (map[i] >= 4)
      return sum;
      
  return 0;
}

int full_house(Roll roll) {
  int map[6] = {0};

  // counting frequency of faces
  for (int i = 0; i < 5; i++)
    map[roll.arr[i] - 1]+=1;

  // checking for pair
  char pair = 0;
  for (int i = 0; i < 6; i++)
    if (map[i] == 2)
      pair = 1;

  // checking for three of a kind  
  char three = 0;
  for (int i = 0; i < 6; i++)
    if (map[i] == 3)
      three = 1;

  printf("map = { ");
  for (int i = 0; i < 6; i++)
    printf("%d:%d ", i+1, map[i]);
  printf("}\n");

  if (pair && three)
    return 25;
  return 0;
}

int small_straight(Roll roll) {
  int next = roll.arr[0] + 1;
  int len = 1;
  for (int i = 1; i < 5; i++) {
    if (roll.arr[i] != next) {
      next = roll.arr[i] + 1;
      len = 1;
    }
    else {
      len++;
      next++;
    }
    if (len == 4)
      return 30;
  }
  return 0;
}

int large_straight(Roll roll) {
  int next = roll.arr[0] + 1;
  int len = 1;
  for (int i = 1; i < 5; i++) {
    if (roll.arr[i] != next) {
      next = roll.arr[i] + 1;
      len = 1;
    }
    else {
      len++;
      next++;
    }
    if (len == 5)
      return 40;
  }
  return 0;
}

int yahtzee(Roll roll) {
  for (int i = 0; i < 5; i++)
    if (roll.arr[0] != roll.arr[i])
      return 0;
  return 50;
}

int chance(Roll roll) {
  int sum = 0;
  for (int i = 0; i < 5; i++)
    sum += roll.arr[i];
  return sum;
}

void update_roll_map(Roll *roll) {
  printf("Enter the dice to reroll, 1 to keep 0 to reroll (ex: 0 1 1 0 1)\n");
  int arr[5];
  scanf("%d%d%d%d%d", &arr[0], &arr[1], &arr[2], &arr[3], &arr[4]);
  for (int i = 0; i < 5; i++) {
    roll->map[i] = 0;
    if (arr[i] != 0)
      roll->map[i] = 1;
  }
}
