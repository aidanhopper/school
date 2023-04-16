#ifndef NODE_H
#define NODE_H

#include <string>
#include <iostream>

class Node {
private:
  Node *mpLeft;
  Node *mpRight;

protected:
  std::string mData;

public:
  Node(std::string &mData);
  ~Node();
  Node *&getLeft();
  Node *&getRight();
  std::string &getData();
  void setLeft(Node *&mpLeft);
  void setRight(Node *&mpRight);
  void setData(std::string &mData);
  virtual void printData();
};

class TransactionNode : public Node {
private:
  int mUnits;

public:
  TransactionNode(std::string &mData, int &mUnits);
  ~TransactionNode();
  int getUnits();
  void setUnits(int mUnits);
  void printData();
};

class BST {
private:
  Node *mpRoot;
  void destroyTree();
  void insert(Node *&node, std::string &mData, int &mUnits);
  void inOrderTraversal(Node *&node);

public:
  BST();
  ~BST();
  Node *&getRoot();
  void setRoot(Node *&mpRoot);
  void insert(std::string &mData, int &mUnits);
  void inOrderTraversal();
  TransactionNode &findSmallest();
  TransactionNode &findLargest();
};

class DataAnalysis {
private:

public:
};

#endif
