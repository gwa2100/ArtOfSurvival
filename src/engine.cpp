#include "engine.h"
#include <iostream>

engine::engine()
{
    //ctor
    run = false;
}

engine::~engine()
{
    //dtor
    delete window;
    delete event;
    //test resources
    delete shape;
}

bool engine::Start()
{
    run = true;
    Init();
    Loop();
    Shutdown();

    return true;
}

bool engine::Stop()
{
    run = false;
    return true;
}

bool engine::Init()
{
    //Initialize the window
    sf::RenderWindow* createWindow = new sf::RenderWindow(sf::VideoMode(800, 640), "Art Of Survival - Dev Build - v0.01A - Velocibyte Softworks LLC");
    window = createWindow;
    //Initialize event system
    sf::Event* createEvent = new sf::Event;
    event = createEvent;
    //Initialize test resources
    sf::CircleShape* createShape = new sf::CircleShape(100.f);
    shape = createShape;
    SpriteObject* newSprite = new SpriteObject();
    spriteManager.push_back(newSprite);

    sf::Texture* createTexture = new sf::Texture();
    createTexture->loadFromFile("buildingTiles_000.png");
    newSprite->SetTexture(createTexture);
    return true;
}

bool engine::Loop()
{
    shape->setFillColor(sf::Color::Green);
    while (run)
    {
        Input();
        Render();
        Update();
    }
    Shutdown();
    return true;
}

bool engine::Render()
{
    window->clear(sf::Color::Black);
    window->draw(*shape);
    window->draw(*spriteManager.front()->GetSprite());
    window->display();


    return true;
}

bool engine::Input()
{
    while (window->pollEvent(*event))
    {
        if (event->type == sf::Event::Closed)
            eventBuffer.push(exitGame);
    }
    return true;
}

bool engine::Update()
{
    while (!eventBuffer.empty())
    {
        switch(eventBuffer.front())
        {
            case moveUp   : break;
            case moveDown : break;
            case moveLeft : break;
            case moveRight: break;
            case exitGame : run = false; break;
        }
        eventBuffer.pop();
    }
    return true;
}

bool engine::Shutdown()
{
    window->close();
    return true;
}
