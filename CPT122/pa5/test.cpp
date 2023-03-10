#include "app.hpp"

void test_enqueue_on_empty_queue() {
  Queue queue = Queue();
  queue.enqueue(1, 10, 10);
  queue.printQueue();
}

void test_enqueue_on_queue_with_one_node() {
  Queue queue = Queue(1,12,23);
  queue.enqueue(2, 10, 10);
  queue.printQueue();
}

void test_dequeue_on_empty_queue() {
  Queue queue = Queue();
  queue.dequeue();
}

void test_dequeue_on_queue_with_one_node() {
  Queue queue = Queue(1,12,23);
  queue.enqueue(2, 10, 10);
  queue.dequeue();
}
