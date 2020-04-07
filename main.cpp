/**
 * Made by Darclander :D 
 * Latest update 2020-04-07
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>

#include "human.h"


void printAll(Human *arr) {
    int arr2[10];
    for (int i = 0; i < 10; i++) {
        arr2[i] = arr[i].print(); 
    }
    std::sort(arr2, arr2+10);
    for (int i = 0; i < 10; i++) {
        std::cout << i+1 << ": " << arr2[i] << "\n";
    }
}

int decAll(Human *arr) {
    int canGive = 0;

    for (int i = 0; i < 10; i++) {
        if(arr[i].print()>0) {
            arr[i].decDollar();
            canGive += 1;
        }
    }
    return canGive;
}

/** 
 *  Increases a random persons stack with 1 as long as there 
 *  are enough dollars left to give
 */
void incRand(Human *arr, int canGive) {
    srand(time(NULL));
    int random;

    while(canGive > 0) {
        random = (rand() % 10 + 1) - 1;
        arr[random].incDollar();
        canGive -= 1;
    }
}

int main () {
    Human arr [10];
    // Total amount of cycles
    int x = 1000;
    for (int i = 0; i < 10; i++ ) {
        arr[i] = *new Human();
    }
    int canGive = 0;
    while(x > 0) {
        canGive = decAll(arr);
        incRand(arr, canGive);
        printAll(arr);
        x--;
    }

}