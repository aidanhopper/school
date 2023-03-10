#include "classes.hpp"

Data::Data() {
  this->totalTime = 0;
  this->customerNumber = 0;
  this->serviceTime = 0;
}

Data::Data(int customerNumber, int serviceTime, int totalTime) {
  this->customerNumber = customerNumber;
  this->serviceTime = serviceTime;
  this->totalTime = totalTime;
}

int Data::getTotalTime() { return this->totalTime; }
int Data::getServiceTime() { return this->serviceTime; }
int Data::getCustomerNumber() { return this->customerNumber; }
void Data::setServiceTime(int serviceTime) { this->serviceTime = serviceTime; }

Data::~Data() {}

QueueNode::QueueNode() {
  this->pData = NULL;
  this->pNext = NULL;
}

QueueNode::QueueNode(QueueNode *pNext, int customerNumber, int serviceTime,
                     int totalTime) {
  this->pNext = pNext;
  this->pData = new Data(customerNumber, serviceTime, totalTime);
}

Data *QueueNode::getData() { return this->pData; }

QueueNode::~QueueNode() { delete this->pData; }

QueueNode *QueueNode::getNext() { return this->pNext; }

void QueueNode::setNext(QueueNode *pNext) { this->pNext = pNext; }

Queue::Queue() {
  this->pHead = NULL;
  this->pTail = NULL;
}

QueueNode *Queue::getTail() { return this->pTail; }

Queue::Queue(int customerNumber, int serviceTime, int totaltime) {
  this->pHead = new QueueNode(NULL, customerNumber, serviceTime, totaltime);
  this->pTail = pHead;
}

Queue::~Queue() {}

int Queue::isEmpty() {
  if (this->pHead == NULL)
    return 1;
  return 0;
}

void Queue::printQueue() {
  QueueNode *node = this->pHead;
  while (node != NULL) {
    std::cout << node->getData()->getCustomerNumber() << "->";
    node = node->getNext();
  }
  std::cout << std::endl;
}

void Queue::enqueue(int customerNumber, int serviceTime, int totalTime) {
  QueueNode *node =
      new QueueNode(this->pHead, customerNumber, serviceTime, totalTime);
  if (this->pTail == NULL) {
    this->pTail = node;
  }
  this->pHead = node;
}

void Queue::dequeue() {
  QueueNode *retnode = this->pTail;
  if (retnode == NULL)
    return;
  this->pTail = NULL;
  QueueNode *tmp = this->pHead;
  QueueNode *tmpprev = NULL;
  while (tmp != NULL) {
    tmpprev = tmp;
    tmp = tmp->getNext();
  }
  tmpprev->setNext(NULL);
  delete retnode;
}
