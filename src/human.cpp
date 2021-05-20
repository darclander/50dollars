/**
 * Made by Darclander :D 
 * Latest update 2020-04-07
 */

#include "headers/human.h"

Human::Human() {
    dollars = 50;
}

Human::Human(SDL_Renderer *r, int id) {
    dollars = 50;
    rend = r;
    this->id = id;
    moneySize.x = 1+id*100;
    moneySize.y = 700;
    moneySize.w = 50;
    moneySize.h = dollars;
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

void Human::update() {
    moneySize.h = -dollars*1.5;
}

void Human::draw() {
  SDL_SetRenderDrawColor(rend, 0, 255, 0, 255);
  SDL_RenderDrawRect(rend, &moneySize);
  SDL_RenderFillRect(rend, &moneySize);
}