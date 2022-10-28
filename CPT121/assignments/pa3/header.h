#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <math.h>

// reads double from file
// pre: assumes FILE as input
// post: returns double from file
double read_double(FILE *infile);

// reads integer from file
// pre: assumes FILE as input
// post: returns integer from file
int read_integer(FILE *infile);

// calculates sum from input numbers
// pre: 5 doubles as input
// post: returns the sum of five doubles
double calculate_sum(double number1, double number2, double number3, double number4, double number5);

// calculates the mean sum the sum
// pre: takes sum as double and number as an integer
// post: returns the mean as a double
double calculate_mean(double sum, int number);

// calculates the difference from the mean
// pre: assumes number and mean as passed as doubles
// post: returns the deviation as a double
double calculate_deviation(double number, double mean);

// calculates the variance from 5 input values
// pre: assumes 5 devation inputs and a number input
// post: returns the variance as a double
double calculate_variance(double deviation1, double deviation2, double deviation3, double deviation4, double deviation5, int number);

// calculates the standard deviation from the variance
// pre: assumes variance is passed as double
// post: returns standard deviation as double
double calculate_standard_devation(double variance);

// finds the max value among 5 values
// pre: assumes 5 double inputs
// post: returns max as double
double find_max(double number1, double number2, double number3, double number4, double number5);

// finds the min value among 5 values
// pre: assumes 5 number inputs as doubles
// post: returns min as double
double find_min(double number1, double number2, double number3, double number4, double number5);

// writes double to outfile
// pre: assumes outfile as FILE pointer and number as double
// post: returns nothing
void print_double(FILE *outfile, double number);

#endif
