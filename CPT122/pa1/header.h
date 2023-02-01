#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// defines sleep levels
typedef enum sleep
{
  NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

// struct to store fitbit data
typedef struct fitbit
{
  char patient[10];
  char minute[9];
  double calories;
  double distance;
  unsigned int floors;
  unsigned int heartRate;
  unsigned int steps;
  Sleep sleeplevel;
} FitbitData;

// stores data calculated from input data
typedef struct info
{
  double total_calories;
  double total_distance;
  unsigned int total_floors;
  unsigned int total_steps;
  double average_heartrate;
  unsigned int max_steps;
} Info;

// reads data from fitbit csv file
// pre: array of fitbit data
// post: returns the length of the array
int read_data(FitbitData data[]);

// prints the FitbitData struct
// pre: FitbitData struct
// post: nothing
void print_fitbit_data(FitbitData *data);

// parses data calculating stuff
// pre: data array, length of data array, and info struct
// post: nothing
void parse_data(FitbitData data[], int len, Info *info);

// writes data to Results csv file
// pre: data struct, length of data struct, and info struct
// post: nothing
void write_data(FitbitData data[], int len, Info *info);
