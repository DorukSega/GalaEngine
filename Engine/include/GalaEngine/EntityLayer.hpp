// Project: GalaEngine
// File: EntityLayer.hpp
// Description: Inherited class from Layer which supports entity updating and rendering
// Authors: Colleen (@colleen05)
// https://github.com/colleen05/GalaEngine
// Distributed under the zlib license.

#pragma once

#include <GalaEngine/Layer.hpp>
#include <GalaEngine/Entity.hpp>
#include <algorithm>

namespace GalaEngine {
    class EntityLayer : public Layer {
        protected:
            std::vector<GalaEngine::Entity*> _entities;

        public:
            void AddEntity(GalaEngine::Entity *entity);
            void RemoveEntity(GalaEngine::Entity *entity);

            void OnStart() override;
            void OnUpdate() override;
            void OnDraw(GalaEngine::Camera camera) override;
            void OnDestroy() override;

            EntityLayer(int width, int height, Colour clearColour);
            EntityLayer();
    };
}