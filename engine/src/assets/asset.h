#pragma once

namespace project {
  using asset_typeid = uint32_t;
  using asset_id = uuid64;

  struct asset {
        PROJECT_INLINE virtual ~asset() = default;
        asset_id id = generate_uuid();
        std::string name;
    };
}