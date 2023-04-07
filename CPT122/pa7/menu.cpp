#include "menu.h"

std::ostream &operator<<(std::ostream &input, Data &data) {

  input << data.record << "," << data.id << "," << "\"" << data.name << "\"" << ","
        << data.email << "," << data.units << "," << data.program << ","
        << data.level;
  return input;
}

void Menu::run() {
  List<Data> list;
  while (1) {
    int option;
    std::cout << "1. Import course list" << std::endl
              << "2. Load master list" << std::endl
              << "3. Store master list" << std::endl
              << "4. Mark absences" << std::endl
              << "5. Edit absences" << std::endl
              << "6. Generate report" << std::endl
              << "7. Exit" << std::endl;
    std::cin >> option;
    if (option == 7)
      break;
    this->executeOption(option, list);
  }
}

void Menu::executeOption(int &option, List<Data> &list) {
  switch (option) {
  case 1:
    this->importCourselist(list);
    break;
  case 2:
    this->loadMasterList(list);
    break;
  case 3:
    this->storeMasterList(list);
  }
}


void Menu::storeMasterList(List<Data> &list) {
  std::ofstream masterlistFile("./master.csv");
  masterlistFile << "record number,ID number,name,email,units,program,level" << std::endl;
  list.write(masterlistFile);
}

void loadNodesFromFile(List<Data> &list, std::ifstream &file) {
  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    if (line == "") break;
    //std::cout << line << std::endl;
    std::string tmp = "";
    char del = ',';
    int j = 0;
    Data data;
    for (int i = 0; i < line.length(); i++) {
      if (line[i] != del && line[i] != '\"') {
        tmp += line[i];
      } 
      else if (line[i] == '\"') {
        int k = i + 1;
        while(line[k] != '\"') {
          tmp += line[k];
          k++;
        }
        i = k;
      }
      else {
        switch (j) {
          // record
          case 0:
            data.record = std::stoi(tmp);
            break;
          // id
          case 1:
            data.id = std::stoi(tmp);
            break;
          // name
          case 2:
            data.name = tmp;
            break;
          // email
          case 3:
            data.email = tmp;
            break;
          // units
          case 4:
            data.units = std::stoi(tmp);
            break;
          // program
          case 5:
            data.program = tmp;
            break;
        }
        j++;
        tmp = "";
      }
    }
    // level
    data.level = tmp;
    list.insert(data);
  }
  list.print();
}

void Menu::loadMasterList(List<Data> &list) {
  std::ifstream masterlistFile("./master.csv");
  loadNodesFromFile(list, masterlistFile);
}

void Menu::markAbsences(List<Data> &list) {
  ListNode<Data> *node = list.getHead();
}

void Menu::importCourselist(List<Data> &list) {
  list.~List();
  std::ifstream file("./classlist.csv");

  loadNodesFromFile(list, file);

  file.close();
}
