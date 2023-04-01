#include "header.h"

BSTNode::BSTNode(const char c, const char *code) {
  this->c = c;
  this->code = code;
}

char BSTNode::getC() { return this->c; }

BSTNode *BSTNode::getLeft() { return this->left; }

BSTNode *BSTNode::getRight() { return this->right; }

void BSTNode::setLeft(BSTNode *left) { this->left = left; }

void BSTNode::setRight(BSTNode *right) { this->right = right; }

BST::BST(const char *path) {
  std::ofstream file;
  file.open(path);

  file.close();
}

void BST::insert(BSTNode *root, const char c, const char *code) {
  {
    if (this->root == NULL) // base case
    {
      // we know the tree is empty
      this->root = new BSTNode(c, code); // mpLeft, mpRight are nullptr
    } else if (c > root->getC()) {
      // root contains the address of the current node that we're visiting
      // is the right subtree of the node that we're visiting empty?
      if (root->getRight() == NULL) {
        root->setRight(new BSTNode(c, code));
      } else // the right subtree is not empty
      {
        insert(root->getRight(), c, code);
      }
    } else if (c < root->getC()) {
      // is the left subtree empty?
      if (root->getLeft() == NULL) {
        root->setLeft(new BSTNode(c, code));
      } else // the left subtree is not empty
      {
        insert(root->getLeft(), c, code);
      }
    }
  }
}
