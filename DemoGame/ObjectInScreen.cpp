#include "ObjectInScreen.h"

ObjectInScreen::ObjectInScreen()
{
}

void ObjectInScreen::undoMovement()
{
    this->wordPosition = this->wordPositionLastFrame;
}
