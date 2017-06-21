#include "gameobject.h"
#include <datatype.h>

GameObject::GameObject()
{
    //ctor
}

GameObject::GameObject(Int2D pPosition, Int2D pSpeed)
{
    //ctor
    position = pPosition;
    speed = pSpeed;
}

GameObject::~GameObject()
{
    //dtor
}

bool GameObject::OnRender()
{
    return true;
}

bool GameObject::OnUpdate()
{
    return true;
}

bool GameObject::OnInput(unsigned int pEvent)
{
    return true;
}

Int2D GameObject::GetPosition()
{
    return position;
}

bool GameObject::SetPosition(Int2D pPosition)
{
    position = pPosition;
}

Int2D GameObject::GetSpeed()
{
    return speed;
}

bool GameObject::SetSpeed(Int2D pSpeed)
{
    speed = pSpeed;
}
