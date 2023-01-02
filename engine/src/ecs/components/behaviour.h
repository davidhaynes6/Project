#pragma once
#include "scripts/script_instance.h"

namespace project::ecs {
  struct script_component {
    PROJECT_INLINE script_component(const script_component&) = default;
    PROJECT_INLINE script_component() = default;

    template<typename T>
    PROJECT_INLINE void bind() { 
      instantiate = [](const script_props& props) { 
        auto script = static_cast<script_instance*>(new T());         
        script->init(props);
        return script;
      };    
    }   

    script_instance* instance = NULL;
    script_instantiator instantiate;
    std::string name;
  };
}