#include "Character.h"
#include "raymath.h"

Character::Character(int winWidth, int winHeight, Texture2D idleAnim, Texture2D runAnim) : windowWidth(winWidth), windowHeight(winHeight), BaseCharacter(idleAnim, runAnim)
{
    width = static_cast<float>(idleAnim.width) / maxFrames;
    height = static_cast<float>(idleAnim.height);
    texture = idleAnim;
}

Vector2 Character::getScreenPosition()
{
    return Vector2{
        static_cast<float>(windowWidth) / 2.0f - (scale * ((width) / 2.f)),
        static_cast<float>(windowHeight) / 2.0f - (scale * (height / 2.f))};
}

void Character::takeDamage(float damage)
{
    health -= damage;
    if (health <= 0)
    {
        setIsDead(true);
    }
}

void Character::TickFrame(float deltaTime)
{

    if(getIsDead()) return;

    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        velocity.x += 1;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        velocity.x -= 1;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        velocity.y -= 1;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        velocity.y += 1;

    BaseCharacter::TickFrame(deltaTime);

    // Draw weapon with drawTexturePro
    float weaponWidth = static_cast<float>(weapon.width);
    float weaponHeight = static_cast<float>(weapon.height);
    Vector2 origin{};
    Vector2 offset{};
    float weaponRotation{};
    if (playerDirection > 0)
    {
        origin = {0.f, weaponHeight * scale};
        offset = {35.f, 55.f};
        weaponCollisionRec = {getScreenPosition().x + offset.x, getScreenPosition().y + offset.y - scale * weaponHeight, scale * weaponWidth, scale * weaponHeight};
        weaponRotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? 35.f : 0.f;
    }
    else
    {
        origin = {weaponWidth * scale, weaponHeight * scale};
        offset = {25.f, 55.f};
        weaponCollisionRec = {getScreenPosition().x + offset.x - scale * weaponWidth, getScreenPosition().y + offset.y - scale * weaponHeight, scale * weaponWidth, scale * weaponHeight};
        weaponRotation = IsMouseButtonDown(MOUSE_LEFT_BUTTON) ? -35.f : 0.f;
    }
    Rectangle source{0.f, 0.f, weaponWidth * playerDirection, weaponHeight};
    Rectangle dest{getScreenPosition().x + offset.x, getScreenPosition().y + offset.y, scale * weaponWidth, scale * weaponHeight};
    DrawTexturePro(weapon, source, dest, origin, weaponRotation, WHITE);

    DrawRectangleLines(weaponCollisionRec.x, weaponCollisionRec.y, weaponCollisionRec.width, weaponCollisionRec.height, RED);
}
