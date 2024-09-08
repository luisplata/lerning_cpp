#ifndef EXPERIENCE_H
#define EXPERIENCE_H
#include "ObjectInScreen.h"
class Experience : public ObjectInScreen
{
private:
    /* data */
public:
    Experience(Texture2D idle, Texture2D run);
    ~Experience();
    void Reset();
    virtual Vector2 getScreenPosition() override;
    virtual void TickFrame(float deltaTime) override;
};
#endif // EXPERIENCE_H