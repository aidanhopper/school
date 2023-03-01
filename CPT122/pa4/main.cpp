#include "header.cpp"

int main()
{
  Data dat;
  dat.exercise = ExercisePlan(1231, "asdf", "123");
  List list = List(dat, Type::EXERCISE);
  list.print();
  return 0;
}
