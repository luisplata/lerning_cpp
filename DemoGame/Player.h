#include "ObjectInScreen.h"

class Player : public ObjectInScreen
{
private:
public:
    float attackSpeed{1.0f};
    float currentTotalExp{1.0f};
    float currentExp{0.0f};
    float expToNextLevel{100.0f};
    float expMultiplier{1.1f};


    Player(/* args */);
    ~Player();
    virtual Vector2 getScreenPosition() override;
    virtual Vector2 GetWorldPosition() override;
};