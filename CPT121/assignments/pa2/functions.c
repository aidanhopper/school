#include "header.h" // telling the preprocessor to include the header file

/* calculates_series_resistance: calculates total from 3 arguments
   pre: arguments passed are integers
   post: returns the sum of 3 integer arguments */
int calculate_series_resistance(int r1, int r2, int r3) {
  return r1 + r2 + r3;
}

/* calculate_total_sales_tax: calculates total sales tax from item cost and tax rate
   pre: both arguments are doubles
   post: returns the product of two doubles */
double calculate_total_sales_tax(double sales_tax_rate, double item_cost) {
  return sales_tax_rate * item_cost;
}

/* calculate_volume_pyramid: calculates the volume based on length width and height
   pre: all arguments are doubles
   post: returns the volume */
double calculate_volume_pyramid(double l, double w, double h) {
  return (l * w * h) / 3;
}


/* calculate_total_parallel_resistance: calculates the total parallel resistance from 3 integers 
   pre: all arguments are integers
   post: returns total parallel resistance */
double calculate_total_parallel_resistance(int r1, int r2, int r3) {
  return 1 / ((double)1/r1 + (double)1/r2 + (double)1/r3);
}

/* calculate_encode_character: calculates an encoded character based on an input char and shift value
   pre: has character and integer passed as arguments
   post: returns an encoded character */
char calculate_encode_character(char character, int shift) {
  return (character - 'a') + 'A' - shift;
}

/* calculate_distance_between_points: calculates the distance between two points
   pre: all arguments are doubles
   post: returns the distance */
double calculate_distance_between_points(double x1, double y1, double x2, double y2) {
  double distance = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
  return distance;
}

/* calculate_general_equation: calculates the result of a general equation
   pre: 3 doubles and 1 integer are passed as arguments
   post: returns the result of the equation */
double calculate_general_equation(double y, double z, double x, int a) {
  return (y / ((double)3 /17)) - (z + x / (a % 2)) + PI;
}
