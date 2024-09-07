#ifndef IUPDATABLE_H
#define IUPDATABLE_H
class IUpdatable
{
public:
    virtual ~IUpdatable() = default;
    virtual void Update(float dt) = 0; // Función pura virtual
};
#endif