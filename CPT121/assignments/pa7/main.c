#include "header.h"

int main() {

  // suits
  const char *suit[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};

  // faces
  const char *face[13] = {"Ace",  "Deuce", "Three", "Four", "Five",
			  "Six",  "Seven", "Eight", "Nine", "Ten",
			  "Jack", "Queen", "King"};

  int deck[4][13] = {0};

  srand(time(NULL));

  shuffle(deck);

  Hand hand1;

  deal(deck, face, suit, hand1.cards, 5);
  print_hand(&hand1, face, suit);
  return 0;
}
