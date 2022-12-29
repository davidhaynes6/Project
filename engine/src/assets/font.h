#pragma once
#include "asset.h"

namespace project {
  struct font {
    TTF_Font* data = NULL;
    std::string filename;
    int size = 20;
  };

  struct font_asset : asset {
    PROJECT_INLINE font_asset() = default;
    PROJECT_INLINE ~font_asset() {
      TTF_CloseFont(instance.data);
    }

    font instance;
  };
}