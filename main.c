/***********************************************************
*
* Thomas Hynes
*
* Reads in two command line arguments, first being
* the input file the second being the output. Sorts
* and solves input then opens the output file and prints
* the sorted data.
*
***********************************************************/


#include <stdio.h>
#include "header.h"

struct Patient patients[MAX_PATIENTS];
struct Patient solved[MAX_PATIENTS];

int main(int argc, char* argv[])
{
  const char* inputfile = argv[1];
  const char* outputfile = argv[2];

  char line[LINE_LENGTH];

  int i = 0;
  int arrlen;
  
  FILE* in = fopen(inputfile,"r");
  FILE* out;
  
  while(fgets(line,LINE_LENGTH,in)!=NULL)
  {
    int hours;
    int minutes;
    int seconds;
    sscanf(line,"%d %d:%d:%d %d %d",&patients[i].num,&hours,&minutes,&seconds,&patients[i].age,&patients[i].pain);
    patients[i].time = timeToSeconds(hours,minutes,seconds);
    patients[i].used = 0;
    patients[i].helpedtime = 0;
    i++;
  }

  arrlen = i;
  initialSort(arrlen);

  solve(arrlen);

  out = fopen(outputfile, "w");
  printSolved(out, arrlen);
  fclose(in);
  fclose(out);
  return 0;
}
