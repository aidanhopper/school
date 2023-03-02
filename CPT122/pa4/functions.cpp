#include "header.cpp"
#include <fstream>
#include <ios>
#include <iostream>
#include <pthread.h>
#include <string>

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

List::List(Type id) {
  this->id = id;
  this->setHeadNode(NULL);
}

List::~List() {}

FitnessAppWrapper::FitnessAppWrapper() {
  this->dietList = List(Type::DIET);
  this->exerciseList = List(Type::EXERCISE);
}

int FitnessAppWrapper::displayMenu() {
  printf("Select an option\n"
         "1. Load weekly diet plan from file.\n"
         "2. Load weekly exercise plan from file.\n"
         "3. Store weekly diet plan to file.\n"
         "4. Store weekly exercise plan to file.\n"
         "5. Display weekly diet plan to screen.\n"
         "6. Display weekly exercise plan to screen.\n"
         "7. Edit daily diet plan.\n"
         "8. Edit daily exercise plan.\n"
         "9. Exit\n");
  int input;
  std::cin >> input;
  return input;
}

void FitnessAppWrapper::runApp() {
  int option_selected = -1;
  while (option_selected != 9) {
    option_selected = this->displayMenu();
    this->executeOption(option_selected);
  }
  // save
}
void FitnessAppWrapper::executeOption(int option_selected) {
  this->dietStream = std::fstream("./dietPlans.txt");
  this->exerciseStream = std::fstream("./exercisePlans.txt");
  switch (option_selected) {
  case 1:
    this->loadWeeklyDietPlan(this->dietStream, this->dietList);
    break;
  case 2:
    this->loadWeeklyExercisePlan(this->exerciseStream, this->exerciseList);
    break;
  case 3:
    this->storeWeeklyDietPlan(this->dietStream, this->dietList);
    break;
  case 4:
    this->storeWeeklyExercisePlan(this->exerciseStream, this->exerciseList);
    break;
  case 5:
    this->displayWeeklyDietPlan(this->dietList);
    break;
  case 6:
    this->displayWeeklyExercisePlan(this->exerciseList);
    break;
  }
  dietStream.close();
  exerciseStream.close();
}

void FitnessAppWrapper::loadDailyDietPlan(std::fstream &fileStream,
                                          Data &data) {
  fileStream >> data.diet;
}

void FitnessAppWrapper::loadWeeklyDietPlan(std::fstream &fileStream,
                                           List &list) {
  Data data;
  for (int i = 0; i < 7; i++) {
    this->loadDailyDietPlan(fileStream, data);
    list.insertAtEnd(data);
  }
}

void FitnessAppWrapper::loadDailyExercisePlan(std::fstream &fileStream,
                                              Data &data) {
  fileStream >> data.exercise;
}

void FitnessAppWrapper::loadWeeklyExercisePlan(std::fstream &fileStream,
                                               List &list) {
  Data data;
  for (int i = 0; i < 7; i++) {
    this->loadDailyExercisePlan(fileStream, data);
    list.insertAtEnd(data);
  }
}

std::istream &operator>>(std::istream &input, ExercisePlan &plan) {
  char line[100];
  input.getline(line, 100, '\n');
  plan.setName(line);
  input.getline(line, 100, '\n');
  plan.setGoal(std::stoi(line));
  input.getline(line, 100, '\n');
  plan.setDate(line);
  input.getline(line, 100, '\n');
  return input;
}

std::ostream &operator<<(std::ostream &output, ExercisePlan &plan) {
  output << "Plan name: " << plan.getName() << std::endl
         << "Goal: " << plan.getGoal() << std::endl
         << "Date: " << plan.getDate() << std::endl;
  return output;
}

std::istream &operator>>(std::istream &input, DietPlan &plan) {
  char line[100];
  input.getline(line, 100, '\n');
  plan.setName(line);
  input.getline(line, 100, '\n');
  plan.setGoal(std::stoi(line));
  input.getline(line, 100, '\n');
  plan.setDate(line);
  input.getline(line, 100, '\n');
  return input;
}

std::ostream &operator<<(std::ostream &output, DietPlan &plan) {
  output << "Plan name: " << plan.getName() << std::endl
         << "Goal: " << plan.getGoal() << std::endl
         << "Date: " << plan.getDate() << std::endl;
  return output;
}

std::fstream &operator<<(std::fstream &output, DietPlan &plan) {
  output << plan.getName() << std::endl
         << plan.getGoal() << std::endl
         << plan.getDate() << std::endl
         << std::endl;
  return output;
}

std::fstream &operator<<(std::fstream &output, ExercisePlan &plan) {
  output << plan.getName() << std::endl
         << plan.getGoal() << std::endl
         << plan.getDate() << std::endl
         << std::endl;
  return output;
}


void FitnessAppWrapper::displayWeeklyDietPlan(List &list) {
  ListNode *node = list.getHeadNode();
  while (node != NULL) {
    DietPlan plan = node->getData().diet;
    this->displayDailyDietPlan(plan);
    node = node->next();
  }
}

void FitnessAppWrapper::displayDailyDietPlan(DietPlan &plan) {
  std::cout << plan;
}

void FitnessAppWrapper::displayWeeklyExercisePlan(List &list) {
  ListNode *node = list.getHeadNode();
  while (node != NULL) {
    ExercisePlan plan = node->getData().exercise;
    this->displayDailyExercisePlan(plan);
    node = node->next();
  }
}

void FitnessAppWrapper::displayDailyExercisePlan(ExercisePlan &plan) {
  std::cout << plan;
}

void FitnessAppWrapper::storeDailyDietPlan(std::fstream &dietStream, DietPlan &plan) {
  dietStream << plan;
}

void FitnessAppWrapper::storeWeeklyDietPlan(std::fstream &dietStream, List &list) {
  ListNode *node = list.getHeadNode();  
  while (node != NULL) {
    DietPlan plan = node->getData().diet;
    this->storeDailyDietPlan(dietStream, plan);
    node = node->next();
  }
}

void FitnessAppWrapper::storeDailyExercisePlan(std::fstream &exerciseStream, ExercisePlan &plan) {
  exerciseStream << plan;
}

void FitnessAppWrapper::storeWeeklyExercisePlan(std::fstream &exerciseStream, List &list) {
  ListNode *node = list.getHeadNode();  
  while (node != NULL) {
    ExercisePlan plan = node->getData().exercise;
    this->storeDailyExercisePlan(exerciseStream, plan);
    node = node->next();
  }
}
