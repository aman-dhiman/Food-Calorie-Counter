#ifndef _DHIMANA_DAIRYH
#define _DHIMANA_DAIRYH
#include "linkedList.h"

void initVar (double * typeCal, int * typeNum);
void checkNumFood (int * numFood, int argc, char * argv);
void readFile (char ** dataString, int argc, char * argv);
Food * createList (char ** dataString, int numFood, double * totalCal,
                   double * typeCal, int * typeNum);
void printCalories (double totalCal, double * typeCal, int * typeNum);
#endif