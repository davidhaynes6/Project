#pragma once
#include "core/event.h"

namespace project {
  struct quit_event : event_instance {
    PROJECT_INLINE quit_event() = default;
  };

  struct keydown_event : event_instance {
    PROJECT_INLINE keydown_event(int key) : key(key) {}
    int key;
  };

  struct keyup_event : event_instance {
    PROJECT_INLINE keyup_event(int key) : key(key) {}
    int key;
  };

  struct keyrepeat_event : event_instance {
    PROJECT_INLINE keyrepeat_event(int key) : key(key) {}
    int key;
  };

  struct mousedown_event : event_instance {
    PROJECT_INLINE mousedown_event(int btn):button(btn) {}
    int button;
  };

  struct mouseup_event : event_instance {
    PROJECT_INLINE mouseup_event(int btn) : button(btn) {}
    int button;
  };

  struct mousemotion_event : event_instance {
    PROJECT_INLINE mousemotion_event() = default;
  };

  struct mousewheel_event : event_instance {
    PROJECT_INLINE mousewheel_event() = default;
  };
}