#pragma once

#include <iostream>
#include <ctime>

class Data {
public:
  Data();
  Data(int customerNumber, int serviceTime, int totalTime);
  ~Data();
  int getCustomerNumber();
  int getServiceTime();
  int getTotalTime();
  void setCustomerNumber(int customerNumber);
  void setServiceTime(int serviceTime);
  void setTotalTime(int totalTime);
private:
  int customerNumber;
  int serviceTime;
  int totalTime;
};

class QueueNode {
public:
  QueueNode();
  QueueNode(QueueNode *pNext, int customerNumber, int serviceTime, int totalTime);
  ~QueueNode();
  Data *getData();
  QueueNode *getNext();
  void setNext(QueueNode *pNext);
  void getData(Data *pData);

private:
  Data *pData;
  QueueNode *pNext;
};

class Queue {
public:
  Queue();
  Queue(int customerNumber, int serviceTime, int totaltime);
  ~Queue();
  QueueNode *getHead();
  QueueNode *getTail();
  void setHead(QueueNode *pHead);
  void setTail(QueueNode *pTail);
  void enqueue(int customerNumber, int serviceTime, int totalTime);
  void dequeue();
  void printQueue();
  int isEmpty();

private:
  QueueNode *pHead;
  QueueNode *pTail;
};

void test_enqueue_on_empty_queue();
void test_enqueue_on_queue_with_one_node();
void test_dequeue_on_empty_queue();
void test_dequeue_on_queue_with_one_node();

void run(int minutes);
