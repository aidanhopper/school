#include "menu.h"
#include "list.h"

void Menu::run() {
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
    this->executeOption(option);
  }
}

void Menu::executeOption(int &option) {
  switch (option) {
  case 1:
    this->importCourselist();
    break;
  }
}

void Menu::importCourselist() {
  std::ifstream classlistFile("./classlist.csv");

  List<Data> list = List<Data>();

  std::string line;
  std::getline(classlistFile, line);
  while (std::getline(classlistFile, line)) {
    std::cout << line << std::endl;
  }

  classlistFile.close();
}
