/*
Programmer: Aidan Hopper
Class: CptS 121, Fall 2022; Lab Section 11
Programming Assignment: Lab1Task1
Date: September 1, 2022
Description: First lab
*/

#define _CRT_SECURE_NO_WARNINGS // stops scanf from complaining

#include <stdio.h> // telling the preprocessor to include the header stdio in the file

int main () {

  // 1
  int number1_int = 123;
  int number2_int = 3;
  int int_sum = number1_int + number2_int; printf("%d\n", int_sum);

  //2
  double number1_float = 22.34;
  double number2_float = 19.2;
  printf("%lf\n", number1_float-number2_float);

  // 3
  int product = number1_int * number2_float;
  printf("%d\n", product);

  // 4
  int quotient = number1_int / number2_float;
  printf("%d\n", quotient);

  // 5
  int sum2int = number1_int / number2_float;
  double sum2float = number1_int / number2_float;
  printf("As int : %d, As float %lf\n", sum2int, sum2float);

  // 6
  int sum3int = ((double) number1_int) / number2_int;
  double sum3float = sum3int;
  printf("As int %d, As float %lf\n", sum3int, sum3float);

  // 7
  int mod = (int) number1_float % (int) number2_float;
  printf("%d\n", mod);


  // 8
  int isodd = number1_int % number2_int;

  printf("%d\n", isodd);
  return 0;
}
