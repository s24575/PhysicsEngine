#include <SFML/Graphics.hpp>

#include "Renderer.h"

#include "Circle.h"

#include <iostream>

int main()
{
    uint32_t width = 640;
    uint32_t height = 480;
    sf::RenderWindow window(sf::VideoMode(640, 480), "Hello World");

    Renderer renderer;

    float radius = 10.0f;
    sf::Vector2f position(0, (float)height / 2 - radius);
    Circle circle(position, 1.0f, radius);
    circle.Velocity = sf::Vector2f(50.0f, -25.0f);

    PhysicsWorld physicsWorld;
    physicsWorld.AddObject(&circle);

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;
            case sf::Event::Resized:
                width = event.size.width;
                height = event.size.height;
                sf::FloatRect visibleArea(0, 0, width, height);
                window.setView(sf::View(visibleArea));
                break;
            }
        }

        // UPDATE
        float deltaTime = clock.restart().asSeconds();
        physicsWorld.Step(deltaTime);

        window.clear();

        // RENDER
        renderer.OnResize(width, height);
        renderer.Render(window, physicsWorld);
        //circle.draw(window, sf::RenderStates());

        window.display();
    }

    return 0;
}