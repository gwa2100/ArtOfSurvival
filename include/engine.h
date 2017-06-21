#ifndef ENGINE_H
#define ENGINE_H

#include <datatype.h>
#include <gameobject.h>
#include <spriteobject.h>
#include <SFML/Graphics.hpp>
#include <queue>
#include <textureManager.h>

class engine
{
    public:
        engine();
        virtual ~engine();
        bool Start();
        bool Stop();
    protected:
        bool Init();
        bool Loop();
        bool Render();
        bool Input();
        bool Update();
        bool Shutdown();

        sf::RenderWindow* window;
        sf::Event* event;
        std::queue<unsigned int> eventBuffer;
        SpriteObjectPtrVector spriteManager;
        TextureManagerPtrVector textureManager;
        bool run;


        //Test Resources
        sf::CircleShape* shape;

};

#endif // ENGINE_H
