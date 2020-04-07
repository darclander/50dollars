/**
 * Made by Darclander :D 
 * Latest update 2020-04-07
 */

#include "human.h"

Human::Human() {
    dollars = 50;
}

void Human::incDollar() {
    dollars += 1;
}

void Human::decDollar() {
    dollars -= 1;
}

int Human::print() {
    return dollars;
}