// Project: GalaEngine
// File: Tileset.hpp
// Description: Tileset class for holding tileset texture & information
// Authors: Colleen (@colleen05)
// https://github.com/colleen05/GalaEngine
// Distributed under the zlib license.

#pragma once

#include <raylib.h>
#include <cmath>
#include <string>

namespace GalaEngine {
    class Tileset {
        public:
            Texture texture{};
            int tileSize;

            Rectangle GetTileRect(int tileX, int tileY) const;
            Rectangle GetTileRect(int tileID) const;

            Tileset(Texture texture, int tileSize);
            Tileset();
    };
}