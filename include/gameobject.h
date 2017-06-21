#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <datatype.h>

class GameObject
{
    public:
        GameObject();
        GameObject(Int2D pPosition, Int2D pSpeed);
        virtual ~GameObject();

        virtual bool OnRender();
        virtual bool OnUpdate();
        virtual bool OnInput(unsigned int pEvent);

        Int2D GetPosition();
        bool SetPosition(Int2D pPosition);

        Int2D GetSpeed();
        bool SetSpeed(Int2D pSpeed);
    protected:
        Int2D position;
        Int2D speed;
};

#endif // GAMEOBJECT_H
