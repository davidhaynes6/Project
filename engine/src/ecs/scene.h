#pragma once
#include "systems/test_system.h"

namespace project::ecs
{
    struct scene
    {
        PROJECT_INLINE scene(SDL_Renderer *rd) : _renderer(rd)
        {
            register_system<ecs::test_system>();
        }

        PROJECT_INLINE ~scene()
        {
            for (auto &s : _systems)
            {
                PROJECT_DELETE(s);
            }
            _registry.clear();
            _systems.clear();
        }

        PROJECT_INLINE ecs::entity add_entity(const std::string &name)
        {
            auto entity = ecs::entity(&_registry);
            entity.add_component<info_component>().name = name;
            entity.add_component<transform_component>();
            return entity;
        }

        PROJECT_INLINE void update(float dt)
        {
            for (auto &sys : _systems)
            {
                sys->update(dt);
            }
        }

        PROJECT_INLINE void start()
        {
            auto e = this->add_entity("test");
            e.add_component<transform_component>();
            for (auto &sys : _systems)
            {
                sys->start();
            }
        }

        template <typename T>
        PROJECT_INLINE void register_system()
        {
            //PROJECT_STATIC_ASSERT(std::is_base_of < ecs::system, <T>::value);
            auto new_system = new T();
            new_system->prepare(&_registry, _renderer);
            this->_systems.push_back(new_system);
        }

    private:
        std::vector<ecs::system *> _systems;
        SDL_Renderer *_renderer = NULL;
        ecs::registry _registry;
    };
}