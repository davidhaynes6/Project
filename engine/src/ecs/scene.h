#pragma once
#include "ecs/systems/text_render_system.h"

namespace project::ecs
{
    struct scene
    {
        PROJECT_INLINE scene(SDL_Renderer *rd) : _renderer(rd)
        {
            register_system<ecs::text_renderer_system>();
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
            SDL_SetRenderDrawColor(_renderer, 255, 255, 255, 255);
            for (auto &sys : _systems)
            {
                sys->update(dt);
            }
        }

        PROJECT_INLINE void start()
        {
            // load texture asset
            auto font = _assets.load_font("assets/font.ttf", "ft", 30);

            // add entity with text component
            ecs::entity entity = add_entity("entity");

            auto &tx = entity.add_component<ecs::text_component>();
            tx.text = "This is a text!";
            tx.font = font->id;

            // start systems
            for (auto &sys : _systems)
            {
                sys->start();
            }
        }

        template <typename T>
        PROJECT_INLINE void register_system()
        {
            // PROJECT_STATIC_ASSERT(std::is_base_of < ecs::system, <T>::value);
            auto new_system = new T();
            new_system->prepare(&_registry, _renderer, &_assets);
            this->_systems.push_back(new_system);
        }

    private:
        std::vector<ecs::system *> _systems;
        SDL_Renderer *_renderer = NULL;
        ecs::registry _registry;
        asset_registry _assets;
    };
}