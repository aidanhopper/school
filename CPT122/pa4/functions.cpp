#include "header.cpp"

// DietPlan definitions
DietPlan::DietPlan() {
  this->goal = 0;
  name = "";
  date = "";
}

DietPlan::DietPlan(int goal, std::string name, std::string date) {
  this->goal = goal;
  this->name = name;
  this->date = date;
}

DietPlan::~DietPlan() {}

int DietPlan::getGoal() { return this->goal; }

std::string DietPlan::getName() { return this->name; }

std::string DietPlan::getDate() { return this->date; }

void DietPlan::setGoal(int goal) { this->goal = goal; }

void DietPlan::setName(std::string name) { this->name = name; }

void DietPlan::setDate(std::string date) { this->date = date; }

// Exercise Plan definitons
ExercisePlan::ExercisePlan() {
  this->goal = 0;
  name = "";
  date = "";
}

ExercisePlan::ExercisePlan(int goal, std::string name, std::string date) {
  this->goal = goal;
  this->name = name;
  this->date = date;
}

ExercisePlan::~ExercisePlan() {}

int ExercisePlan::getGoal() { return this->goal; }

std::string ExercisePlan::getName() { return this->name; }

std::string ExercisePlan::getDate() { return this->date; }

void ExercisePlan::setGoal(int goal) { this->goal = goal; }

void ExercisePlan::setName(std::string name) { this->name = name; }

void ExercisePlan::setDate(std::string date) { this->date = date; }

// ListNode defintions
ListNode::ListNode() {
  this->nextNode = NULL;
  this->prevNode = NULL;
  data.id = Data::NONE;
}

ListNode::ListNode(Data data, ListNode *nextNode, ListNode *prevNode) {
  this->data = data; 
  this->nextNode = nextNode;
  this->prevNode = prevNode;
}

void ListNode::setNext(ListNode *node) {
  this->nextNode = node;
}

void ListNode::setPrev(ListNode *node) {
  this->prevNode = node;
}

Data ListNode::getData() {
  return this->data;
}

ListNode *ListNode::next() {
  return this->nextNode;
}

ListNode *ListNode::prev() {
  return this->prevNode;
}

List::List() {
  this->headNode = NULL;
  this->curNode = NULL;
}

ListNode *List::createNode(Data data) {
  ListNode *node = new ListNode(data, this->headNode, NULL);
  return node;
}

List::List(Data data) {
  List::createNode(data);
}



