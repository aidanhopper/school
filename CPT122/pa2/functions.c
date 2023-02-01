#include "header.h"
#include <stdio.h>
#include <stdlib.h>

int menu()
{
  printf("(1)  load\n"
         "(2)  store\n"
         "(3)  display\n"
         "(4)  insert\n"
         "(5)  delete\n"
         "(6)  edit\n"
         "(7)  sort\n"
         "(8)  rate\n"
         "(9)  play\n"
         "(10) shuffle\n"
         "(11) exit\n");
  int option_selected;
  scanf("%d%*c", &option_selected);
  return option_selected;
}

void print_record(Record *data) 
{
    printf("Artist      : %s\n"
           "Album Title : %s\n"
           "Song Title  : %s\n"
           "Genre       : %s\n"
           "Duration    : %d:%d\n"
           "Times Played: %d\n"
           "Rating      : %d\n\n",
           data->artist,
           data->album_title,
           data->song_title,
           data->genre,
           data->duration.minutes, data->duration.seconds,
           data->times_played,
           data->rating);
}

void print_list(Node *node, char *artist)
{
  if (artist == NULL)
  {
    while (node != NULL)
    {
      print_record(&node->data);
      node = node->next;
    }
  }
  else 
  {
    while (node != NULL)
    {
      if (strcmp(artist, node->data.artist) == 0)
      {
        print_record(&node->data);
      }
      node = node->next;
    }
  }
}

void read_line(char line[], Record *record)
{
  char *token;

  // two cases for reading the artist
  // 1. if the line starts with ", then read in the string
  //    up to the closing ", then strtok after
  // 2. if not then use strtok to read in the artist name
  if (line[0] == '\"')
  {
    char *c = line + 1;
    int len = 0;
    while(*c != '\"')
    {
      c = c + 1;
      len++;
    }
    // stops characters from doing weird shit
    for (int i = 0; i < 20; i++) record->artist[i] = '\0';
    strncpy(record->artist, line + 1, len);

    // incrementing the token 
    token = strtok(line, ",");
    token = strtok(NULL, ",");
  }
  else
  {
    token = strtok(line, ",");
    strcpy(record->artist, token); 
  }

  // reading albumn title
  token = strtok(NULL, ",");
  strcpy(record->album_title, token);

  // reading song title
  token = strtok(NULL, ",");
  strcpy(record->song_title, token);

  // reading genre
  token = strtok(NULL, ",");
  strcpy(record->genre, token);
  
  // reading song length
  token = strtok(NULL, ",");
  token[1] = '\0';
  sscanf(token, "%d", &record->duration.minutes);
  sscanf(token+2, "%d", &record->duration.seconds);

  // reading times played
  token = strtok(NULL, ",");
  sscanf(token, "%d", &record->times_played);

  // reading rating
  token = strtok(NULL, ",");
  sscanf(token, "%d", &record->rating);
}

Node *make_node(char *line)
{
    Node *node = (Node *) malloc(sizeof(Node));
    read_line(line, &node->data);
    return node;
}

int insert_front(Node **playlist, char *line)
{
  Node *node = make_node(line);
  if (node == NULL)
  {
    return 0;
  }
  if (*playlist == NULL)
  {
    node->next = NULL;
    node->prev = NULL;
    *playlist = node;
  }
  else 
  {
    node->next = *playlist;
    (*playlist)->prev = node;
    node->prev = NULL;
    *playlist = node;
  }
  return 1;
}

void load(Node **playlist) 
{
  // open file
  char *file_path = "musicPlayList.csv";
  FILE *file = fopen(file_path, "r");
  if (file == NULL) return;

  while (1)
  {
    // read in line
    char line[100];
    fgets(line, 100, file);
    if (feof(file)) break;

    // inserts the content of the line into
    // the front of the linked list
    insert_front(playlist, line);
  }
   
  fclose(file);
}

int str_contains_char(char *str, const char ch)
{
  char *c = str;
  while (*c != '\0')
  {
    if (*c == ch)
    {
      return 1;
    }
    c = c + 1;
  }
  return 0;
}

void create_line(Record *data, char *line)
{
  int artist_has_space = str_contains_char(data->artist, ' ');
  // check for space in artist name
  if (artist_has_space)
  {
    sprintf(line, "\"%s\",", data->artist);
  }
  else 
  {
    sprintf(line, "%s,", data->artist);
  }

  char tmp_str[100];
  sprintf(tmp_str, "%s,%s,%s,%d:%d,%d,%d",
      data->album_title,
      data->song_title,
      data->genre,
      data->duration.minutes,
      data->duration.seconds,
      data->times_played,
      data->rating);

  strcat(line, tmp_str);
}

void store(Node **playlist)
{
  // opening file
  char *file_path = "musicPlayList.csv";
  FILE *file = fopen(file_path, "w");

  // writing line to file
  Node *tmp = *playlist;
  int stack_index = 0;
  while (tmp != NULL)
  {
    char line[100];
    create_line(&tmp->data, line);
    fprintf(file, "%s\n", line);
    tmp = tmp->next;
  }
  fclose(file);
}

void display(Node **playlist)
{

  printf("What would you like to display?\n"
         "(1) The entire list\n"
         "(2) Records from a specific artist\n");

  int option;
  scanf("%d%*c", &option);
  if (option == 1)
  {
    print_list(*playlist, NULL);
  }
  else if (option == 2)
  {
    char artist[20];
    printf("What artist would you like to search for?\n");
    fgets(artist, 20, stdin);
    for (int i = 0; i < 20; i++) if (artist[i] == '\n') artist[i] = '\0';
    print_list(*playlist, artist);
  }
}

void edit(Node **playlist) 
{
  
}

void insert() {}
void delete() {}
void sort() {}
void rate() {}
void play() {}
void shuffle() {}

void execute_option(Node **playlist, int option_selected)
{
  switch (option_selected) {
    case 1:  load(playlist);
             break;
    case 2:  store(playlist);
             break;
    case 3:  display(playlist);
             break;
    case 4:  insert();
             break;
    case 5:  delete();
             break;
    case 6:  edit(playlist);
             break;
    case 7:  sort();
             break;
    case 8:  rate();
             break;
    case 9:  play();
             break;
    case 10: shuffle();
             break;
  }
}


