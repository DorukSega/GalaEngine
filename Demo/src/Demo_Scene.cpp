#include <Demo_Scene.hpp>

void Demo_Scene::OnLoad() {
    scene->Resize(2048, 1152);

    tex_bgSky = LoadTexture("./res/tex/bg_clouds.png");
    tex_bgOverlay = LoadTexture("./res/tex/bg_clouds_overlay.png");

    scene->mainCamera.position  = {0.0f, 0.0f};
    scene->mainCamera.size      = {1024.0f, 576.0f};

    tex_sprFlower = LoadTexture("./res/tex/spr_flower.png");
    spr_flower = GalaEngine::Sprite {
        tex_sprFlower,
        {0.0f, 0.0f},
        {
            {0.0f,  0.0f,   64.0f, 64.0f},
            {64.0f, 0.0f,   64.0f, 64.0f},
            {0.0f,  64.0f,  64.0f, 64.0f},
            {64.0f, 64.0f,  64.0f, 64.0f}
        }
    };

    lay_background0 = scene->AddBackgroundLayer(tex_bgSky, C_BLACK);
    lay_background0->scrollSpeed = {32.0f, 12.0f};

    ts_test.texture = LoadTexture("./res/tex/ts_testtiles.png");
    ts_test.tileSize = 64;

    std::vector<uint16_t> tiles = {
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x47, 0x48, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x57, 0x58, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x61, 0x61, 0x61, 0x61, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x25, 0x26, 0x21, 0x61, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x35, 0x36, 0x21, 0x61, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x63, 0x64, 0x61, 0x63, 0x64, 0x63, 0x64, 0x61, 0x61, 0x61, 0x63, 0x64, 0x61, 0x63, 0x64, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x21, 0x23, 0x24, 0x21, 0x21, 0x21, 0x23, 0x24, 0x23, 0x24, 0x21, 0x21, 0x23, 0x24, 0x21, 0x21, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
        0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    };

    lay_tiles = scene->AddTileLayer(ts_test, tiles, 32, 18);

    lay_entities = scene->AddEntityLayer();
    
    ent_flower0 = new Ent_Flower(360, 256);
    ent_flower0->sprite = &spr_flower;
    ent_flower0->spriteFrame = 0;
    scene->PushEntity(ent_flower0, "flower_0");
    lay_entities->AddEntity(ent_flower0);

    ent_flower1 = new Ent_Flower(440, 256);
    ent_flower1->sprite = &spr_flower;
    ent_flower1->spriteFrame = 1;
    scene->PushEntity(ent_flower1, "flower_1");
    lay_entities->AddEntity(ent_flower1);

    ent_flower2 = new Ent_Flower(520, 256);
    ent_flower2->sprite = &spr_flower;
    ent_flower2->spriteFrame = 2;
    scene->PushEntity(ent_flower2, "flower_2");
    lay_entities->AddEntity(ent_flower2);

    ent_flower3 = new Ent_Flower(600, 256);
    ent_flower3->sprite = &spr_flower;
    ent_flower3->spriteFrame = 3;
    scene->PushEntity(ent_flower3, "flower_3");
    lay_entities->AddEntity(ent_flower3);

    lay_foreground = scene->AddBackgroundLayer(tex_bgOverlay, C_CLEAR);
    lay_foreground->scrollSpeed = {96.0f * 10.0f, -48.0f * 10.0f};
    lay_foreground->blendColour = {0xff, 0xff, 0xff, 0xff};
}

void Demo_Scene::OnDraw() {
    scene->RenderLayers();

    window->surface.DrawText("FPS: " + std::to_string(1.0f / GetFrameTime()), 8.0f, 8.0f, 20, Colours::GalaBlack);
}

void Demo_Scene::OnUpdate() {
    if(IsKeyDown(KEY_UP)) {
        scene->mainCamera.position.y -= 512.0f * GetFrameTime();
    }else if(IsKeyDown(KEY_DOWN)) {
        scene->mainCamera.position.y += 512.0f * GetFrameTime();
    }

    if(IsKeyDown(KEY_LEFT)) {
        scene->mainCamera.position.x -= 512.0f * GetFrameTime();
    }else if(IsKeyDown(KEY_RIGHT)) {
        scene->mainCamera.position.x += 512.0f * GetFrameTime();
    }

    scene->mainCamera.size = Vector2Subtract(scene->mainCamera.size, Vector2Multiply({32.0f, 18.0f}, {GetMouseWheelMove(), GetMouseWheelMove()}));
}

void Demo_Scene::OnUnload() {
    UnloadTexture(tex_bgSky);
    UnloadTexture(tex_bgOverlay);
    UnloadTexture(tex_sprFlower);
}

Demo_Scene::Demo_Scene() : Game(
    GalaEngine::GameInfo {
        "GalaEngine Scene Demo (GalaEngine v" GALAENGINE_VERSION_STRING ")",
        "GalaEngine example project.",
        "Colleen (colleen05)",

        1024, 576,

        "./res/"
    }
) {}