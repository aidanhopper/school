#include "header.h"

void test_insert()
{
  Node *playlist = NULL; 
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);


  Node *node = playlist;
  while (node != NULL)
  {
    int song_title_len = strlen(node->data.song_title);
    int rand_char = (rand() % 26) + 48;
    int rand_index = rand() % song_title_len;
    node->data.song_title[rand_index] = rand_char;
    node = node->next;
  }

  
  delete(&playlist);
  
}

void test_delete()
{
  Node *playlist = NULL; 
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);


  Node *node = playlist;
  while (node != NULL)
  {
    int song_title_len = strlen(node->data.song_title);
    int rand_char = (rand() % 26) + 48;
    int rand_index = rand() % song_title_len;
    node->data.song_title[rand_index] = rand_char;
    node = node->next;
  }

  
  delete(&playlist);
  
}

void test_shuffle() 
{
  Node *playlist = NULL; 
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);
  load(&playlist);


  Node *node = playlist;
  while (node != NULL)
  {
    int song_title_len = strlen(node->data.song_title);
    int rand_char = (rand() % 26) + 48;
    int rand_index = rand() % song_title_len;
    node->data.song_title[rand_index] = rand_char;
    node = node->next;
  }
  
  shuffle(&playlist);
}
