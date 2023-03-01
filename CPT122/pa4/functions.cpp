#include "header.cpp"

// DietPlan definitions
DietPlan::DietPlan() {
  this->goal = 0;
  this->name.assign("");
  this->date.assign("");
}

DietPlan::DietPlan(int goal, const char *name, const char *date) {
  this->goal = goal;
  this->name.assign(name);
  this->date.assign(date);
}

DietPlan::~DietPlan() {}

int DietPlan::getGoal() { return this->goal; }

std::string DietPlan::getName() { return this->name; }

std::string DietPlan::getDate() { return this->date; }

void DietPlan::setGoal(int goal) { this->goal = goal; }

void DietPlan::setName(std::string name) { this->name.assign(name); }

void DietPlan::setDate(std::string date) { this->date.assign(date); }

// Exercise Plan definitons
ExercisePlan::ExercisePlan() {
  this->goal = 0;
  this->name.assign("");
  this->date.assign("");
}

ExercisePlan::ExercisePlan(int goal, const char *name, const char *date) {
  this->goal = goal;
  this->name.assign(name);
  this->date.assign(date);
}

ExercisePlan::~ExercisePlan() {}

int ExercisePlan::getGoal() { return this->goal; }

std::string ExercisePlan::getName() { return this->name; }

std::string ExercisePlan::getDate() { return this->date; }

void ExercisePlan::setGoal(int goal) { this->goal = goal; }

void ExercisePlan::setName(std::string name) { this->name.assign(name); }

void ExercisePlan::setDate(std::string date) { this->date = date; }

// ListNode defintions
ListNode::ListNode() {
  this->nextNode = NULL;
  this->prevNode = NULL;
}

ListNode::ListNode(Data &data, ListNode *nextNode, ListNode *prevNode) {
  this->data.diet = data.diet;
  this->data.exercise = data.exercise;
  this->nextNode = nextNode;
  this->prevNode = prevNode;
}

void ListNode::setNext(ListNode *node) { this->nextNode = node; }

void ListNode::setPrev(ListNode *node) { this->prevNode = node; }

ListNode *ListNode::next() { return this->nextNode; }

ListNode *ListNode::prev() { return this->prevNode; }

List::List() {
  this->headNode = NULL;
  this->id = Type::NONE;
}

List::List(Data &data, Type id) {
  ListNode *node = new ListNode(data, NULL, NULL);
  this->headNode = node;
  this->curNode = this->headNode;
  this->id = id;
}

ListNode *List::getHeadNode() { return this->headNode; }

void List::setHeadNode(ListNode *headNode) { this->headNode = headNode; }

Data ListNode::getData() { return this->data; }

void List::print() {
  ListNode *node = this->headNode;
  while (node != NULL) {
    Data dat = node->getData();
    if (this->id == Type::DIET) {
      std::cout << dat.diet.getName() << "->";
    } else if (this->id == Type::EXERCISE) {
      std::cout << dat.exercise.getName() << "->";
    }
    node = node->next();
  }
  std::cout << std::endl;
}

void List::insertInFront(Data &data) {
  ListNode *node = new ListNode(data, this->getHeadNode(), NULL);
  this->setHeadNode(node);
}

void List::insertAtEnd(Data &data) {
  ListNode *newNode = new ListNode(data, NULL, NULL);
  ListNode *tmpNode = this->getHeadNode();
  ListNode *tmpPrevNode = NULL;
  while (tmpNode != NULL) {
    tmpPrevNode = tmpNode;
    tmpNode = tmpNode->next();
  }
  if (tmpPrevNode == NULL) {
    this->setHeadNode(newNode);
  } else {
    tmpPrevNode->setNext(newNode);
  }
}

List::~List() {}
