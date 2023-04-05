#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <string>

class Menu {
private:
  void executeOption(int &option);
  void importCourselist();

public:
  void run();
};

#endif
