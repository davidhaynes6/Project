#pragma once
#include "entity.h"
#include <vector>

namespace project::ecs {
  struct system {
    PROJECT_INLINE virtual ~system() = default;

    PROJECT_INLINE void prepare(registry* rg, SDL_Renderer* rd) {
      this->_registry = rg;
      this->_renderer = rd;
    }
    
    template<typename T> 
    PROJECT_INLINE auto view() {
      std::vector<entity> entities;
      for(auto& e : _registry->view<T>()) {
        entities.push_back(entity(e, _registry));
      }
      return entities;
    }

    PROJECT_INLINE virtual void update(float) {}
    PROJECT_INLINE virtual void start() {}

  protected:
    SDL_Renderer* _renderer = NULL;
    registry* _registry = NULL;
  };
}