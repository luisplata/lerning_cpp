#ifndef IMAINMENU_H
#define IMAINMENU_H
class IMainMenu
{
    public :
    virtual ~IMainMenu() = default;
    virtual bool isGameStarted() const = 0;
};
#endif