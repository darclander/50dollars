/**
 * Made by Darclander :D 
 * 
 */

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <windows.h>

#include "headers/human.h"
#include "headers/ui.h"
#include "SDL2/SDL.h"

#define FPS 30
#define frameDelay = 1000 / FPS

void fpsCap(Uint32 starting_tick) {
    if ((1000 / FPS) > SDL_GetTicks() - starting_tick) {
        SDL_Delay(1000 / FPS - (SDL_GetTicks() - starting_tick));
    }
}


void printAll(Human *arr) {
    int arr2[10];
    for (int i = 0; i < 10; i++) {
        arr2[i] = arr[i].print(); 
    }
    // std::sort(arr2, arr2+10);
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

int main (int argc, char *argv[]) {
    UI ui = UI();
    ui.init("Test", 1680, 800, false);

    SDL_Renderer *r = ui.getRenderer();

    Human arr [10];

    // Total amount of cycles
    int x = 1000;
    for (int i = 0; i < 10; i++ ) {
        arr[i] = Human(r, i);
    }


    // Will be used for SDL_GetTicks(), see https://wiki.libsdl.org/SDL_GetTicks
    uint32_t startingTick;

    int canGive = 0;
    while(x > 0) {

        startingTick = SDL_GetTicks();

        if(ui.handleEvents()){
            return 0;
        }
        ui.clearRenderer();
        ui.update();
        for(int i = 0; i < 10; i++) {
            arr[i].update();
            arr[i].draw();
        }
        ui.render();

        canGive = decAll(arr);
        incRand(arr, canGive);
        printAll(arr);
        std::cout << std::endl;
        x--;

        fpsCap(startingTick);
    }

    // Cleanup
    for(int i = 0; i < 10; i++) {
        delete &arr[i];
    }

}

