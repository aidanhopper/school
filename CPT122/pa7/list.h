#ifndef LIST_H
#define LIST_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

typedef struct {
  int record;
  int id;
  std::string name;
  std::string email;
  int units;
  std::string program;
  std::string level;
  int absences;
  // insert stack here
} Data;

template <class T> class ListNode {
private:
  T data;
  ListNode<T> *next;

public:
  ListNode();
  ListNode(T &data);
  ListNode<T> *getNext();
  T *getData();
  void setNext(ListNode<T> *next);
};

template <class T> class List {
private:
  ListNode<T> *head;
  void destroyList();

public:
  List();
  void insert(T &data);
  void print();
  void write(std::ofstream &file);
  ListNode<T> *getHead();
  ~List();
};

template <class T> ListNode<T>::ListNode(T &data) {
  this->data = data;
  this->next = NULL;
}

template <class T> ListNode<T> *ListNode<T>::getNext() { return this->next; }

template <class T> void ListNode<T>::setNext(ListNode<T> *next) {
  this->next = next;
}

template <class T> T *ListNode<T>::getData() { return &this->data; }

template <class T> List<T>::List() { this->head = NULL; }

template <class T> void List<T>::insert(T &data) {
  ListNode<T> *newNode = new ListNode<T>(data);
  if (newNode == NULL)
    return;

  if (this->head != NULL)
    newNode->setNext(this->head);

  this->head = newNode;
}

template <class T> ListNode<T> *List<T>::getHead() { return this->head; }

template <class T> void List<T>::print() {
  ListNode<T> *node = this->head;
  while (node != NULL) {
    std::cout << *node->getData() << std::endl;
    node = node->getNext();
  }
}

template <class T> void List<T>::write(std::ofstream &file) {
  ListNode<T> *node = this->head;
  while (node != NULL) {
    file << *node->getData() << std::endl;
    node = node->getNext();
  }
}

template <class T> void List<T>::destroyList() {
  ListNode<T> *tmp = this->head;
  ListNode<T> *tmpPrev = NULL;

  while (tmp != NULL) {
    tmpPrev = tmp;
    tmp = tmp->getNext();
    delete tmpPrev;
  }

  this->head = NULL;
}

template <class T> List<T>::~List() { this->destroyList(); }

#endif
