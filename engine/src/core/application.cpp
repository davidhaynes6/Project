#include "pch.h"
#include "inputs.h"
#include "application.h"


namespace project
{
    static bool is_running = true;

    PROJECT_API void run_application(const app_config &config)
    {
        // init SDL
        if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
            PROJECT_ERROR("%s", SDL_GetError());
            exit(EXIT_FAILURE);
        }
        // init SDL_image
        if (IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG) < 0) {
            PROJECT_ERROR("%s", IMG_GetError());
        }
        // init SDL_ttf
        if(TTF_Init() < 0) { 
            PROJECT_ERROR("%s", TTF_GetError());         
        }
        // init SDL_mixer
        if (Mix_Init(MIX_INIT_MP3 | MIX_INIT_OGG) < 0 || 
            Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 512)) {
            PROJECT_ERROR("%s", Mix_GetError());
        }

        // create window
        auto w_flags = (SDL_WindowFlags)(SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
        SDL_Window* window = SDL_CreateWindow(config.title.c_str(), SDL_WINDOWPOS_CENTERED, 
        SDL_WINDOWPOS_CENTERED, config.width, config.height, w_flags);

        // create renderer 
        auto r_flags = (SDL_RendererFlags)(SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        auto renderer = SDL_CreateRenderer(window, -1, r_flags);
        if (!window || !renderer) {
            PROJECT_ERROR("%s", SDL_GetError());
            exit(EXIT_FAILURE);
        }

        while (is_running) { 
            inputs::dispatch_events();
            if(inputs::is_key(SDL_SCANCODE_A)) {
                PROJECT_INFO("Key 'a' pressed!");
            }
            SDL_RenderClear(renderer);
            SDL_RenderPresent(renderer);
        }
    }
}