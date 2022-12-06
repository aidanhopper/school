#include "header.h"

int menu()
{
  printf("1. play the game\n"
         "2. show the rules\n"
         "3. exit the game\n");
  int input;
  do
    scanf("%d", &input);
  while (input != 1 && input != 2 && input != 3);
  return input;
}

void shuffle(int wDeck[][13])
{
  int row = 0;    /* row number */
  int column = 0; /*column number */
  int card = 0;   /* card counter */

  /* for each of the 52 cards, choose slot of deck randomly */
  for (card = 1; card <= 52; card++)
  {
    /* choose new random location until unoccupied slot found */
    do
    {
      row = rand() % 4;
      column = rand() % 13;
    } while (wDeck[row][column] != 0);

    /* place card number in chosen slot of deck */
    wDeck[row][column] = card;
  }
}

/* deal cards in deck */
void deal(int wDeck[][13], const char *wFace[], const char *wSuit[], Card cards[], int cards_size)
{
  int row = 0;    /* row number */
  int column = 0; /*column number */
  int card = 0;   /* card counter */
  int cards_delt = 0;
  

  /* deal each of the 52 cards */
  for (card = 1; card <= 52; card++)
  {
    /* loop through rows of wDeck */
    for (row = 0; row <= 3; row++)
    {
      /* loop through columns of wDeck for current row */
      for (column = 0; column <= 12; column++)
      {
        if (wDeck[row][column] == card)
        {
          cards[cards_delt].suit = row;
          cards[cards_delt++].face = column;
          wDeck[row][column] = 0;
          if (cards_delt == cards_size)
            return;
        }
      }
    }
  }
}

void print_hand(Hand *hand, const char *wFace[], const char *wSuit[])
{
  for (int i = 0; i < 5; i++)
  {
    printf("%s of %s\n", wFace[hand->cards[i].face], wSuit[hand->cards[i].suit]);
  }
}

int check_pair(Hand *hand)
{
  for (int suit = 0; suit < 4; suit++)
  {
    int count = 0;
    for (int card = 0; card < 5; card++) {
      if (hand->cards[card].suit == suit)
        count++;
    }
    if (count == 2)
      return 1;
  }
  return 0;
}

int check_two_pairs(Hand *hand)
{
  int pairs = 0;
  int used_pair = -1;
  for (int suit = 0; suit < 4; suit++)
  {
    int count = 0;
    for (int card = 0; card < 5; card++)
    {
      if (hand->cards[card].suit == suit && suit != used_pair)
      {
        count++;
        used_pair = suit;
      }
    }
    if (count == 2)
    {
      pairs++;
    }
    if (pairs == 2)
    {
      return 1;
    }
  }
  return 0;
}

int check_three_of_a_kind(Hand *hand)
{
  for (int card = 0; card < 5; card++)
  {
    int count = 0;
    int face = hand->cards[card].face;
    for (int i = 0; i < 5; i++)
    {
      if (hand->cards[i].face == face && i != card)
      {
        count++;
      }
    }
    if (count == 3)
    {
      return 1;
    }
  }
  return 0;
}

int check_four_of_a_kind(Hand *hand)
{
  for (int card = 0; card < 5; card++)
  {
    int count = 0;
    int face = hand->cards[card].face;
    for (int i = 0; i < 5; i++)
    {
      if (hand->cards[i].face == face && i != card)
      {
        count++;
      }
    }
    if (count == 4)
    {
      return 1;
    }
  }
  return 0;
}

int check_full_house(Hand *hand)
{

  return 0;
}