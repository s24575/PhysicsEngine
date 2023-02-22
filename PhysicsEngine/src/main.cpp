#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "objects/Circle.h"
#include "ImpulseSolver.h"

#include "collision/colliders/CircleCollider.h"

int main()
{
    uint32_t width = 640;
    uint32_t height = 480;
    sf::RenderWindow window(sf::VideoMode(1280, 720), "PhysicsEngine");

    Renderer renderer;
    PhysicsWorld physicsWorld;
    ImpulseSolver impulseSolver;

    physicsWorld.AddSolver(&impulseSolver);

    std::vector<Circle*> circles;

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
                    sf::FloatRect visibleArea(0, 0, (float)width, (float)height);
                    window.setView(sf::View(visibleArea));
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        sf::Vector2f mousePosition((float)event.mouseButton.x, (float)event.mouseButton.y);
                        //mousePosition = sf::Vector2f(width / 2, height / 2);
                        Circle* circle = new Circle(mousePosition, 1.0f, 20.0f);

                        CircleCollider* circleCollider = new CircleCollider();
                        circleCollider->Radius = circle->m_CircleShape.getRadius();
                        circleCollider->Center = circle->Position;
                        circle->m_CircleCollider = circleCollider;

                        circle->m_Transform = new Transform();

                        circles.push_back(circle);
                        physicsWorld.AddObject(circle);
                    }
                    break;
                }
            }
        }

        // UPDATE
        float deltaTime = clock.restart().asSeconds();
        physicsWorld.Step(deltaTime);

        // RENDER
        window.clear();

        renderer.OnResize(width, height);
        renderer.Render(window, physicsWorld);

        window.display();
    }
}