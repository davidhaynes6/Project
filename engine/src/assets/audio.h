#pragma once
#include "asset.h"

namespace project {
  struct audio_clip {
    Mix_Chunk* data = NULL;
    std::string filename;
  };

  struct audio_asset : asset {
    PROJECT_INLINE audio_asset() = default;

    PROJECT_INLINE ~audio_asset() {
    Mix_FreeChunk(instance.data);
    }

    audio_clip instance;
  };
}