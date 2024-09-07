#ifndef SYSTEM_MAP_H
#define SYSTEM_MAP_H
#include "ISystem.h"
#include "Map.h"
class System_Map : public ISystem
{
private:
public:
    System_Map(/* args */);
    ~System_Map();
    virtual void Update(float dt) override;
    static Map map;
};

#endif