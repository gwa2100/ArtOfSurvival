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
    frame = 0;
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
    newSprite->SetDraw();
    newSprite->SetInput();
    newSprite->SetUpdate();
    return true;
}

bool engine::Loop()
{
    shape->setFillColor(sf::Color::Green);
    while (run)
    {
        cout << frame++ << endl;
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
    //window->draw(*spriteManager.front()->GetSprite());
    //render sprites from spritemanager
    for(auto & value : spriteManager)
    {
        if (value->NeedDraw())
            window->draw(*value->GetSprite());
    }


    window->display();


    return true;
}

bool engine::Input()
{
    while (window->pollEvent(*event))
    {
        unsigned int currentEvent;
        if (event->type == sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
            currentEvent = moveLeft;
        if (event->type == sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
            currentEvent = moveRight;
        if (event->type == sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            currentEvent = moveUp;
        if (event->type == sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
            currentEvent = moveDown;
        if (event->type == sf::Event::Closed)
        {
            window->close();
            exit(0);
        }
        cout << currentEvent << endl;
        for(auto & value : spriteManager)
        {
            if (value->NeedInput())
            {
                value->OnInput(currentEvent);
            }

        }
    }
    return true;
}

bool engine::Update()
{

    for(auto & value : spriteManager)
    {
        if (value->NeedUpdate())
            value->OnUpdate();
    }
    return true;
}

bool engine::Shutdown()
{
    window->close();
    return true;
}
