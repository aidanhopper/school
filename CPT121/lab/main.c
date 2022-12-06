#include "header.h"

int main() {

  //Employee emp[10];
  FILE *file = fopen("payroll.txt", "r");
  char str[100];
  fgets(str, 100, file);
  printf("%s", str);
  fclose(file);
  return 0;
}
