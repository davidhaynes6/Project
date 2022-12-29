#pragma once
#include "assets/asset.h"

namespace project::ecs {
  struct sprite_component {
    PROJECT_INLINE sprite_component(const sprite_component&) = default;
    PROJECT_INLINE sprite_component() = default;
    
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    asset_id sprite = INVALID_ID;
  };

  struct text_component {
    PROJECT_INLINE text_component(const text_component&) = default;
    PROJECT_INLINE text_component() = default;

    SDL_RendererFlip flip = SDL_FLIP_NONE;
    SDL_Color color = { 0, 0, 0, 255 };
    asset_id font = INVALID_ID;
    std::string text;
  };

  struct animation_component {
    PROJECT_INLINE animation_component(const animation_component&) = default;
    PROJECT_INLINE animation_component() = default;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    asset_id animation = INVALID_ID;
  };

  struct tilemap_component {
    PROJECT_INLINE tilemap_component(const tilemap_component&) = default;
    PROJECT_INLINE tilemap_component() = default;
    asset_id tilemap = INVALID_ID;
  };

  struct tile_component {
    PROJECT_INLINE tile_component(const tile_component&) = default;
    PROJECT_INLINE tile_component() = default;
    SDL_RendererFlip flip = SDL_FLIP_NONE;
    asset_id tilemap = INVALID_ID;
    asset_id tileset = INVALID_ID;
    float offset_x, offset_y = 0;
    int row, col = 0;
  };
}