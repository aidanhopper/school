/*

    Name: Aidan Hopper
    Date: 09/09/22
    Class: CPTS 121 Section 1
    Description: 1st programming assignment

*/

#include <math.h> // tells the preprocessor to include useful math functions in the namespace
#include <stdio.h> // tells the preprocessor to include basic i/o functions in the namespace

// tells the preprocessor to replace any instance of PI with 3.14
#define PI 3.14

int main() { // beginning of program
  // 1
  // takes values as input and calculates the resistance
  printf("Please enter the values of all three resistors (all integers) "
         "connected in series: ");
  int R1 = 0;
  int R2 = 0;
  int R3 = 0;
  scanf("%d%d%d", &R1, &R2, &R3);
  int series_resistance = R1 + R2 + R3;
  printf("Total series resistance: series_resistance = R1 + R2 + R3 = %d + %d "
         "+ %d = %d\n",
         R1, R2, R3, series_resistance);

  // 2
  // takes sales tax and cost as input and outputs the total sales tax
  double sales_tax_rate = 0;
  double item_cost = 0;
  printf("Please enter the sales tax rate then the item cost: ");
  scanf("%lf%lf", &sales_tax_rate, &item_cost);
  double total_sales_tax = sales_tax_rate * item_cost;
  printf("total_sales_tax = sales_tax_rate * item_cost = %lf * %lf = %lf\n",
         sales_tax_rate, item_cost, total_sales_tax);

  // 3
  // calculates the volume given the dimensions
  double l = 0;
  double w = 0;
  double h = 0;
  printf("Please enter the length, width and height: ");
  scanf("%lf%lf%lf", &l, &w, &h);
  double volume_pyramid = (l * w * h) / 3;
  printf("volume_pyramid = (l * w * h)/3 = (%lf * %lf * %lf)/3 = %lf\n", l, w,
         h, volume_pyramid);

  // 4
  // calculates the parallel resistance with previous R values
  double parallel_resistance =
      1 / ((double)1 / R1 + (double)1 / R2 + (double)1 / R3);
  printf("parallel_resistance = 1 / ( 1/R1 + 1/R2 + 1/R3 ) = 1 / ( 1/%d + 1/%d "
         "+ 1/%d) = %lf\n",
         R1, R2, R3, parallel_resistance);

  // 5
  // takes in char and with ascii codes adds A as an integer to a and then
  // subtracts a specified integer
  printf("Please input a character and shift int: ");
  char plaintext_character;
  int shift_int = 0;
  scanf("%c%d", &plaintext_character, &shift_int);
  char encoded_character = plaintext_character - 'a' + 'A' - shift_int;
  printf("encoded_character = plaintext_character - 'a' + 'A' - shift_int = %c "
         "- 'a' + 'A' - %d = %c\n",
         plaintext_character, shift_int, encoded_character);

  // 6
  // takes in two sets of coordinates and outputs the difference between them
  double x1 = 0;
  double x2 = 0;
  double y1 = 0;
  double y2 = 0;

  printf("Please input two sets of coordinates: ");
  scanf("%lf%lf%lf%lf", &x1, &x2, &y1, &y2);

  double xdiff = x1 - x2;
  double ydiff = y1 - y2;

  double distance = sqrt(xdiff * xdiff + ydiff * ydiff);

  printf("distance = (x1-x2)^2 + (y1-y2)^2 = (%lf-%lf)^2 + (%lf-%lf)^2 = %lf\n",
         x1, x2, y1, y2, distance);

  // 7
  // takes in 4 values and runs them through an equation
  double y = 0;
  double x = 0;
  double z = 0;
  int a = 0;

  printf("Please enter a x, y, z, and a value: ");
  scanf("%lf%lf%lf%d", &x, &y, &z, &a);

  double sum = y / ((double)3 / 17) - z + x / (a % 2) + PI;
  printf("y = y / (3/17) - z + x / (a mod 2) + PI = %lf / (3/17) - %lf + %lf / "
         "(%d mod 2) + %lf = %lf",
         y, z, x, a, PI, sum);

  // program ran successfully
  return 0;
}
