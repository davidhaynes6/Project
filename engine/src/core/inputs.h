#pragma once
#include "math/vec2.h"
#include "dispatcher.h"

namespace project::inputs
{
    struct mouse_state
    {
        std::bitset<7> buttons = {0};
        vec2f offset, wheel;
    };

    PROJECT_API const vec2f &mouse_offset();
    PROJECT_API const vec2f &mouse_wheel();
    PROJECT_API bool is_button(int);

    PROJECT_API void initialize(SDL_Window *);
    PROJECT_API dispatcher *get_dispatcher();
    PROJECT_API void dispatch_events();
    PROJECT_API bool is_key(int);
}