#ifndef DATA_H
#define DATA_H

#include "node.h"

class DataAnalysis {
private:
  BST mTreeSold;
  BST mTreePurchased;
  std::ifstream mCsvStream;
  void openFile();
  void readLine(std::string &line);
  void readFile();
  void insertIntoTree(int isSold);
  void insertIntoTree(int &isSold, std::string &type, int &units);
  void printAnalysis();

public:
  DataAnalysis();
  void runAnalysis();
};

#endif
