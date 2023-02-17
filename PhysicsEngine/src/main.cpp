#include <SFML/Graphics.hpp>

#include "Renderer.h"

#include "Circle.h"

int main()
{
    uint32_t width = 640;
    uint32_t height = 480;
    sf::RenderWindow window(sf::VideoMode(640, 480), "Hello World");

    Renderer renderer;
    PhysicsWorld physicsWorld;
    Object circle = Circle(10.0f);
    physicsWorld.AddObject(&circle);

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

        window.clear();

        renderer.OnResize(width, height);
        renderer.Render(window, physicsWorld);

        window.display();
    }

    return 0;
}