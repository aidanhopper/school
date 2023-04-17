#ifndef DATA_H
#define DATA_H

#include "node.h"

class DataAnalysis {
private:
  BST mTreeSold;
  BST mTreePurchased;
  std::ifstream mCsvStream;

public:
  void openFile();
  void readLine();
  void readFile();
  void insertIntoTree();
  void printAnalysis();
  void runAnalysis();

};

#endif
