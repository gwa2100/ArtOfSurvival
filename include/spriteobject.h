#ifndef SPRITEOBJECT_H
#define SPRITEOBJECT_H

#include <GameObject.h>
#include <SFML/Graphics.hpp>
#include <datatype.h>
#include <vector>

using namespace std;

class SpriteObject : protected GameObject
{
    public:
        SpriteObject()
        {
            position.x = 10;
            position.y = 10;
        }
        virtual ~SpriteObject();

        bool OnRender();
        bool OnUpdate();
        bool OnInput(int pEvent);

        sf::Texture* GetTexture() const
        {
            return texture;
        };
        void SetTexture(sf::Texture* pText)
        {
            texture = pText;
            sprite.setTexture(*texture);
        };
        sf::IntRect GetSpriteDimensions()
        {
            return spriteDimensions;
        };
        void SetSpriteDimensions(sf::IntRect pDim)
        {
            spriteDimensions = pDim;
        };
        void SetDraw(bool p = true)
        {
            needDraw = p;
        };
        void SetUpdate(bool p = true)
        {
            needUpdate = p;
        };
        void SetInput(bool p = true)
        {
            needInput = p;
        };
        bool NeedDraw() const
        {
            return needDraw;
        };
        bool NeedUpdate() const
        {
            return needUpdate;
        };
        bool NeedInput() const
        {
            return needInput;
        };
        sf::Sprite* GetSprite()
        {
            return &sprite;
        };
    protected:
        sf::Texture* texture;
        sf::Sprite sprite;
        sf::IntRect spriteDimensions;
        bool needDraw;
        bool needUpdate;
        bool needInput;
    private:
};

class SpriteObjectPtrVector : public vector< SpriteObject* >
{
    public:
    SpriteObjectPtrVector() {}
    ~SpriteObjectPtrVector()
    {
        ResetContent();
    }

    void ResetContent()
    {
        if ( size() == 0 ) return;

        SpriteObject** ppObjects = data();
        for(size_t n = 0; n < size(); n++)
        {
            delete ppObjects[n];
        }

        clear();

        SpriteObjectPtrVector().swap( *this );
    }

};

#endif // SPRITEOBJECT_H
