#pragma once
#include "asset.h"

namespace project {
  struct animation {
    std::vector<asset_id> frames;
    int speed = 100;
  };

  struct animation_asset : asset {
    PROJECT_INLINE animation_asset() = default;
    animation instance;
  }; 
}