#ifndef IRENDERABLE_H
#define IRENDERABLE_H
class IRenderable
{
public:
    virtual ~IRenderable() = default;
    virtual void Render(float dt) = 0; // Función pura virtual
};
#endif