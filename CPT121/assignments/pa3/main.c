/*

    Name: Aidan Hopper
    Date: 09/26/22
    Class: CPTS 121 Section 1
    Description: 3rd programming assignment

*/

#include "header.h"

int main() {
  FILE * infile;  // creating pointer for infile
  FILE * outfile; // creating pointer for outfile

  infile = fopen("input.dat", "r"); // opens input file as read only
  outfile = fopen("output.dat", "w"); //opens output file as write only

  // reading variables from input file into variables
  int		id1	  = read_integer(infile); 
  double	gpa1	  = read_double(infile);
  int		standing1 = read_integer(infile);
  double	age1	  = read_double(infile);

  int		id2	  = read_integer(infile);
  double	gpa2	  = read_double(infile);
  int		standing2 = read_integer(infile);
  double	age2	  = read_double(infile);

  int		id3	  = read_integer(infile);
  double	gpa3	  = read_double(infile);
  int		standing3 = read_integer(infile);
  double	age3	  = read_double(infile);

  int		id4	  = read_integer(infile);
  double	gpa4	  = read_double(infile);
  int		standing4 = read_integer(infile);
  double	age4	  = read_double(infile);

  int		id5	  = read_integer(infile);
  double	gpa5	  = read_double(infile);
  int		standing5 = read_integer(infile);
  double	age5	  = read_double(infile);

  // calculates the sum of gpa, standing, and age 
  double	gpaSum	     = calculate_sum(gpa1, gpa2, gpa3, gpa4, gpa5);
  double	standingSum  = calculate_sum(standing1, standing2, standing3, standing4, standing5);
  double	ageSum	     = calculate_sum(age1, age2, age3, age4, age5);

  // calculate the mean of gpa, standing, and age
  double	gpaMean	     = calculate_mean(gpaSum, 5);
  double	standingMean = calculate_mean(standingSum, 5);
  double	ageMean	     = calculate_mean(ageSum, 5);

  // calculates the difference from the mean of each gpa
  double	gpaDeviation1 = calculate_deviation(gpa1, gpaMean);
  double	gpaDeviation2 = calculate_deviation(gpa2, gpaMean);
  double	gpaDeviation3 = calculate_deviation(gpa3, gpaMean);
  double	gpaDeviation4 = calculate_deviation(gpa4, gpaMean);
  double	gpaDeviation5 = calculate_deviation(gpa5, gpaMean);

  // calculates the variance of the gpa using the deviations from the mean
  double	gpaVariance	     = calculate_variance(gpaDeviation1, gpaDeviation2, gpaDeviation3, gpaDeviation4, gpaDeviation5, 5);

  // calculates the standard deviation from the mean for gpa
  double	gpaStandardDeviation = calculate_standard_devation(gpaVariance);

  // finds the min and max gpas from ones read from file
  double gpaMin = find_min(gpa1, gpa2, gpa3, gpa4, gpa5);
  double gpaMax = find_max(gpa1, gpa2, gpa3, gpa4, gpa5);

  // writes doubles to file
  print_double(outfile, gpaMean);
  print_double(outfile, standingMean);
  print_double(outfile, ageMean);
  fprintf(outfile, "\n");
  print_double(outfile, gpaStandardDeviation);
  print_double(outfile, gpaMin);
  print_double(outfile, gpaMax);

  return 0; // program ran successfully
}
