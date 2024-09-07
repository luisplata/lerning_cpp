#include "System_Input.h"
#include "raylib.h"
#include "raymath.h"
#include <string>

Vector2 System_Input::velocity = {0, 0};

System_Input::System_Input()
{
}

void System_Input::Update(float dt)
{
    velocity = {0, 0};
    if (IsKeyDown(KEY_RIGHT) || IsKeyDown(KEY_D))
        velocity.x += 1;
    if (IsKeyDown(KEY_LEFT) || IsKeyDown(KEY_A))
        velocity.x -= 1;
    if (IsKeyDown(KEY_UP) || IsKeyDown(KEY_W))
        velocity.y -= 1;
    if (IsKeyDown(KEY_DOWN) || IsKeyDown(KEY_S))
        velocity.y += 1;

    std::string velocityString = "Velocity: " + std::to_string(velocity.x) + ", " + std::to_string(velocity.y);
    DrawText(velocityString.c_str(), 10, 10, 20, RED);
}