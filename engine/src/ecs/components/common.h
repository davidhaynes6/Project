#pragma once
#include "math/vec2.h"

namespace project::ecs {
  struct info_component {
    PROJECT_INLINE info_component(const info_component&) = default;
    PROJECT_INLINE info_component() = default;

    uuid64 uuid = generate_uuid();
    std::string name = "entity";
    std::string tag = "default";
  };

  struct transform_component {
    PROJECT_INLINE transform_component(const transform_component&) = default;
    PROJECT_INLINE transform_component() = default;

    vec2f translate = vec2f(0.0f);
    vec2f scale = vec2f(1.0f);
    float rotation = 0.0f;
  };
}