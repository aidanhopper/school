#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include "list.h"

class Menu {
private:
  void executeOption(int &option, List<Data> &list);
  void importCourselist(List<Data> &list);
  void loadMasterList(List<Data> &list);
  void storeMasterList(List<Data> &list);
  void markAbsences(List<Data> &list);

public:
  void run();
};

std::ostream &operator<<(std::ostream &input, Data &data);

void loadNodesFromFile(List<Data> &list, std::ifstream &file);

#endif
