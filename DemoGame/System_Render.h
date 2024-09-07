#ifndef SYSTEM_RENDER_H
#define SYSTEM_RENDER_H

#include "ISystem.h"
#include "raylib.h"

class System_Render : public ISystem
{
private:
    /* data */
public:
    System_Render(/* args */);
    ~System_Render();
    virtual void Update(float dt) override;
    Texture2D mapTexture{LoadTexture("Assets/Map/map.png")};
    Texture2D playerTexture{LoadTexture("Assets/Characters/player.png")};
    Texture2D enemyTexture[3]{
        LoadTexture("Assets/Characters/Enemy_bat.png"),
        LoadTexture("Assets/Characters/Enemy_gosh.png"),
        LoadTexture("Assets/Characters/Enemy_mage.png")};

    Vector2 GetScreenCenter()
    {
        return Vector2{static_cast<float>(GetScreenWidth() / 2), static_cast<float>(GetScreenHeight() / 2)};
    }
};

#endif // SYSTEM_RENDER_H