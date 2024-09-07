#ifndef ISYSTEM_H
#define ISYSTEM_H
class ISystem
{
public:
    void Tick(float dt)
    {
        if (isAvailable)
        {
            Update(dt);
        }
    }
    virtual void Update(float dt) = 0;
    virtual ~ISystem();
    bool isAvailable{false};
    virtual void IsAvailable(bool isAvailable);
    bool IsAvailable() const
    {
        return isAvailable;
    }
};
#endif