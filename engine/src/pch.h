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

#if defined(_DEBUG)
    #define PROJECT_LOG(level, message, ...) \
    fprintf(stderr, "[%s] ", level); \
    fprintf(stderr, message, ##__VA_ARGS__); \
    fprintf(stderr, "\n");

    #define PROJECT_WARNING(message, ...) PROJECT_LOG("warning", message, ##__VA_ARGS__)
    #define PROJECT_ERROR(message, ...) PROJECT_LOG("error", message, ##__VA_ARGS__)
    #define PROJECT_INFO(message, ...) PROJECT_LOG("info", message, ##__VA_ARGS__)
#else
    #define PROJECT_INFO
    #define PROJECT_ERROR
    #define PROJECT_WARNING
#endif

// runtime assertion
#define PROJECT_ASSERT assert

// static assertion
#if defined(__clang__) || defined(__gcc__)
    #define PROJECT_STATIC_ASSERT _STATIC_ASSERT
#else
    #define PROJECT_STATIC_ASSERT static_assert
#endif