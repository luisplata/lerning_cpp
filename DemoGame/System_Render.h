#ifndef SYSTEM_RENDER_H
#define SYSTEM_RENDER_H

#include "ISystem.h"

class System_Render : public ISystem
{
private:
    /* data */
public:
    System_Render(/* args */);
    ~System_Render();
    virtual void Update(float dt) override;
};

#endif // SYSTEM_RENDER_H