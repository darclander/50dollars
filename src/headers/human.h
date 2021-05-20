/**
 * Made by Darclander :D 
 * 
 */

#include "SDL2/SDL.h"

class Human {

    public:
        Human();
        Human(SDL_Renderer *r, int id);
        void draw();
        void update();
        void incDollar();
        void decDollar();
        int print();


    private:
        int dollars;
        int id;
        SDL_Renderer *rend;
        SDL_Rect moneySize; // Has w, h, x, y
        int x, y;
    
};