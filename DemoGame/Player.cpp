#include "Player.h"
#include "raylib.h"
#include "raymath.h"
#include "System_Input.h"
#include "Globals.h"

Player::Player(Texture2D idle, Texture2D run) : ObjectInScreen(idle, run)
{
    this->width = static_cast<float>(idle.width) / maxFrames;
    this->height = static_cast<float>(idle.height);
}

Rectangle Player::getCollisionRec()
{
    return ObjectInScreen::getCollisionRec();
}

Vector2 Player::getScreenPosition()
{
    return Vector2{
        static_cast<float>(Globals::screenWidth) / 2.0f - (scale * ((width) / 2.f)),
        static_cast<float>(Globals::screenHeight) / 2.0f - (scale * (height / 2.f))};
}

void Player::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0)
    {
        setIsDead(true);
    }
}

void Player::Render()
{
    ObjectInScreen::Render();
    for (auto powerUp : powerUps)
    {
        powerUp->Render();
    }

    // render the world position of the player
    DrawText(TextFormat("World Position: %f, %f", wordPosition.x, wordPosition.y), 10, 30, 20, RED);
}

void Player::TickFrame(float deltaTime)
{

    if (getIsDead())
        return;

    velocity = System_Input::velocity;

    ObjectInScreen::TickFrame(deltaTime);

    for (PowerUp *powerUp : powerUps)
    {
        powerUp->TickFrame(deltaTime);
    }
}
