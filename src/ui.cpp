#include "headers/ui.h"

UI::UI() {

}


int UI::init(const char *title, int w, int h, bool fullscreen) {
    int flags = 0;

    if (fullscreen) {
        flags = SDL_WINDOW_FULLSCREEN;
    }

    if (SDL_Init(SDL_INIT_EVERYTHING) == 0) {
        window = SDL_CreateWindow(
                                    title,
                                    SDL_WINDOWPOS_CENTERED,
                                    SDL_WINDOWPOS_CENTERED,
                                    w,
                                    h,
                                    flags
        );
        renderer = SDL_CreateRenderer(window, -1, 0);

        if(renderer) {
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        }

        if(TTF_Init() != 0) {
            fprintf(stderr, "Couldn't init SDL_ttf: %s\n", TTF_GetError());
            return 1;
        }
        
    }


    return 0;
}

void UI::update() {

    const Uint8 *key_state = SDL_GetKeyboardState(NULL);

    if(key_state[SDL_SCANCODE_SPACE]) {
        // START || STOP
    }



}

void UI::render() {
    SDL_RenderPresent(renderer);
}

void UI::clearRenderer() {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}


void UI::clean() {
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}

int UI::handleEvents() {
    
    SDL_PollEvent(&event);

    switch (event.type) {
        case SDL_QUIT : 
            return 1;
            break;
        default:
            return 0;
            break;
    }

}

SDL_Renderer *UI::getRenderer() {
    return renderer;
}
