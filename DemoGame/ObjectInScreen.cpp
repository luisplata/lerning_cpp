#include "ObjectInScreen.h"

ObjectInScreen::ObjectInScreen(Texture2D idleAnim, Texture2D runAnim)
{
    idle = idleAnim;
    run = runAnim;
    texture = idleAnim;
    width = static_cast<float>(idle.width);
    height = static_cast<float>(idle.height);
}

Rectangle ObjectInScreen::getCollisionRec()
{
    Rectangle rec{getScreenPosition().x, getScreenPosition().y, scale * width * Globals::globalScale, scale * height * Globals::globalScale};
    return rec;
}

void ObjectInScreen::undoMovement()
{
    wordPosition = wordPositionLastFrame;
}

void ObjectInScreen::finishGame()
{
    UnloadTexture(idle);
    UnloadTexture(run);
}

void ObjectInScreen::TickFrame(float deltaTime)
{
    wordPositionLastFrame = wordPosition;
    // Animation
    framesCounter += deltaTime;
    if (framesCounter >= framesSpeed)
    {
        framesCounter = 0.0f;
        currentFrame++;
        if (currentFrame >= maxFrames)
            currentFrame = 0;
    }

    texture = Vector2Length(velocity) == 0.0 ? idle : run;

    if (Vector2Length(velocity) != 0.0)
    {
        wordPosition = Vector2Add(wordPosition, Vector2Scale(Vector2Normalize(velocity), speed * deltaTime));
        velocity.x > 0 ? playerDirection = 1.0f : playerDirection = -1.0f;
    }

    velocity = {};
}

void ObjectInScreen::Render()
{
    Rectangle source{currentFrame * width, 0, playerDirection * width, height};
    Rectangle dest{getScreenPosition().x, getScreenPosition().y, scale * width * Globals::globalScale, scale * height * Globals::globalScale};
    Vector2 origin{};
    DrawTexturePro(texture, source, dest, origin, 0, WHITE);
}
