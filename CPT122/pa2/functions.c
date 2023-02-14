#include "header.h"

int menu() {
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

void clear() { system("clear"); }

Record *move_by_record(Node *playlist) {
  static Node *node;
  if (playlist != NULL) {
    node = playlist;
  }

  Record *record = NULL;

  if (node != NULL) {
    record = &node->data;
    node = node->next;
  }
  return record;
}

Record *search_by_artist(Node *playlist, char *artist) {
  Record *record = move_by_record(playlist);
  while (record != NULL) {
    if (artist == NULL || strcmp(record->artist, artist) == 0) {
      return record;
    }
    record = move_by_record(NULL);
  }
  return NULL;
}

Record *search_for_song(Node *playlist, char *song_title)
{
  Record *record = move_by_record(playlist);
  while (record != NULL) {
    if (song_title == NULL || strcmp(record->song_title, song_title) == 0) {
      return record;
    }
    record = move_by_record(NULL);
  }
  return NULL;

}

void print_record(Record *data) {
  printf("Artist      : %s\n"
         "Album Title : %s\n"
         "Song Title  : %s\n"
         "Genre       : %s\n"
         "Duration    : %d:%d\n"
         "Times Played: %d\n"
         "Rating      : %d\n\n",
         data->artist, data->album_title, data->song_title, data->genre,
         data->duration.minutes, data->duration.seconds, data->times_played,
         data->rating);
}

void print_list(Node *node, char *artist) {
  Record *record = search_by_artist(node, artist);
  while (record != NULL) {
    print_record(record);
    record = search_by_artist(NULL, artist);
  }
}

void print_list_backwards(Node *node)
{
  // go to back of list
  while (node->next != NULL)
  {
    node = node->next;
  }
  int i = 1;
  while (node != NULL)
  {
    printf("%s<-",node->data.artist);
    node = node->prev;
  }
  printf("\n");

}

void print_list_small(Node *node)
{
  // go to back of list
  while (node != NULL)
  {
    printf("%s->",node->data.artist);
    node = node->next;
  }
  printf("\n");

}

void read_line(char line[], Record *record) {
  char *token;

  // two cases for reading the artist
  // 1. if the line starts with ", then read in the string
  //    up to the closing ", then strtok after
  // 2. if not then use strtok to read in the artist name
  if (line[0] == '\"') {
    char *c = line + 1;
    int len = 0;
    while (*c != '\"') {
      c = c + 1;
      len++;
    }
    // stops characters from doing weird shit
    for (int i = 0; i < 20; i++)
      record->artist[i] = '\0';
    strncpy(record->artist, line + 1, len);

    // incrementing the token
    token = strtok(line, ",");
    token = strtok(NULL, ",");
  } else {
    token = strtok(line, ",");
    strcpy(record->artist, token);
  }

  // reading album title
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
  sscanf(token + 2, "%d", &record->duration.seconds);

  // reading times played
  token = strtok(NULL, ",");
  sscanf(token, "%d", &record->times_played);

  // reading rating
  token = strtok(NULL, ",");
  sscanf(token, "%d", &record->rating);
}

Node *make_node(char *line) {
  Node *node = (Node *)malloc(sizeof(Node));
  read_line(line, &node->data);
  return node;
}

int insert_front(Node **playlist, char *line) {
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
    //printf("%s\n",(*playlist)->prev->data.artist);
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
  if (file == NULL)
    return;

  while (1)
  {
    // read in line
    char line[100];
    fgets(line, 100, file);
    if (feof(file))
      break;

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
  sprintf(tmp_str, "%s,%s,%s,%d:%d,%d,%d", data->album_title, data->song_title,
          data->genre, data->duration.minutes, data->duration.seconds,
          data->times_played, data->rating);

  strcat(line, tmp_str);
}

void store(Node **playlist) {
  // opening file
  char *file_path = "musicPlayList.csv";
  FILE *file = fopen(file_path, "w");

  // writing line to file
  Node *tmp = *playlist;
  int stack_index = 0;
  while (tmp != NULL) {
    char line[100];
    create_line(&tmp->data, line);
    fprintf(file, "%s\n", line);
    tmp = tmp->next;
  }
  fclose(file);
}

void display(Node **playlist) {

  printf("What would you like to display?\n"
         "(1) The entire list\n"
         "(2) Records from a specific artist\n");

  int option;
  scanf("%d%*c", &option);
  if (option == 1) {
    //print_list(*playlist, NULL);
    print_list(*playlist, NULL);
  } else if (option == 2) {
    char artist[20];
    printf("What artist would you like to search_by_artist for?\n");
    fgets(artist, 20, stdin);
    for (int i = 0; i < 20; i++)
      if (artist[i] == '\n')
        artist[i] = '\0';
    print_list(*playlist, artist);
  }
}

int edit_yes_or_no(char *str) {
  char input[20];
  printf("Would you like to change the %s? (y/n)\n", str);
  scanf("%s%*c", input);
  if (input[0] == 'y')
    return 1;
  return 0;
}

void new_str(char str[20]) {
  printf("Enter a new value: ");
  fgets(str, 20, stdin);
  for (int i = 0; i < 20; i++)
    if (str[i] == '\n')
      str[i] = '\0';
  printf("\n");
}

void edit(Node **playlist) {
  char artist[20];
  printf("What artist would you like to search_by_artist for?\n");
  fgets(artist, 20, stdin);
  for (int i = 0; i < 20; i++)
    if (artist[i] == '\n')
      artist[i] = '\0';
  Record *record = search_by_artist(*playlist, artist);
  int i = 0;
  while (record != NULL) {
    i++;
    printf("%d:%s, ", i, record->song_title);
    record = search_by_artist(NULL, artist);
  }

  int choise = 1;
  if (i == 0)
    return;
  if (i > 1) {
    printf("\nThere are %d records by this artist, "
           "which one would you like to edit between 1 and %d? \n",
           i, i);
    scanf("%d%*c", &choise);
  }

  record = search_by_artist(*playlist, artist);
  int k = 1;
  while (k != choise) {
    k++;
    record = search_by_artist(NULL, artist);
  }
  print_record(record);
  char str[20];

  int change = edit_yes_or_no("artist");
  if (change) {
    new_str(str);
    strcpy(record->artist, str);
  }

  change = edit_yes_or_no("album title");
  if (change) {
    new_str(str);
    strcpy(record->album_title, str);
  }

  change = edit_yes_or_no("song title");
  if (change) {
    new_str(str);
    strcpy(record->song_title, str);
  }

  change = edit_yes_or_no("genre");
  if (change) {
    new_str(str);
    strcpy(record->genre, str);
  }

  change = edit_yes_or_no("duration");
  if (change) {
    int num;
    printf("Enter a new value for minutes: ");
    scanf("%d", &num);
    record->duration.minutes = num;
    printf("\nEnter a new value for seconds: ");
    scanf("%d", &num);
    record->duration.seconds = num;
    printf("\n");
  }

  change = edit_yes_or_no("times played");
  if (change) {
    int num;
    printf("Enter a new value: ");
    scanf("%d", &num);
  }

  change = edit_yes_or_no("rating");
  if (change) {
    int num;
    printf("Enter a new value: ");
    scanf("%d", &num);
  }
  printf("New record\n"
         "----------\n");
  print_record(record);
}

void rate(Node **playlist) {
  char input[20];
  Record *record = move_by_record(*playlist);
  while (input[0] != 'y' && record != NULL) {
    print_record(record);
    printf("Rate this record? (y/n)\n");
    scanf("%s", input);
    if (input[0] != 'y')
      record = move_by_record(NULL);
  }
  if (input[0] == 'y') {
    int new_rating;
    printf("Enter a rating for this song: ");
    scanf("%d", &new_rating);
    record->rating = new_rating;
    printf("\n");
    print_record(record);
  }
}

void play(Node **playlist) {
  Record *record = move_by_record(*playlist);
  while (record != NULL) {
    clear();
    print_record(record);
    record->times_played++;
    sleep(1);
    record = move_by_record(NULL);
  }
  clear();
}

void insert(Node **playlist) 
{
  Node *node = malloc(sizeof(Node));
  char str[30];
  printf("Enter a artist: ");
  fgets(str, 20, stdin);
  for (int i = 0; i < 20; i++)
    if (str[i] == '\n')
      str[i] = '\0';
  strcpy(node->data.artist, str);

  printf("Enter a album title: ");
  fgets(str, 20, stdin);
  for (int i = 0; i < 20; i++)
    if (str[i] == '\n')
      str[i] = '\0';
  strcpy(node->data.album_title, str);

  printf("Enter a song title: ");
  fgets(str, 20, stdin);
  for (int i = 0; i < 20; i++)
    if (str[i] == '\n')
      str[i] = '\0';
  strcpy(node->data.song_title, str);
  
  printf("Enter a genre: ");
  fgets(str, 20, stdin);
  for (int i = 0; i < 20; i++)
    if (str[i] == '\n')
      str[i] = '\0';
  strcpy(node->data.genre, str);

  int num;
  printf("Enter duration minutes: ");
  scanf("%d%*c", &num);
  node->data.duration.minutes = num;
  printf("\nEnter duration seconds: ");
  scanf("%d%*c", &num);
  node->data.duration.seconds = num;

  printf("Enter times played: ");
  scanf("%d%*c", &num);
  node->data.times_played = num;

  printf("Enter rating: ");
  scanf("%d%*c", &num);
  node->data.rating = num;

  (*playlist)->prev = node;
  node->next = *playlist;
  node->prev = NULL;
  *playlist = node;
}

void delete(Node **playlist) 
{
  char song_title[30];
  fgets(song_title, 30, stdin);
  for (int i = 0; i < 30; i++)
    if (song_title[i] == '\n')
      song_title[i] = '\0';

  Node *node = *playlist;
  while (node != NULL && strcmp(node->data.song_title, song_title) != 0)
  {
    node = node->next;
  }

  if (node != NULL)
  {
    Node *prev = node->prev;
    Node *next = node->next;
    prev->next = next;
    next->prev = prev;
    free(node);
  }
}

int compare_strings(char *str1, char *str2)
{
  char str1_lower[30];
  strcpy(str1_lower, str1);
  char *c = str1_lower;
  while (*c != '\0')
  {
    *c = tolower(*c);
    c = c + 1;
  }

  char str2_lower[30];
  strcpy(str2_lower, str2);
  c = str2_lower;
  while (*c != '\0')
  {
    *c = tolower(*c);
    c = c + 1;
  }
  
  int i = 0;
  while (*(str1_lower + i) != '\0' && *(str2_lower + i) != '\0')
  {
    //printf("%c < %c\n",*(str2_lower + i), *(str1_lower + i));
    if (*(str2_lower + i) < *(str1_lower + i))
    {
     // printf("%c is less than %c\n",*(str2_lower + i), *(str1_lower + i));
      return 1;
    }

    if (*(str2_lower + i) > *(str1_lower + i))
    {
      //printf("%c is less than %c\n",*(str2_lower + i), *(str1_lower + i));
      return 0;
    }
    i++;
  }

  if (*(str1_lower + i) == '\0' && *(str2_lower + i) == '\0')
  {
    return 0;
  }

  if (*(str1_lower + i) == '\0')
  {
    return 0;
  }

  return 1;
  
}

void sort_by_artist(Node **playlist)
{
  // bubble sort
  Node *node = *playlist;
  int list_size = 0;
  while (node != NULL)
  {
    node = node->next;
    list_size++;
  }
  list_size--;

  //print_list_small(*playlist);
  int swap_happened = 1;
  while (swap_happened)
  {
    swap_happened = 0;
    node = *playlist;
    while (node != NULL && node->next != NULL)
    {
      // is str 2 is less than str1
      int swap = 0;
      swap = compare_strings(node->data.artist, node->next->data.artist);
      if (swap) 
      {
        swap_happened = 1;

        Node *tail = node->prev;
        Node *head = node->next->next;

        Node *back = node->next;
        Node *front = node;
        //printf("curNode %s nextNode %s \n", node->next->data.artist, node->data.artist);

        //printf("%d %s\n", swap, node->data.artist);

        front->prev = back;
        front->next = head;

        back->next = front;
        back->prev = tail;

        if (tail != NULL)
        {
          tail->next = back;
        }
        else 
        {
          *playlist = back;
        }

        if (head != NULL)
        {
          head->prev = front;
        }
      }
      //printf("-------------------------\n");
      //print_list_small(*playlist);
      node = node->next;
    }
    //printf("\nFULL LOOP\n");
  }

}

void sort_by_album_title(Node **playlist)
{
   // bubble sort
  Node *node = *playlist;
  int list_size = 0;
  while (node != NULL)
  {
    node = node->next;
    list_size++;
  }
  list_size--;

  //print_list_small(*playlist);
  int swap_happened = 1;
  while (swap_happened)
  {
    swap_happened = 0;
    node = *playlist;
    while (node != NULL && node->next != NULL)
    {
      // is str 2 is less than str1
      int swap = 0;
      swap = compare_strings(node->data.album_title, node->next->data.album_title);
      if (swap) 
      {
        swap_happened = 1;

        Node *tail = node->prev;
        Node *head = node->next->next;

        Node *back = node->next;
        Node *front = node;
        //printf("curNode %s nextNode %s \n", node->next->data.artist, node->data.artist);

        //printf("%d %s\n", swap, node->data.artist);

        front->prev = back;
        front->next = head;

        back->next = front;
        back->prev = tail;

        if (tail != NULL)
        {
          tail->next = back;
        }
        else 
        {
          *playlist = back;
        }

        if (head != NULL)
        {
          head->prev = front;
        }
      }
      //printf("-------------------------\n");
      //print_list_small(*playlist);
      node = node->next;
    }
    //printf("\nFULL LOOP\n");
  }

 // bubble sort
  

}
void sort_by_rating(Node **playlist)
{
  // use counting sort to link all nodes with the same rating together
  // in their respective buckets and then link the end and beginning of each
  // together
  Node *bucket_beg[5];
  for (int i = 0; i < 5; i++) bucket_beg[i] = NULL;
  Node *bucket_end[5];
  for (int i = 0; i < 5; i++) bucket_end[i] = NULL;

  Node *node = *playlist;
  while(node != NULL)
  {
    int index = node->data.rating - 1;

    Node *next_node = node->next;
    node->next = bucket_beg[index];
    node->prev = NULL;
    if (bucket_end[index] == NULL)
    {
      bucket_end[index] = node;
    }
    if (bucket_beg[index] != NULL)
    {
      bucket_beg[index]->prev = node;
    }
    bucket_beg[index] = node;
    node = next_node;
  }
  
  bucket_end[0]->next = bucket_beg[1]; 
  bucket_beg[1]->prev = bucket_end[0];

  bucket_end[1]->next = bucket_beg[2]; 
  bucket_beg[2]->prev = bucket_end[1];

  bucket_end[2]->next = bucket_beg[3]; 
  bucket_beg[3]->prev = bucket_end[2];

  bucket_end[3]->next = bucket_beg[4]; 
  bucket_beg[4]->prev = bucket_end[3];

  *playlist = bucket_beg[0];
}

void sort_by_times_played(Node **playlist)
{   // bubble sort
  Node *node = *playlist;
  int list_size = 0;
  while (node != NULL)
  {
    node = node->next;
    list_size++;
  }
  list_size--;

  //print_list_small(*playlist);
  int swap_happened = 1;
  while (swap_happened)
  {
    swap_happened = 0;
    node = *playlist;
    while (node != NULL && node->next != NULL)
    {
      // is str 2 is less than str1
      int swap = 0;
      if (node->data.times_played < node->next->data.times_played)
      {
        swap = 1;
      }
      if (swap) 
      {
        swap_happened = 1;

        Node *tail = node->prev;
        Node *head = node->next->next;

        Node *back = node->next;
        Node *front = node;
        //printf("curNode %s nextNode %s \n", node->next->data.artist, node->data.artist);

        //printf("%d %s\n", swap, node->data.artist);

        front->prev = back;
        front->next = head;

        back->next = front;
        back->prev = tail;

        if (tail != NULL)
        {
          tail->next = back;
        }
        else 
        {
          *playlist = back;
        }

        if (head != NULL)
        {
          head->prev = front;
        }
      }
      //printf("-------------------------\n");
      //print_list_small(*playlist);
      node = node->next;
    }
    //printf("\nFULL LOOP\n");
  }

 // bubble sort
  



}

void sort(Node **playlist) 
{
  int choise;
  printf("What sort method would you like to use?\n"
         "(1) Based on artist (A-Z)\n"
         "(2) Based on album title (A-Z)\n"
         "(3) Based on rating (1-5)\n"
         "(4) Based on times played (largest-smallest)\n");
  scanf("%d", &choise);
  switch (choise)
  {
    case 1: sort_by_artist(playlist);
            break;
    case 2: sort_by_album_title(playlist);
            break;
    case 3: sort_by_rating(playlist);
            break;
    case 4: sort_by_times_played(playlist);
            break;
  }
}

void shuffle(Node **playlist) 
{
  //count nodes in list
  int list_size = 0;
  Node *node = *playlist;
  while (node != NULL)
  {
    list_size++;
    node = node->next;
  }
  node = *playlist;

  Node *list_order[list_size]; 
  char played[list_size][30];
  int index = 0;

  int dir = 1;
  int random_number = rand() % list_size;
  while(index != list_size)
  {
    int random_number = rand() % list_size;    

    while (random_number != 0) {
      if (dir == 1 && node->next == NULL)
      {
        dir = 0;
      }

      if (dir == 0 && node->prev == NULL)
      {
        dir = 1;
      }

      if (dir == 1)
      {
        node = node->next;
      }

      if (dir == 0)
      {
        node = node->prev;
      }
      random_number--;
    }

    int been_played = 0;
    for (int i = 0; i < list_size; i++)
    {
      if (strcmp(node->data.song_title, played[i]) == 0) 
      {
        been_played = 1;
      }
    }

    if (!been_played)
    {
      strcpy(played[index++], node->data.song_title);
      clear();
      print_record(&node->data);
      node->data.times_played++;
      sleep(1);
    }
  }
  clear();
}

void execute_option(Node **playlist, int option_selected) {
  switch (option_selected) {
  case 1:
    load(playlist);
    break;
  case 2:
    store(playlist);
    break;
  case 3:
    display(playlist);
    break;
  case 4:
    insert(playlist);
    break;
  case 5:
    delete(playlist);
    break;
  case 6:
    edit(playlist);
    break;
  case 7:
    sort(playlist);
    break;
  case 8:
    rate(playlist);
    break;
  case 9:
    play(playlist);
    break;
  case 10:
    shuffle(playlist);
    break;
  }
}
