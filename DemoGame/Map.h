#ifndef MAP_H
#define MAP_H

#include "ObjectInScreen.h"

class Map : public ObjectInScreen
{
private:
    /* data */
public:
    Map(/* args */);
    ~Map();
    virtual Vector2 getScreenPosition() override;
};

#endif