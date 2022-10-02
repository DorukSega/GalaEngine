// Project: GalaEngine
// File: AssetManager.hpp
// Description: Asset managing class for auto loading and unloading
// Authors: Colleen (@colleen05)
// https://github.com/colleen05/GalaEngine
// Distributed under the zlib license.

#pragma once

#include <raylib.h>
#include <string>
#include <map>

namespace GalaEngine {
    struct AssetPathLayout {
        std::string base,
                    textures,
                    sounds,
                    fonts;
    };

    class AssetManager {
        public:
            // Layout
            AssetPathLayout pathLayout;

            // Containers
            std::map<std::string, Texture>  textures;
            std::map<std::string, Sound>    sounds;
            std::map<std::string, Font>     fonts;

            // Getters
            Texture GetTexture  (const std::string& name);
            Sound   GetSound    (const std::string& name);
            Font    GetFont     (const std::string& name);

            // Loading
            Texture LoadTexture (const std::string& name, const std::string& path);
            Sound   LoadSound   (const std::string& name, const std::string& path);
            Font    LoadFont    (const std::string& name, const std::string& path);

            // Unloading
            void UnloadTexture  (const std::string& name);
            void UnloadSound    (const std::string& name);
            void UnloadFont     (const std::string& name);

            void UnloadAllTextures  ();
            void UnloadAllSounds    ();
            void UnloadAllFonts     ();
            
            void UnloadAll();

            // Constructor
             explicit AssetManager(AssetPathLayout pathLayout = {
                "./base/",
                "./textures/",
                "./sounds/",
                "./fonts/"
            });
    };
}