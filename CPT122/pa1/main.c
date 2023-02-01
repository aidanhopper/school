#include "header.h"

int main()
{
  // creating fitbit array
  FitbitData data[1441]; 

  // if len is 0 then opening the file failed
  int len = read_data(data);
  if (len == 0) return 0;

  // parses data store into info struct
  Info info;
  parse_data(data, len, &info);

  // printing data
  for (int i = 0; i < len; i++)
  {
    print_fitbit_data(&data[i]);
  }

  // writing data to results csv file
  write_data(data, len, &info);

  return 0;
}
