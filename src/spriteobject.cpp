#include "spriteobject.h"
#include "gameobject.h"


SpriteObject::~SpriteObject()
{
    //dtor
}

bool SpriteObject::OnRender()
{
    return true;
}

bool SpriteObject::OnUpdate()
{
    GameObject::MovePosition(GameObject::speed);
    return true;
}

bool SpriteObject::OnInput(int pEvent)
{
    switch(pEvent)
    {
        case moveUp :   this->SetSpeed(Int2D(0,1)); break;
        case moveDown : this->SpriteObject::SetSpeed(Int2D(0,-1)); break;
        case moveLeft : this->SpriteObject::SetSpeed(Int2D(1,0)); break;
        case moveRight: this->SpriteObject::SetSpeed(Int2D(-1,0)); break;
        case die: needDraw = false; this->needInput = false; this->needUpdate = false; break;
        case show: this->needDraw = true; break;
        case hide: this->needDraw = false; break;
    }
    return true;
}
