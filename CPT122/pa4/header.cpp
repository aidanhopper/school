#ifndef HEADER_CPP
#define HEADER_CPP

#include <iostream>
#include <string>
#include <string.h>

class DietPlan {
private:
  int goal;
  std::string name;
  std::string date;

public:
  DietPlan();
  DietPlan(int goal, const char *name, const char *date);
  ~DietPlan();
  int getGoal();
  std::string getName();
  std::string getDate();
  void setGoal(int goal);
  void setName(std::string name);
  void setDate(std::string date);
  void editGoal();
};

class ExercisePlan {
private:
  int goal;
  std::string *name;
  std::string *date;

public:
  ExercisePlan();
  ExercisePlan(int goal, std::string name, std::string date);
  ~ExercisePlan();
  int getGoal();
  std::string *getName();
  std::string *getDate();
  void setGoal(int goal);
  void setName(std::string name);
  void setDate(std::string date);
  void editGoal();
};

class FitnessAppWrapper {
private:
public:
};

struct Data {
  enum { NONE, EXERCISE, DIET } id;
  ExercisePlan exercise;
  DietPlan diet;
};

class ListNode {
private:
  ListNode *nextNode;
  ListNode *prevNode;
  Data data;

public:
  ListNode();
  ListNode(Data data, ListNode *nextNode, ListNode *prevNode);
  ListNode *next();
  ListNode *prev();
  void setNext(ListNode *node);
  void setPrev(ListNode *node);
  Data getData();
};

class List {
private:
  ListNode *headNode;
  ListNode *curNode;

public:
  List();
  List(Data data);
  ~List();
  void setHead();
  void print();
};

#endif


