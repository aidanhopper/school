#include "header.h"

int main() {

  // player 1
  Player player1;
  init_player(&player1);

  // player 2
  Player player2;
  init_player(&player2);

  welcome_screen();
  clear();
  char method = place_method();

  return 0;
}
