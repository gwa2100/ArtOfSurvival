#ifndef TEXTUREMANAGER_H_INCLUDED
#define TEXTUREMANAGER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <vector>

using namespace std;

class TextureManagerPtrVector : public vector< sf::Texture* >
{
    public:
    TextureManagerPtrVector() {}
    ~TextureManagerPtrVector()
    {
        ResetContent();
    }

    void ResetContent()
    {
        if ( size() == 0 ) return;

        sf::Texture** ppObjects = data();
        for(size_t n = 0; n < size(); n++)
        {
            delete ppObjects[n];
        }

        clear();

        TextureManagerPtrVector().swap( *this );
    }

};
#endif // TEXTUREMANAGER_H_INCLUDED
