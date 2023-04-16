#include "node.h"

Node::Node(std::string &mData) {
  this->mData = mData;
  this->mpLeft = NULL;
  this->mpRight = NULL;
}

Node *&Node::getLeft() { return this->mpLeft; }

Node *&Node::getRight() { return this->mpLeft; }

std::string &Node::getData() { return this->mData; }

void Node::setLeft(Node *&mpLeft) { this->mpLeft = mpLeft; }

void Node::setRight(Node *&mpRight) { this->mpRight = mpRight; }

void Node::setData(std::string &mData) { this->mData = mData; }

TransactionNode::TransactionNode(std::string &mData, int &mUnits)
    : Node(mData) {
  this->mData = mData;
}

int TransactionNode::getUnits() { return this->mUnits; }

void TransactionNode::setUnits(int mUnits) { this->mUnits = mUnits; }

void TransactionNode::printData() {
  std::cout << this->mUnits << ":" << this->mData;
}

BST::BST() { this->mpRoot = NULL; }

Node *&BST::getRoot() { return this->mpRoot; }

void BST::setRoot(Node *&mpRoot) { this->mpRoot = mpRoot; }

void BST::insert(std::string &mData, int &mUnits) { insert(this->mpRoot, mData, mUnits); }

void BST::insert(Node *&node, std::string &data, int &mUnits) {
  if (node == NULL)
    return;
  if (((TransactionNode*)node)->getUnits()) {

  }
}
