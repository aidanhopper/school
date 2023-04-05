#ifndef LIST_H
#define LIST_H

#include <cstring>
#include <fstream>
#include <string>

typedef struct {
  int record;
  int id;
  std::string name;
  std::string email;
  int units;
  std::string program;
  std::string level;
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
  ~List();
};

template <class T> ListNode<T>::ListNode(T &data) {
  std::memcpy(this->data, data, sizeof this->data);
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

template <class T> void List<T>::destroyList() {
  ListNode<T> *tmp = this->head;
  ListNode<T> *tmpNext = NULL;

  while (tmp != NULL) {
    tmpNext = tmp->getNext();
    delete tmp;
  }

  this->head = NULL;
}

template <class T> List<T>::~List() { this->destroyList(); }

std::ostream &operator<<(std::ostream &input, Data &data) {

  input << data.record << "," << data.id << "," << data.name << ","
        << data.email << "," << data.units << "," << data.program << ","
        << data.level << "," << std::endl;
  return input;
}

#endif
