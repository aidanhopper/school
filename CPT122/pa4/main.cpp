#include "header.cpp"

int main()
{
  Data data;
  data.id = Data::DIET;
  const char *name = "plan1";
  const char *date = "01/22/2122";
  data.diet = DietPlan(1566, name, date);
    
  List *list = new List(data);
  list->print();
  return 0;
}
