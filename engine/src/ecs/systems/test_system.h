#include "ecs/system.h"
#include "ecs/components/common.h"

namespace project::ecs {
    struct test_system : system {
        void update(float dt) {
            for (auto e : view<transform_component>()) {
                auto& t = e.get_component<transform_component>();
                PROJECT_INFO("id:[%zd], x:%f", e.id(), t.translate.x++);
            }
        }
    };
}