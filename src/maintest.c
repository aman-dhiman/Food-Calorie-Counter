#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

int main() {
    char names[][15] = {"chips", "cake", "carrots", "cabbage"};
    char groups[][15] = {"fat", "dairy", "veggie", "veggie"};
    char type[4] = {'j','j','h','h'};
    double calories[4] = {200.2355, 342.2134, 100, 150.23};
    Food * list;
    int empty;
    Food *  item;
    char * str;
    for (int i = 0; i < 4; i++) {
        item = createRecord (names[i], groups[i], calories[i], type[i]);
        if (i == 0) {
            list = item;
        }
        if (i == 1) {
            list = addToBack (list, item);
        }
        if(i == 2 || i == 3) {
            list = addToFront (list, item);
        }
    }
    printList (list);
    empty = isEmpty(list);
    if (empty == false) {
    printf("False\n");
    }
    list = removeFromFront(list);
    printList(list);
    list = removeFromBack(list);
    printList(list);
    item = getLastItem(list);
    str = printRecord(item);
    printf("%s\n", str);
    destroyList(list);
    list = NULL;
//    printList(list);
    printList(list);
    empty = isEmpty(list);
    printf("%d\n",empty);
    if (empty == true) {
    printf("True\n");
    }
    return 0;
}
