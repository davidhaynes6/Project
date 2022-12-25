#pragma once

namespace project::inputs {
    PROJECT_API void initialize(SDL_Window*);
    PROJECT_API void dispatch_events();
    PROJECT_API bool is_key(int);
}