#pragma once
#include "asset.h"

namespace project {
  struct tilemap {
    std::set<asset_id> tilesets;
    int col_count = 0;
    int row_count = 0;
    int tilesize = 0;
  };

  struct tilemap_asset : asset {
    PROJECT_INLINE tilemap_asset() = default;
    tilemap instance;
  };
}