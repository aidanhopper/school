#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int seconds;
  int minutes;
} Duration;

typedef struct {
  char artist[20];
  char album_title[20];
  char song_title[20];
  char genre[20];
  Duration duration;
  int times_played;
  int rating;
} Record;

typedef struct node Node;

typedef struct node {
  Record data;
  Node *prev;
  Node *next;
} Node;

int menu();
void execute_option(Node **playlist, int option_selected);
