#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <time.h>

typedef struct {
  int seconds;
  int minutes;
} Duration;

typedef struct {
  char artist[30];
  char album_title[30];
  char song_title[30];
  char genre[30];
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
void store(Node **playlist);
int compare_strings(char *str1, char *str2);
void load(Node **playlist);
void shuffle(Node **playlist);
void insert(Node **playlist);
void test_shuffle();
void delete(Node **playlist);
void test_insert();
void test_delete();
