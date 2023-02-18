#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "Circle.h"

#include <iostream>

int main()
{
    uint32_t width = 640;
    uint32_t height = 480;
    sf::RenderWindow window(sf::VideoMode(640, 480), "PhysicsEngine");

    Renderer renderer;
    PhysicsWorld physicsWorld;

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
                case sf::Event::Closed:
                {
                    window.close();
                    break;
                }
                case sf::Event::Resized:
                {
                    width = event.size.width;
                    height = event.size.height;
                    sf::FloatRect visibleArea(0, 0, width, height);
                    window.setView(sf::View(visibleArea));
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2f mousePosition(event.mouseButton.x, event.mouseButton.y);
                        Circle* newCircle = new Circle(mousePosition, 1.0f, 10.0f);
                        newCircle->Velocity = mousePosition;
                        physicsWorld.AddObject(newCircle);
                    }
                    break;
                }
            }
        }

        // UPDATE
        float deltaTime = clock.restart().asSeconds();
        physicsWorld.Step(deltaTime);

        window.clear();

        // RENDER
        renderer.OnResize(width, height);
        renderer.Render(window, physicsWorld);

        window.display();
    }
}