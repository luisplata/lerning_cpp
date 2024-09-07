#ifndef ISTATE_H
#define ISTATE_H
class IState
{
private:
    /* data */
public:
    IState() = default;
    ~IState() = default;
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void Update(float dt) = 0;
};
#endif