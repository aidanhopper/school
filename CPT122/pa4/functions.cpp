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
  this->name.assign(date);
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
  name = new std::string("");
  date = new std::string("");
}

ExercisePlan::ExercisePlan(int goal, std::string name, std::string date) {
  this->goal = goal;
  this->name = new std::string(name);
  this->date = new std::string(date);
}

ExercisePlan::~ExercisePlan() {}

int ExercisePlan::getGoal() { return this->goal; }

std::string *ExercisePlan::getName() { return this->name; }

std::string *ExercisePlan::getDate() { return this->date; }

void ExercisePlan::setGoal(int goal) { this->goal = goal; }

void ExercisePlan::setName(std::string name) { *this->name = name; }

void ExercisePlan::setDate(std::string date) { *this->date = date; }

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

ListNode *ListNode::next() {
  return this->nextNode;
}

ListNode *ListNode::prev() {
  return this->prevNode;
}

List::List() {
  this->headNode = NULL;
}

List::List(Data data) {
  ListNode *node = new ListNode(data, NULL, NULL);
  this->headNode = node;
  this->curNode = this->headNode;
}

Data ListNode::getData() {
  return this->data;
}

void List::print() {
  ListNode *node = this->headNode;
  while (node != NULL) {
    Data dat = node->getData();
    if (dat.id == Data::DIET) {
      std::cout << dat.diet.getName() << "->";
    }
    else if (dat.id == Data::EXERCISE) {
      std::cout << dat.exercise.getName() << "->";
    }
    node = node->next();
  }
  std::cout << std::endl;
}


