#include "sdl_env.cpp"
#include <iostream>
int sample_n = 0;

void fred_audio(void *data, Uint8 *stream, int len) {
  const int tone = 440; // A4
  const int sample_rate = 44100;
  const int amp = 7000;
  float freq = (float)tone;
  Sint16* buf = (Sint16*)stream;
  for(int i = 0; i < len/2; i++) { 
    buf[i] = amp*cos(2*M_PI*freq*(((float)sample_n)/sample_rate));
    sample_n = (sample_n < sample_rate) ? sample_n + 1 : 0;
  }
};

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
    int numAudioDevices = SDL_GetNumAudioDevices(0);
    SDL_zero(audio_spec_desired);
    audio_spec_desired.freq = 44100;
    // Signed 16-bit little-endian samples
    audio_spec_desired.format = AUDIO_S16LSB;
    audio_spec_desired.channels = 1;
    audio_spec_desired.samples = 4096;
    audio_spec_desired.callback = fred_audio;
    SDL_AudioDeviceID audio_dev = SDL_OpenAudioDevice(NULL, 0, &audio_spec_desired, &audio_spec_obtained, SDL_AUDIO_ALLOW_ANY_CHANGE);
    while (!quit){
       keys = SDL_GetKeyboardState(numKeys);
       // Pressing left key plays audio
       if (keys[SDL_SCANCODE_LEFT]) {
        myRect.x--;
        SDL_PauseAudioDevice(audio_dev, 0);
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

    SDL_CloseAudioDevice(audio_dev);
    // Quit SDL subsystems
    SDL_Quit();

    return 0;
}