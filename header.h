/*****************************************************************
*
* Thomas Hynes
*
* Program reads in a list of patients as the time they arrived
* sorts data given specifications in assignment sheet and outputs
* into a seperate file.
*
*****************************************************************/

#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <stdio.h>

#define MAX_PATIENTS 100
#define LINE_LENGTH 50

struct Patient
{
  int used;
  int num;
  int age;
  int pain;
  long time;
  long helpedtime;
};

extern struct Patient patients[MAX_PATIENTS];
extern struct Patient solved[MAX_PATIENTS];

void printTime(FILE*,long);
void printTime2(FILE*,long);
long timeToSeconds(int,int,int);
void solve(int);
void initialSort(int);
void printSolved(FILE*, int);

#endif
