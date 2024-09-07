#include "Player.h"

Player::Player()
{
    
}

Player::~Player()
{
}

Vector2 Player::getScreenPosition()
{
    return this->screenPosition;
}

Vector2 Player::GetWorldPosition()
{
    return this->wordPosition;
}
