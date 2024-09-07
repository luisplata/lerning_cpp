#include "ISystem.h"

ISystem::~ISystem()
{
    
}

void ISystem::IsAvailable(bool isAvailable)
{
    this->isAvailable = isAvailable;
}
