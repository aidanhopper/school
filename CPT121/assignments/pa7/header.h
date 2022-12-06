#ifndef HEADER_H
#define HEADER_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
  int face;
  int suit;
} Card;

typedef struct {
  Card cards[5];
} Hand;

int menu();
void shuffle(int wDeck[][13]);
void deal(int wDeck[][13], const char *wFace[], const char *wSuit[], Card cards[], int cards_size);
void print_hand(Hand *hand, const char *wFace[], const char *wSuit[]);

#endif
