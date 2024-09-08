#ifndef MAINMENU_H
#define MAINMENU_H

#include "IMainMenu.h"
#include "IState.h"
#include "PerySystem.h"

class MainMenu : public IMainMenu, public IState
{
public:
    MainMenu();
    virtual void Update(float dt) override;
    virtual void Render() override;
private:
protected:
private:
};
#endif