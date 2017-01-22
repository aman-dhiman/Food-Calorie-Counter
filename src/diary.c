#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "diary.h"

void initVar (double * typeCal, int * typeNum) {
    int i;
    for (i = 0; i < 5; i++) {
        typeCal[i] = 0;
        typeNum[i]= 0;
    }
}
void checkNumFood (int * numFood, int argc, char * argv) {
    FILE * infile;
    char tempStr[50];
    int i;
    i = 0;
    if (argc != 2) {
        printf ("Invalid number of inputs, exiting\n");
        exit(0);
    }
    infile = fopen (argv, "r");
    while (fgets (tempStr, 50, infile) != NULL) {
        i++;
    }
    *numFood = i;
    fclose (infile);
}

void readFile (char ** dataString, int argc, char * argv) {
    FILE * infile;
    char tempStr[50];
    int i, length;
    i = 0;

    infile = fopen (argv, "r");
    while (fgets (tempStr, 50, infile) != NULL) {
        length = strlen(tempStr);
        if (tempStr[length] == '\n') {
            tempStr[length] = '\0';
        }
        dataString[i] = malloc (sizeof (char) * (length + 1));
        strcpy (dataString[i], tempStr);
        i++;
    }
    fclose (infile);
}

Food * createList (char ** dataString, int numFood, double * totalCal,
                   double * typeCal, int * typeNum) {
    int i;
    Food * item;
    Food * list;
    char name[30];
    char group[15];
    char type;
    char * token;
    double calories;

    for (i = 0; i < numFood; i++) {
        token = strtok (dataString[i], ",");
        strcpy (name, token);
        token = strtok (NULL, ",");
        strcpy (group, token);
        token = strtok (NULL, ",");
        calories = atof (token);
        *totalCal = *totalCal + calories;
        token = strtok (NULL, ",");
        type = token[0];

        item = createRecord (name, group, calories, type);
        if (strcmp(group, "vegfruit") == 0) {
            typeCal[0] = typeCal[0] + calories;
            typeNum[0]++;
        }
        else if (strcmp(group, "meat") == 0) {
            typeCal[1] = typeCal[1] + calories;
            typeNum[1]++;
        }
        else if (strcmp(group, "dairy") == 0) {
            typeCal[2] = typeCal[2] + calories;
            typeNum[2]++;
        }
        else if (strcmp(group, "grains") == 0) {
            typeCal[3] = typeCal[3] + calories;
            typeNum[3]++;
        }
        else if (strcmp(group, "fat") == 0) {
            typeCal[4] = typeCal[4] + calories;
            typeNum[4]++;
        }
        if (i == 0) {
            list = item;
        }
        else if (i != 0) {
            if (type == 'j') {
                list = addToBack (list, item);
            }
            else if (type == 'h') {
                list = addToFront (list, item);
            }
        }
    }
    return list;
}

void printCalories (double totalCal, double * typeCal, int * typeNum) {
    int i, calTotal;
    calTotal = totalCal + 0.5;
    double average[5];

    for (i = 0; i < 5; i++) {
        average[i] = typeCal[i]/typeNum[i];
    }

    printf ("%d\n", calTotal);

    for (i = 0; i < 5; i++) {
        if (typeNum[i] != 0) {
            printf ("%.2f\n", average[i]);
        }
        else {
            printf ("0.00\n");
        }
    }

}
