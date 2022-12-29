#pragma once
#include "asset.h"

namespace project {
  struct texture {    
    SDL_Texture* data = NULL;
    std::string filename;
    int height = 0;
    int width = 0;
  };

  struct texture_asset : asset {
    PROJECT_INLINE texture_asset() = default;

    PROJECT_INLINE ~texture_asset() { 
      SDL_DestroyTexture(instance.data);
    }

    texture instance;
  };
}