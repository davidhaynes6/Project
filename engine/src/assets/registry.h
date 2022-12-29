#pragma once
#include "font.h"
#include "audio.h"
#include "tilemap.h"
#include "texture.h"
#include "animation.h"
#include "core/typeid.h"

namespace project {
  struct asset_registry {
    PROJECT_INLINE asset_registry() = default;

    PROJECT_INLINE void clear() { 
      for(auto& [_, list] : _data){
        for(auto a : list) { PROJECT_DELETE(a); }
      }
      _data.clear(); 
    }

    template <typename T>
    PROJECT_INLINE T* get(asset_id id) {
      PROJECT_STATIC_ASSERT(std::is_base_of<asset, T>::value);
      const auto type = type_id<T>();
      if(!_data.count(type)) { return NULL; }

      for(auto& asset : _data.at(type)) {
        if(asset->id == id) { return static_cast<T*>(asset); }
      }
      return NULL;
    }

     template <typename T>
    PROJECT_INLINE T* get(const std::string& name) {
      asset_id id = get_id<T>(name);
      PROJECT_STATIC_ASSERT(std::is_base_of<asset, T>::value);
      const auto type = type_id<T>();
      if(!_data.count(type)) { 
        return NULL; 
      }

      for(auto& asset : _data.at(type)) {
        if(asset->id == id) { 
            return static_cast<T*>(asset); 
        }
      }
      return NULL;
    }

    template<typename T>
    PROJECT_INLINE asset_id get_id(const std::string& name) {
      PROJECT_STATIC_ASSERT(std::is_base_of<asset, T>::value);
      const auto type = type_id<T>();
      if(!_data.count(type)) { 
        return INVALID_ID; 
      }

      for(auto& asset : _data.at(type)) {
        if(!asset->name.compare(name)) { 
            return asset->id; 
        }
      }
      return INVALID_ID;
    }  

    template <typename T>
    PROJECT_INLINE T* add(const std::string& name) {
      auto asset = new T();
      asset->name = name;
      _data[type_id<T>()].push_back(asset);
      return asset;
    }  

    
    PROJECT_INLINE texture_asset* load_texture(const std::string& src, const std::string& name, SDL_Renderer* rd) {
      texture texture;
      texture.data = IMG_LoadTexture(rd, src.c_str());
      texture.filename = src;

      if (!texture.data) {
        PROJECT_ERROR("%s", IMG_GetError());
        return NULL;
      }      
      
      SDL_QueryTexture(texture.data, NULL, NULL, &texture.width, &texture.height);
      auto asset = new texture_asset();
      asset->instance = texture;
      asset->name = name;

      _data[type_id<texture_asset>()].push_back(asset);
      return asset;
    }

    PROJECT_INLINE font_asset* load_font(const std::string& src, const std::string& name, int size) {
      font font;
      font.data = TTF_OpenFont(src.c_str(), size);
      font.filename = src;
      font.size = size;

      if (!font.data) {
        PROJECT_ERROR("%s", IMG_GetError());
        return NULL;
      }

      auto asset = new font_asset();
      asset->instance = font;
      asset->name = name;

      _data[type_id<font_asset>()].push_back(asset);
      return asset;
    }

    PROJECT_INLINE audio_asset* load_audio(const std::string& src, const std::string& name) {
      audio_clip audio;
      audio.data = Mix_LoadWAV(src.c_str());
      audio.filename = src;

      if (!audio.data) {
        PROJECT_ERROR("%s", IMG_GetError());
        return NULL;
      }

      auto asset = new audio_asset();
      asset->instance = audio;
      asset->name = name;

      _data[type_id<audio_asset>()].push_back(asset);
      return asset;
    }

  private:
    friend struct asset_serializer;
    std::unordered_map<asset_typeid, std::vector<asset*>> _data;
  };
}