#ifndef HEADER_CPP
#define HEADER_CPP

#include <fstream>
#include <iostream>
#include <string>

typedef enum {
  NONE,
  DIET,
  EXERCISE,
} Type;

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
  std::string name;
  std::string date;

public:
  ExercisePlan();
  ExercisePlan(int goal, const char *name, const char *date);
  ~ExercisePlan();
  int getGoal();
  std::string getName();
  std::string getDate();
  void setGoal(int goal);
  void setName(std::string name);
  void setDate(std::string date);
  void editGoal();
};

struct Data {
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
  ListNode(Data &data, ListNode *nextNode, ListNode *prevNode);
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
  Type id;
public:
  List();
  List(Data &data, Type id);
  ~List();
  void setHeadNode(ListNode *headNode);
  ListNode *getHeadNode();
  void print();
  void insertInFront(Data &data);
  void insertAtEnd(Data &data);
};

#endif

class FitnessAppWrapper {
private:
  List dietList;
  List exerciseList;
public:
  void runApp();

  void loadDailyDietPlan(std::fstream &fileStream, Data &data);
  void loadWeeklDietPlan(std::fstream &fileStream, List &list);
  void displayDailyDietPlan();
  void displayWeeklyDietPlan();
  void storeDailyDietPlan();

  void loadDailyExercisePlan(std::fstream &fileStream, Data &data);
  void loadWeeklExercisePlan(std::fstream &fileStream, List &list);
  void displayDailyExercisePlan();
  void displayWeeklyExercisePlan();
  void storeDailyExercisePlan();

  int displayMenu();
  
};
