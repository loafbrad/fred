#include <SDL.h>
#include <iostream>
#include <tuple>
#define PIX_WIDTH  720
#define PIX_HEIGHT 364
#define REFRESH    60
#define SPEED	   7890  //KHz
int mem[PIX_WIDTH][PIX_HEIGHT];

typedef struct {
    SDL_Window* w;
    SDL_Renderer* r;
} SDL_wr_t;

// Initializes SDL and creates a window
SDL_wr_t InitializeSDLandCreate(const char* windowName) {
    SDL_wr_t sdlWr;
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_EVENTS | SDL_INIT_TIMER) == -1 ) {
		std::cout << "Failed to initialize SDL: " << SDL_GetError() << std::endl;
		return {nullptr, nullptr};
	}

	sdlWr.w = SDL_CreateWindow(windowName,
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              PIX_WIDTH,
                              PIX_HEIGHT,
                              SDL_WINDOW_SHOWN);

	if (sdlWr.w == nullptr) {
		std::cout << "Failed to create window: " << SDL_GetError() << std::endl;
	}

	sdlWr.r = SDL_CreateRenderer(sdlWr.w, -1, (SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED));
    SDL_RenderSetLogicalSize(sdlWr.r, PIX_WIDTH, PIX_HEIGHT);

	if (sdlWr.r == nullptr) {
		std::cout << "Failed to create renderer : " << SDL_GetError();
	}

	return sdlWr;
}
