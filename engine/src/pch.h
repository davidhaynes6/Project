#pragma once

// std libs
#include <set>
#include <random>
#include <limits>
#include <vector>
#include <string>
#include <bitset>
#include <cassert>
#include <memory>
#include <sstream>
#include <fstream>
#include <assert.h>
#include <iostream>
#include <algorithm>
#include <functional>
#include <unordered_map>

// SDL2 libraries
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>
#include <SDL2/SDL_image.h>

// export api
#ifdef PROJECT_EXPORT
    #ifdef _MSC_VER
        #define PROJECT_API __declspec(dllexport)
    #else
        #define PROJECT_API __attribute__((visibility("default")))
    #endif
#else
    #ifdef _MSC_VER
        #define PROJECT_API __declspec(dllimport)
    #else
        #define PROJECT_API
    #endif
#endif
