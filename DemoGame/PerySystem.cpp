#include "PerySystem.h"
#include "System_Input.h"
#include "System_Player.h"
#include "System_Render.h"
#include "System_Map.h"
#include "EnumSystemsAvailable.h"
#include <iostream> // Para std::cout
#include "System_Exp.h"
#include "SpawnEnemies.h"

PerySystem::PerySystem()
{
    systemsAvailable[EnumSystemsAvailable::System_Input] = new System_Input();
    systemsAvailable[EnumSystemsAvailable::System_Player] = new SystemPlayer();
    systemsAvailable[EnumSystemsAvailable::System_Render] = new System_Render();
    systemsAvailable[EnumSystemsAvailable::System_Map] = new System_Map();
    systemsAvailable[EnumSystemsAvailable::System_Experiencie] = new System_Exp();

    systems.push_back(systemsAvailable[EnumSystemsAvailable::System_Map]);
    systems.push_back(systemsAvailable[EnumSystemsAvailable::System_Render]);
    systems.push_back(systemsAvailable[EnumSystemsAvailable::System_Player]);
    systems.push_back(systemsAvailable[EnumSystemsAvailable::System_Input]);
    systems.push_back(systemsAvailable[EnumSystemsAvailable::System_Experiencie]);

}

PerySystem::~PerySystem()
{
}

void PerySystem::Tick(float dt)
{
    for (ISystem *sys : systems)
    {
        if (sys == nullptr)
            continue;
        sys->Tick(dt);
    }
}

void PerySystem::AddSystem(EnumSystemsAvailable system)
{
    ISystem *sysLoaded = systemsAvailable[system];
    if (sysLoaded == nullptr)
    {
        std::cerr << "Error: sysLoaded is nullptr" << std::endl;
        return;
    }

    std::cout << "sysLoaded: " << sysLoaded << std::endl;

    for (ISystem *sys : systems)
    {
        std::cout << "Checking system: " << sys << std::endl;

        // compare if the systemload is equal to the system
        if (sys == sysLoaded)
        {
            std::cout << "System found: " << sys << std::endl;
            sys->IsAvailable(true);
            return;
        }
    }

    std::cerr << "Error: System not found" << std::endl;
}
