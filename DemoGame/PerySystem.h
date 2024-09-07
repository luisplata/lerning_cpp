#ifndef PerySystem_h
#define PerySystem_h

#include "ISystem.h"
#include <vector>
#include <unordered_map>
#include "EnumSystemsAvailable.h"
#include <memory> // Para std::unique_ptr

class PerySystem
{
public:
    PerySystem();
    ~PerySystem();
    void Tick(float dt);
    void AddSystem(EnumSystemsAvailable system);
    void ClearSystems()
    {
        for (ISystem *sys : systems)
        {
            sys->IsAvailable(false);
        }
    }

private:
    std::unordered_map<EnumSystemsAvailable, ISystem *> systemsAvailable;
    std::vector<ISystem *> systems;

protected:
};
#endif