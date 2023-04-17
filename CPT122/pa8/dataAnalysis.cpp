#include "dataAnalysis.h"

DataAnalysis::DataAnalysis() {
  this->mTreePurchased = BST();
  this->mTreeSold = BST();
}

void DataAnalysis::openFile() { this->mCsvStream.open("./data.csv"); }

void DataAnalysis::readFile() {
  std::string line;
  std::getline(this->mCsvStream, line);
  while (std::getline(this->mCsvStream, line))
    this->readLine(line);
  std::cout << "Purchased Tree" << std::endl;
  this->mTreePurchased.inOrderTraversal();
  std::cout << "Sold Tree" << std::endl;
  this->mTreeSold.inOrderTraversal();
}

void DataAnalysis::readLine(std::string &line) {
  char del = ',';
  std::string strunits;
  std::string type;
  int soldItem = 0;
  int commas = 0;
  for (int i = 0; i < line.length(); i++) {
    if (commas == 0 && line[i] != del) {
      strunits += line[i];
    } else if (commas == 1 && line[i] != del) {
      type += line[i];
    } else if (line[i] == 'S')
      soldItem = 1;
    else {
      commas++;
    }
  }
  int units = std::stoi(strunits);
  this->insertIntoTree(soldItem, type, units);
}

void DataAnalysis::insertIntoTree(int &isSold, std::string &type, int &units) {
  if (isSold) {
    this->mTreeSold.insert(type, units);
  } else {
    this->mTreePurchased.insert(type, units);
  }
}

void DataAnalysis::printAnalysis() {
  TransactionNode leastPurchased = mTreePurchased.findSmallest();
  TransactionNode leastSold = mTreeSold.findSmallest();
  TransactionNode mostPurchased = mTreePurchased.findLargest();
  TransactionNode mostSold = mTreeSold.findLargest();

  std::cout << "Least Purchased ";
  leastPurchased.printData();

  std::cout << "Least Sold ";
  leastSold.printData();

  std::cout << "Most Purchased ";
  mostPurchased.printData();

  std::cout << "Most Sold ";
  mostSold.printData();
}

void DataAnalysis::runAnalysis() {
  openFile();
  readFile();
  printAnalysis();
  this->mCsvStream.close();
}
