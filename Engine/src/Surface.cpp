#include <GalaEngine/Surface.hpp>

// Point
void GalaEngine::Surface::DrawPixel(int x, int y, Colour colour) const {
    BeginTextureMode(renderTexture);
    ::DrawPixel(x, y, colour);
    EndTextureMode();
}

void GalaEngine::Surface::DrawLine(int x1, int y1, int x2, int y2, Colour colour) const {
    BeginTextureMode(renderTexture);
    ::DrawLine(x1, y1, x2, y2, colour);
    EndTextureMode();
}

void GalaEngine::Surface::DrawLine(int x1, int y1, int x2, int y2, float thickness, Colour colour) const {
    BeginTextureMode(renderTexture);
    ::DrawLineEx(
        {(float)x1, (float)y1},
        {(float)x2, (float)y2},
        thickness, colour
    );
    EndTextureMode();
}

// Primitives
void GalaEngine::Surface::DrawRectangle(int x, int y, int width, int height, Colour colour, bool outline, float thickness) const {
    BeginTextureMode(renderTexture);

    if(outline){
        if(thickness >= 0.0f) { // Draw inner outline
            ::DrawRectangleLinesEx(
                Rectangle {
                    (float) x, (float) y,
                    (float) width, (float) height
                },
                thickness,
                colour
            );
        }else { // Draw outer outline
            ::DrawRectangleLinesEx(
                Rectangle {
                    (float) x + thickness, (float) y + thickness,
                    (float) width - thickness * 2.0f, (float) height - thickness * 2.0f
                },
                -thickness,
                colour
            );
        }
    }else {
        ::DrawRectangle(x, y, width, height, colour);
    }

    EndTextureMode();
}

void GalaEngine::Surface::DrawRectangle(int x, int y, int width, int height, float rotation, Vector2 origin, Colour colour) const {
    BeginTextureMode(renderTexture);
    ::DrawRectanglePro(
        Rectangle {
            (float)x, (float)y,
            (float)width, (float)height
        },
        origin, rotation, colour
    );
    EndTextureMode();
}

void GalaEngine::Surface::DrawRectangleColours(int x, int y, int width, int height, Colour c1, Colour c2, Colour c3, Colour c4) const {
    BeginTextureMode(renderTexture);
    ::DrawRectangleGradientEx(
        Rectangle {
            (float)x, (float)y,
            (float)width, (float)height
        },
        c1, c2, c3, c4
    );
    EndTextureMode();
}

void GalaEngine::Surface::DrawRectangleRounded(int x, int y, int width, int height, float radius, Colour colour, bool outline, float thickness) const {
    if(outline && thickness == 0.0f) return;
    
    BeginTextureMode(renderTexture);

    float roundness = (2.0f * radius) / static_cast<float>(std::min(width, height));
    roundness = Clamp(roundness, 0.0f, 1.0f);

    if(outline){
        if(thickness >= 0.0f) { // Draw inner outline
            ::DrawRectangleRoundedLines(
                Rectangle {
                    (float) x + thickness, (float) y + thickness,
                    (float) width - thickness * 2.0f, (float) height - thickness * 2.0f
                },
                roundness, 16,
                thickness,
                colour
            );
        }else { // Draw outer outline
            ::DrawRectangleRoundedLines(
                Rectangle {
                    (float) x, (float) y,
                    (float) width, (float) height
                },
                roundness, 16,
                -thickness,
                colour
            );
        }
    }else {
        ::DrawRectangleRounded(
                Rectangle {
                    (float) x, (float) y,
                    (float) width, (float) height
                },
                roundness, 16,
                colour
        );
    }

    EndTextureMode();
}

void GalaEngine::Surface::DrawCircle(int x, int y, float radius, Colour colour, bool outline, float thickness) const {
    BeginTextureMode(renderTexture);

    if(outline) {
        ::DrawRing(
            {(float)x, (float)y},
            radius - thickness,
            radius,
            0.0f, 360.0f,
            128.0f,
            colour
        );
    }else {
        ::DrawCircle(x, y, radius, colour);
    }

    EndTextureMode();
}

void GalaEngine::Surface::DrawCircle(int x, int y, float radius, Colour innerColour, Colour outerColour) const {
    BeginTextureMode(renderTexture);
    ::DrawCircleGradient(x, y, radius, innerColour, outerColour);
    EndTextureMode();
}

void GalaEngine::Surface::DrawEllipse(int x, int y, float radiusH, float radiusV, Colour colour, bool outline, float thickness) const {
    if(outline && thickness == 0.0f) return;
    
    BeginTextureMode(renderTexture);
    
    if(outline) {
        if(thickness > std::min(radiusH, radiusV)) { // Draw solid ellipse
            ::DrawEllipse(x, y, radiusH, radiusV, colour);
        }else if(thickness == 1.0f) { // Draw single outline
            ::DrawEllipseLines(x, y, radiusH, radiusV, colour);
        }else {
            if(thickness > 0.0f) { // Draw inner outline
                for(int i = 0; static_cast<float>(i) < thickness * 2; i++) {
                    ::DrawEllipseLines(x, y, radiusH - static_cast<float>(i) / 2.0f, radiusV - (float)(i) / 2.0f, colour);
                }
            }else { // Draw outer outline
                for(int i = 0; static_cast<float>(i) < -thickness * 2; i++) {
                    ::DrawEllipseLines(x, y, radiusH + static_cast<float>(i) / 2.0f, radiusV + (float)(i) / 2.0f, colour);
                }
            }
        }
    }else {
        ::DrawEllipse(x, y, radiusH, radiusV, colour);
    }
    
    EndTextureMode();
}

void GalaEngine::Surface::DrawTriangle(int x1, int y1, int x2, int y2, int x3, int y3, Colour colour, bool outline) const {
    BeginTextureMode(renderTexture);
    
    if(outline){
        ::DrawTriangleLines(
            {(float) x1, (float) y1},
            {(float) x2, (float) y2},
            {(float) x3, (float) y3},
            colour
        );
    }else {
        ::DrawTriangle(
            {(float) x1, (float) y1},
            {(float) x2, (float) y2},
            {(float) x3, (float) y3},
            colour
        );
    }

    EndTextureMode();
}

// Text
void GalaEngine::Surface::DrawText(const std::string& text, int x, int y, int size, Colour colour) const {
    BeginTextureMode(renderTexture);
    ::DrawText(text.c_str(), x, y, size, colour);
    EndTextureMode();
}

// Textures
void GalaEngine::Surface::DrawTexture(Texture texture, int x, int y, float scaleX, float scaleY, float rotation, Vector2 origin, Colour blendColour) const {
    BeginTextureMode(this->renderTexture);
    ::DrawTexturePro(
            texture,
            Rectangle {
            0.0f, 0.0f,
            (float) texture.width,
            (float) texture.height
        },
            Rectangle {
                    (float)x,
                    (float)y,
                    static_cast<float>(texture.width) * scaleX,
                    static_cast<float>(texture.height) * scaleY
        },
            Vector2Multiply(origin, {scaleX, scaleY}),
            rotation,
            blendColour
    );
    EndTextureMode();
}

void GalaEngine::Surface::DrawTexture(Texture texture, int x, int y, float scaleX, float scaleY, float rotation, Colour blendColour) const {
    BeginTextureMode(this->renderTexture);
    DrawTexture(texture, x, y, scaleX, scaleY, rotation, {0.0f, 0.0f}, blendColour);
    EndTextureMode();
}

void GalaEngine::Surface::DrawTexture(Texture texture, Rectangle src, Rectangle dest, Colour blendColour) const {
    BeginTextureMode(this->renderTexture);
    ::DrawTexturePro(
        texture,
        src,
        dest,
        {0.0f, 0.0f},
        0.0f,
        blendColour
    );
    EndTextureMode();
}

// Sprites
void GalaEngine::Surface::DrawSprite(Sprite sprite, int frame, int x, int y, float scaleX, float scaleY, float rotation, Colour blendColour) const {
    BeginTextureMode(renderTexture);
    ::DrawTexturePro(
        sprite.texture,
        sprite.frameRects[frame],
        Rectangle {
            (float)x,
            (float)y,
            sprite.frameRects[frame].width * scaleX,
            sprite.frameRects[frame].height * scaleY
        },
        Vector2Multiply(sprite.origin, {scaleX, scaleY}),
        rotation,
        blendColour
    );
    EndTextureMode();
}

void GalaEngine::Surface::Clear(Colour colour) const {
    BeginTextureMode(renderTexture);
    ClearBackground(colour);
    EndTextureMode();
}

void GalaEngine::Surface::Clear() {
    BeginTextureMode(renderTexture);
    ClearBackground(clearColour);
    EndTextureMode();
}

Image GalaEngine::Surface::GetImage() const {
    Image img = LoadImageFromTexture(renderTexture.texture);
    ImageFlipVertical(&img);

    return img;
}

void GalaEngine::Surface::Destroy() {
    UnloadRenderTexture(renderTexture);
    renderTexture.id = 0;
}

GalaEngine::Surface::Surface(int width, int height, Colour colour) {
    renderTexture = LoadRenderTexture(width, height);
    clearColour = colour;
}

GalaEngine::Surface::Surface() = default;