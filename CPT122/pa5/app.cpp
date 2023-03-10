#include "app.hpp"

void generateNormalCustomer(Queue &q, int &customerNumber, int &arrivalTime) {
  if (arrivalTime > 0) {
    arrivalTime--;
  } else if (arrivalTime == 0) {
    q.enqueue((customerNumber)++, (std::rand() % 5) + 3, 0);
    arrivalTime--;
  } else {
    // generate a new arrival time
    arrivalTime = (std::rand() % 5) + 1;
  }
}

void generateExpressCustomer(Queue &q, int &customerNumber, int &arrivalTime) {
  if (arrivalTime > 0) {
    arrivalTime--;
  } else if (arrivalTime == 0) {
    q.enqueue(customerNumber++, (std::rand() % 3) + 1, 0);
    arrivalTime--;
  } else {
    // generate a new arrival time
    arrivalTime = (std::rand() % 5) + 4;
  }
}

void print(Queue &queue, const char *str, int &time) {
  if (time % 10 == 0) {
    std::cout << str << time << " minutes." << std::endl;
    queue.printQueue();
  }
}

void processNormalCustomer(Queue &q) {
  if (q.isEmpty()) {
    return;
  }
  int serviceTime = q.getTail()->getData()->getServiceTime();
  if (serviceTime > 0) {
    // decrement every minute until 0
    q.getTail()->getData()->setServiceTime(serviceTime - 1);
  } else if (serviceTime == 0) {
    // process
    q.dequeue();
  }
  
}

void run(int minutes) {
  // initing queues
  Queue normal = Queue();
  Queue express = Queue();

  // declaring other stuff
  int customerNumber = 1;
  int normalArrivalTime = (std::rand() % 5) + 1;
  int expressArrivalTime = (std::rand() % 5) + 3;

  // simulation loop
  for (int i = 0; i < minutes; i++) {
    generateNormalCustomer(normal, customerNumber, normalArrivalTime);
    //generateExpressCustomer(express, customerNumber, expressArrivalTime);
    processNormalCustomer(normal);
    print(normal, "Normal line at ", i);
    //print(express, "Express line at ", i);
  }
}
