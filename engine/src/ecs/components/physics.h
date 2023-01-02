#pragma once 
#include "physics/rigidbody2.h"

namespace project::ecs {    
  struct rigidbody_component {
    PROJECT_INLINE rigidbody_component(const rigidbody_component&) = default;
    PROJECT_INLINE rigidbody_component() = default;
    bool disabled = false;
    rigidbody2 body;  
  };

  struct collider_component {
    PROJECT_INLINE collider_component(const collider_component&) = default;
    PROJECT_INLINE collider_component() = default;
    SDL_FRect collider = { 0.0f, 0.0f, 64.0f, 64.0f };   
    bool disabled = false;  
  };

  struct tag_component {
    PROJECT_INLINE tag_component(const tag_component&) = default;
    PROJECT_INLINE tag_component() = default;
    std::string tag;
  };
}