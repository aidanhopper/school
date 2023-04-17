#include "node.h"

Node::Node(std::string &mData) {
  this->mData = mData;
  this->mpLeft = NULL;
  this->mpRight = NULL;
}

Node::~Node() {}
void Node::printData() {}

Node *&Node::getLeft() { return this->mpLeft; }

Node *&Node::getRight() { return this->mpLeft; }

std::string &Node::getData() { return this->mData; }

void Node::setLeft(Node *mpLeft) { this->mpLeft = mpLeft; }

void Node::setRight(Node *mpRight) { this->mpRight = mpRight; }

void Node::setData(std::string &mData) { this->mData = mData; }

TransactionNode::TransactionNode(std::string &mData, int &mUnits)
    : Node(mData) {
  this->mData = mData;
}

TransactionNode::~TransactionNode() {}

int TransactionNode::getUnits() { return this->mUnits; }

void TransactionNode::setUnits(int mUnits) { this->mUnits = mUnits; }

void TransactionNode::printData() {
  std::cout << this->mUnits << ":" << this->mData;
}

BST::BST() { this->mpRoot = NULL; }

BST::~BST() { this->destroyTree(this->mpRoot); }

void BST::destroyTree(Node *node) {
  if (node == NULL)
    return;
  destroyTree(node->getLeft());
  destroyTree(node->getRight());
  delete node;
}

Node *&BST::getRoot() { return this->mpRoot; }

void BST::setRoot(Node *&mpRoot) { this->mpRoot = mpRoot; }

void BST::insert(std::string &mData, int &mUnits) {
  insert(this->mpRoot, mData, mUnits);
}

void BST::insert(Node *&node, std::string &mData, int &mUnits) {
  if (this->mpRoot == NULL) {
    TransactionNode *newNode = new TransactionNode(mData, mUnits);
    this->mpRoot = newNode;
    return;
  }
  else if (node == NULL)
    return;
  else if (node->getLeft() == NULL &&
      ((TransactionNode *)node)->getUnits() < mUnits) {
    TransactionNode *newNode = new TransactionNode(mData, mUnits);
    node->setLeft(newNode);
    std::cout << node->getLeft()->getData() << std::endl;
    return;
  } else if (node->getRight() == NULL &&
             ((TransactionNode *)node)->getUnits() > mUnits) {
    TransactionNode *newNode = new TransactionNode(mData, mUnits);
    node->setRight(newNode);
    return;
  }
  insert(node->getLeft(), mData, mUnits);
  insert(node->getRight(), mData, mUnits);
}

void BST::inOrderTraversal() { this->inOrderTraversal(this->mpRoot); }

void BST::inOrderTraversal(Node *&node) {
  if (node == NULL)
    return;
  this->inOrderTraversal(node->getLeft());
  std::cout << "HI"
            << " ";
  ((TransactionNode *)node)->printData();
  this->inOrderTraversal(node->getRight());
}

TransactionNode &BST::findSmallest() {
  Node *node = this->getRoot();
  while (node->getLeft() != NULL)
    node = node->getLeft();
  TransactionNode *tmp = (TransactionNode *)node;
  return *tmp;
}

TransactionNode &BST::findLargest() {
  Node *node = this->getRoot();
  while (node->getRight() != NULL)
    node = node->getRight();
  TransactionNode *tmp = (TransactionNode *)node;
  return *tmp;
}
