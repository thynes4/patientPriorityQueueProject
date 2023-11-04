#include <stdio.h>

#include "header.h"

/**********************************************************************************
*
* Given the length of the array, goes through the already presorted list,
* and each time sets the struct Patient nextUp to be whichever is next for
* the requirements specified. If a patient gets used it marks that and does not
* consider that patient in the next loop. All patients are assigned the time that
* they are helped and the time spent waiting as they are put into the sorted array.
*
**********************************************************************************/

void solve(int arrlen)
{
  int j;
  int i = 0;
  long curtime = 27900;
  int next = -1;
  struct Patient nextUp;

  while (i < arrlen)
  {
    next = -1;
    for (j= 0; j < arrlen; j++)
    {
     if (patients[j].time < curtime && patients[j].used == 0)
      {
        if (patients[j].pain == 10)
        {
          next = j;
          break;
        }
        if (next != -1 && patients[j].time + 7200 > curtime && patients[j].pain == patients[next].pain
            && patients[next].age == patients[j].age && patients[j].time < patients[next].time)
        {
          next = j;
        }
        if (patients[j].time + 7200 <= curtime && next == -1)
        {
          next = j;
        }
        if (next != -1 && patients[j].time + 7200 <=curtime && patients[j].time < patients[next].time)
        {
          next = j;
        }
        if (next == -1)
        {
          next = j;
        }
      }
    }
    if (next != -1)
    {
      nextUp = patients[next];
      patients[next].used = 1;
      solved[i] = nextUp;
      solved[i].helpedtime = curtime;
      i++;
    }
    curtime += 900;
  }
}

/************************************************************************
*
* Given a file to print to and the length of the array needed to be
* printed, will print out the patients number, pain, age and time waiting
* in the format required for the project.
*
*************************************************************************/

void printSolved(FILE* out, int arrlen)
{
  int i = 0;
  while (i < arrlen)
  {
    printTime(out,solved[i].helpedtime);
    fprintf(out," Patient: ID = %d, ",solved[i].num);
    fprintf(out,"Pain Level (1-10) = %d, ",solved[i].pain);
    fprintf(out,"Age = %d years, ",solved[i].age);
    fprintf(out,"Time waiting = ");
    printTime2(out,solved[i].helpedtime - solved[i].time);
    fprintf(out,"\n");
    i++;
  }
}

/***********************************************************************
*
* Given a time in hours, minutes and seconds will convert this to
* time in just seconds and return it as a long value.
*
***********************************************************************/

long timeToSeconds (int hours, int minutes, int seconds)
{
  long time = 0;
  time += (hours * 3600);
  time += (minutes * 60);
  time += seconds;
  return time;
}

/************************************************************************
*
* Given a file to print out to and a time in seconds, will convert the
* back to hours, minutes, and seconds then print said time into the given
* output file.
*
************************************************************************/
void printTime (FILE* out, long seconds)
{
  int h, m, s;
  h = (seconds / 3600);
  m = (seconds - (3600*h))/60;
  s = (seconds -(3600*h)-(m*60));
  if (h < 10) fprintf(out,"0");
  fprintf(out,"%d:",h);
  if (m < 10) fprintf(out,"0");
  fprintf(out,"%d:",m);
  if (s < 10) fprintf(out,"0");
  fprintf(out,"%d",s);
}

/************************************************************************
*
* Same as function above, except prints in format HHhMMmSSs instead of 
* HH:MM:SS.
*
***********************************************************************/

void printTime2(FILE* out, long seconds)
{
  int h, m, s;
  h = (seconds / 3600);
  m = (seconds - (3600*h))/60;
  s = (seconds -(3600*h)-(m*60));
  if (h < 10) fprintf(out,"0");
  fprintf(out,"%dh",h);
  if (m < 10) fprintf(out,"0");
  fprintf(out,"%dm",m);
  if (s < 10) fprintf(out,"0");
  fprintf(out,"%ds",s);
}

/*********************************************************************
*
* Given the length of the array of Patient, will sort first by
* Pain highest to lowest, then age highest to lowest then finally time
* that the patient arrived highest to lowest.
*
**********************************************************************/

void initialSort(int length)
{
  struct Patient temp;
  int i;
  int j;

  for (i = 0; i < length; ++i)
  {
    for (j = 0; j <  length - 1; ++j)
    {
      if ((patients[j].pain < patients[j+1].pain)
          || (patients[j].pain == patients[j+1].pain
          &&  patients[j].age < patients[j+1].age) ||
             (patients[j].pain == patients[j+1].pain
          &&  patients[j].age == patients[j+1].age &&
              patients[j].time <  patients[j+1].time))
      {
        temp = patients[j];
        patients[j] = patients[j+1];
        patients[j+1] = temp;
      }
    }
  }
}
