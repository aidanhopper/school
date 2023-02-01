#include "header.h"
#include <stdio.h>
#include <string.h>

int is_target(char *target, char *current_patient) {
  for (int i = 0; i < 5; i++) {
    if (target[i] != current_patient[i]) {
      return 0;
    }
  }
  return 1;
}

int read_data(FitbitData data[]) {
  FILE *file = fopen("FitbitData.csv", "r");
  if (file == NULL) return 0;

  // getting target
  char thing[100];
  char target[10];
  fgets(thing, 100, file);
  strncpy(target, thing + 9, 5);

  char str[100];

  // skips first two lines of file
  fscanf(file, "%s", str);

  int data_index = 0;
  while (!feof(file)) {

    // delaring variables with default values
    char patient[10] = "";
    char minute[9] = "";
    double calories = 0xfffffffffffff;
    double distance = 0xfffffffffffff;
    unsigned int floors = 0xffffffff;
    unsigned int heartRate = 0xffffffff;
    unsigned int steps = 0xffffffff;
    Sleep sleeplevel = 0;
    char dupe = 0;

    fscanf(file, "%s", str);
    char *token;

    // reading patient ID
    token = strtok(str, ",");

    // get data and store into variables to do error checking
    if (is_target(target, token)) {
      // copying patient
      strcpy(patient, token);

      // reading minute
      token = strtok(NULL, ",");
      if (token != NULL)
        strcpy(minute, token);
      // check for duplicate
      if (token != NULL && strcmp(token, data[data_index - 1].minute) == 0)
      {
        dupe = 1;
      }

      // reading calories
      token = strtok(NULL, ",");
      if (token != NULL)
        sscanf(token, "%lf", &calories);

      // reading distance
      token = strtok(NULL, ",");
      if (token != NULL)
        sscanf(token, "%lf", &distance);

      // reading floors
      token = strtok(NULL, ",");
      if (token != NULL)
        sscanf(token, "%u", &floors);

      // reading heart rate
      token = strtok(NULL, ",");
      if (token != NULL)
        sscanf(token, "%u", &heartRate);

      // reading steps
      token = strtok(NULL, ",");
      if (token != NULL)
        sscanf(token, "%u", &steps);

      // reading sleeplevel
      token = strtok(NULL, ",");
      if (token != NULL)
        sscanf(token, "%u", &sleeplevel);

      if (!dupe)
      {
        // copying data
        strcpy(data[data_index].patient, patient);
        strcpy(data[data_index].minute, minute);
        data[data_index].calories = calories;
        data[data_index].distance = distance;
        data[data_index].floors = floors;
        data[data_index].heartRate = heartRate;
        data[data_index].steps = steps;
        data[data_index].sleeplevel = sleeplevel;

        data_index++;
      }
    }
  }
  fclose(file);
  return data_index - 1;
}

void print_fitbit_data(FitbitData *data) {
  printf("Patient    : %s\n", data->patient);
  printf("Minute     : %s\n", data->minute);
  printf("Calories   : %lf\n", data->calories);
  printf("Distance   : %lf\n", data->distance);
  printf("Floor      : %u\n", data->floors);
  printf("Heart Rate : %u\n", data->heartRate);
  printf("Steps      : %u\n", data->steps);
  printf("Sleep Level: %u\n\n", data->steps);
}

void parse_data(FitbitData data[], int len, Info *info)
{
  // setting init values
  info->total_calories = 0.0f;
  info->total_distance = 0.0f;
  info->total_floors = 0;
  info->total_steps = 0;
  info->max_steps = 0;
  info->average_heartrate = 0;
  for (int i = 0; i < len; i++)  
  {
    // checks if data is a placeholder and if not it does an addition operation
    if (data[i].calories != 0xfffffffffffff) info->total_calories += data[i].calories;
    if (data[i].distance != 0xfffffffffffff) info->total_distance += data[i].distance;
    if (data[i].floors != 0xffffffff) info->total_floors += data[i].floors;
    if (data[i].steps != 0xffffffff) info->total_steps += data[i].steps;
    if (data[i].heartRate != 0xffffffff) info->average_heartrate += data[i].heartRate;
    if (data[i].steps > info->max_steps && data[i].steps != 0xffffffff) info->max_steps = data[i].steps;
  }
  info->average_heartrate /= len + 1;
}

void longest_sleep_range(FitbitData data[], char str[], int len)
{
  char current_start_time[9];
  int current_range = 0;

  char longest_start_time[9];
  char longest_end_time[9];
  int longest_range = 0;

  for (int i = 0; i < len; i++)
  {
    // reset
    if (data[i].sleeplevel <= 1)
    {
      if (longest_range < current_range)
      {
        longest_range = current_range;
        strcpy(longest_start_time, current_start_time);
        strcpy(longest_end_time, data[i-1].minute);
      }
      current_range = 0;
      strcpy(current_start_time, data[i+1].minute);
    }

    // increment
    else if (data[i].sleeplevel > 1)
    {
      current_range += data[i].sleeplevel;
    }

  }
  // formatting data into tmp then copying it to str to send back to write data
  // function
  char tmp[17];
  sprintf(tmp, "%s:%s", longest_start_time, longest_end_time); 
  strcpy(str, tmp);
}

void write_data(FitbitData data[], int len, Info *info)
{
  // opens file
  FILE *file = fopen("Results.csv", "w");

  // writes a bunch of stuff to the file
  fprintf(file, "Total Calories,Total Distance,Total Floors,"
                "Total Steps,Avg Heartrate,Max Steps,Sleep\n");

  char str[17];
  longest_sleep_range(data, str, len);

  fprintf(file, "%lf,%lf,%u,%u,%lf,%s\n",
      info->total_calories,
      info->total_distance,
      info->total_floors,
      info->total_steps,
      info->average_heartrate,
      str
      );


  //fprintf(file, "Patient,minute,calories,distance,floors,heart,steps,sleep_level\n");

  // writing original data cleaned and deduped
  for (int i = 0; i < len; i++)
  {
    FitbitData *d = &data[i];

    fprintf(file,"%s,%s,", 
        d->patient, 
        d->minute);

    if (d->calories == 0) fprintf(file, "0,");
    else fprintf(file, "%.9lf,", d->calories);
    if (d->distance == 0) fprintf(file, "0,");
    else fprintf(file, "%.9lf,", d->distance);

    fprintf(file, "%u,%u,%u,%d\n", 
        d->floors, 
        d->heartRate, 
        d->steps, 
        d->sleeplevel);
        //d->calories,
        //d->distance,
        
        //d->floors,
        //d->heartRate,
        //d->steps,
        //d->sleeplevel);
  }

  fclose(file);
}
