#include "linkedList.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Food * createRecord (char * name, char * group, double calories, char theType) {
    Food * foodItem;
    foodItem = malloc (sizeof (Food));
    if (foodItem != NULL) {
        foodItem->name = malloc (sizeof (char) * (strlen(name)+1));
        strcpy (foodItem->name, name);
        foodItem->foodGroup = malloc (sizeof (char) * (strlen(group)+1));
        strcpy (foodItem->foodGroup, group);
        foodItem->calories = calories;
        foodItem->type = theType;
        foodItem->next = NULL;
        return foodItem;
    }
    else {
        return NULL;
    }
}

char * printRecord (Food * toPrint) {
    char * printStr;
    char calStr[20];
    sprintf (calStr, "%.2f", toPrint->calories);
    printStr = malloc (sizeof (char) * (strlen(toPrint->name) + strlen(toPrint->foodGroup) +
               strlen(calStr) + 8));
    sprintf (printStr, "%s (%s):%s[%c]", toPrint->name, toPrint->foodGroup, calStr,
                                         toPrint->type);
    return printStr;
}

void destroyElement (Food * theElement) {
    free (theElement->name);
    free (theElement->foodGroup);
}

Food * addToFront (Food * theList, Food * toBeAdded) {
    toBeAdded->next = theList;
    theList = toBeAdded;
    return theList;
}

Food * addToBack (Food * theList, Food * toBeAdded) {
    Food * temp;
    temp = theList;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = toBeAdded;
    return theList;
}

Food * removeFromFront (Food * theList) {
    if (theList == NULL) {
        return NULL;
    }
    Food * foodPtr;
    foodPtr = theList;
    theList = theList->next;
    foodPtr->next = NULL;
    destroyElement (foodPtr);
    free (foodPtr);
    return theList;
}

Food * removeFromBack (Food * theList) {
    if (theList == NULL) {
        return NULL;
    }
    Food * lastItem;
    Food * curItem;
    curItem = theList;
    while (curItem->next->next != NULL) {
        curItem = curItem->next;
    }
    lastItem = curItem->next;
    curItem->next = NULL;
    lastItem->next = NULL;
    destroyElement (lastItem);
    free (lastItem);
    return theList;
}

Food * getLastItem (Food * theList) {
    if (theList == NULL) {
        return NULL;
    }
    Food * lastItem;
    lastItem = theList;
    while (lastItem->next != NULL) {
        lastItem = lastItem->next;
    }
    return lastItem;
}

bool isEmpty (Food * theList) {
    if (theList == NULL) {
        return true;
    }
    else {
        return false;
    }
}

void printList (Food * theList) {
    if (theList == NULL) {
        printf("list is empty\n");
        return;
    }
    Food * temp;
    char * str;
    temp = theList;
    while (temp->next != NULL) {
        str = printRecord (temp);
        printf ("%s\n", str);
        temp = temp->next;
    }
    str = printRecord (temp);
    printf ("%s\n", str);
}

void destroyList (Food * theList) {
    if (theList == NULL) {
        return;
    }
    Food * temp;
    Food * cur;
    cur = theList;
    while (cur != NULL) {
        temp = cur;
        cur = cur->next;
        destroyElement (temp);
        free (temp);
    }
}
