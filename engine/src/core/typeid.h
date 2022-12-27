#pragma once 

namespace project {
  PROJECT_INLINE const uint32_t get_unique_typeid() { 
    static uint32_t type = 1u;
    return type++; 
  }

	template<typename T>
	PROJECT_INLINE const uint32_t type_id() {
		static const uint32_t type = get_unique_typeid();
		return type;
	}
}