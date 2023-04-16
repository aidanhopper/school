#include "node.h"

int main() {
  BST sold = BST();
  BST purchased = BST();
  std::string line;

  std::ifstream file("./data.csv");
  std::getline(file, line);
  while(std::getline(file, line)) {
    char del = ',';
    std::string strunits;
    std::string type;
    int soldItem = 0;
    int commas = 0;
    for (int i = 0; i < line.length(); i++) {
      if (commas == 0 && line[i] != del) {
        strunits += line[i];
      } 
      else if (commas == 1) {
        type += line[i];
      }
      else if (commas == 2) {
        if (line[i] == 'S') soldItem = 1;
        commas++;
      }
      else {
        commas++;
      }
    }
    int units = std::stoi(strunits);
    purchased.insert(type, units);
    /*
    if (soldItem) {
      sold.insert(type, units);
    }
    else {
      purchased.insert(type, units);
    }
    */
  }
  file.close();

  purchased.inOrderTraversal();
}
