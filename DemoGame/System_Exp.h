#ifndef SYSTEM_EXP_H
#define SYSTEM_EXP_H
#include "ISystem.h"
class System_Exp : public ISystem
{
private:
    /* data */
public:
    System_Exp(/* args */);
    ~System_Exp();
    virtual void Update(float dt) override;
};

#endif // SYSTEM_EXP_H