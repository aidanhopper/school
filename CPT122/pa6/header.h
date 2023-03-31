#ifndef HEADER_H
#define HEADER_H

#include <iostream>

class BSTNode {
private:
  char c;
  std::string code;
  BSTNode *left;
  BSTNode *right;

public:
  BSTNode(const char c, const char* code);
  BSTNode *getLeft();
  BSTNode *getRight();
  void setLeft(BSTNode *left);
  void setRight(BSTNode *left);
  
};

#endif
