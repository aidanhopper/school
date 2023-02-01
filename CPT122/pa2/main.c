#include "header.h"

int main()
{
  Node *playlist;
  while(1)
  {
    // displays the menu
    int option_selected = menu();
    
    // exit the program
    if (option_selected == 11)
    {
      return 0;
    }
  
    // if not exit then execute the option
    execute_option(&playlist, option_selected);
    //rintf("%s\n", playlist->next->next->next->prev->data.artist);
    //printf("%s\n", playlist->data.artist);
  }
}
