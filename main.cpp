#include "sdl_env.cpp"
#include <iostream>
int main( int argc, char* args[] ) {
    SDL_wr_t sdlWr;
    const Uint8* keys;
    int* numKeys;
	sdlWr = InitializeSDLandCreate("My SDL Window");
     SDL_Event e;
    bool quit = false;
    SDL_Rect myRect = {
        50, 50,
        20, 20
    };
    int SDL_RenderFillRect(SDL_Renderer * renderer,
                       const SDL_Rect * rect);
    while (!quit){
       keys = SDL_GetKeyboardState(numKeys);
       if (keys[SDL_SCANCODE_LEFT]) {
        myRect.x--;
       }
       if (keys[SDL_SCANCODE_RIGHT]) {
        myRect.x++;
       }
       if (keys[SDL_SCANCODE_UP]) {
        myRect.y--;
       }
       if (keys[SDL_SCANCODE_DOWN]) {
        myRect.y++;
       }
       while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                quit = true;
            }
            if (e.type == SDL_MOUSEBUTTONDOWN){
                quit = true;
            }
        }
        mem[myRect.x][myRect.y] = 1;
        SDL_RenderClear(sdlWr.r);
        // TODO: Make this faster
        for (int x = 0; x < PIX_WIDTH; ++x) {
            for (int y = 0; y < PIX_HEIGHT; ++y) {
                SDL_SetRenderDrawColor(sdlWr.r, mem[x][y]*255, 0, 0, 255);
                SDL_RenderDrawPoint(sdlWr.r, x, y);
            }
        }
        SDL_RenderPresent(sdlWr.r);

        SDL_Delay(20);
    }

    // Destroy window
    SDL_DestroyWindow(sdlWr.w);

    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}