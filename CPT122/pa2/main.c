#include "header.h"

int main()
{
  srand(time(NULL));

  Node *playlist = NULL;

  while(1)
  {
    // displays the menu
    int option_selected = menu();
    
    // exit the program
    if (option_selected == 11)
    {
      store(&playlist);
      return 0;
    }
  
    // if not exit then execute the option
    execute_option(&playlist, option_selected);
  }

}
