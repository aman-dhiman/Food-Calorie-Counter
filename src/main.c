#include "diary.h"
#include <stdlib.h>
#include <stdio.h>

int main (int argc, char * argv[]) {
    char ** dataString;
    int numFood;
    numFood = 0;
    Food * list;
    int i;
    i = 0;
    double totalCal;
    double typeCal[5];
    int typeNum[5];
    totalCal = 0;

    initVar (typeCal, typeNum);

    checkNumFood (&numFood, argc, argv[1]);

    dataString = malloc (sizeof (char*) * numFood);

    readFile (dataString, argc, argv[1]);

    list = createList (dataString, numFood, &totalCal, typeCal, typeNum);

    printCalories (totalCal, typeCal, typeNum);

    printList (list);

    for (i = 0; i < numFood; i++) {
        free (dataString[i]);
    }
    free (dataString);
    destroyList (list);
    list = NULL;
    return 0;
}
