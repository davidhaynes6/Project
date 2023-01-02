#pragma once
#include "math/vec2.h"

namespace project {
  struct rigidbody2 {
    PROJECT_INLINE void set_force(const vec2f& f) { force = f; }
    PROJECT_INLINE void set_force_x(float x) { force.x = x; }
    PROJECT_INLINE void set_force_y(float y) { force.y = y; }

    float gravity_scale = 0.0f;
    vec2f velocity;
    vec2f force;
  };
}