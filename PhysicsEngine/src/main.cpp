#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "objects/Circle.h"
#include "objects/Line.h"
#include "ImpulseSolver.h"

#include "collision/colliders/CircleCollider.h"

int main()
{
    uint32_t width = 1280;
    uint32_t height = 720;
    sf::RenderWindow window(sf::VideoMode(width, height), "PhysicsEngine");

    Renderer renderer;
    PhysicsWorld physicsWorld;
    ImpulseSolver impulseSolver;

    physicsWorld.AddSolver(&impulseSolver);

    Line line(sf::Vector2f(0.0f, (float)height / 2), sf::Vector2f(1.0f, 0.0f), (float)width, 1.0f);

    LineCollider* lineCollider = new LineCollider(line.m_Origin, line.m_Direction, line.m_Distance);
    line.m_LineCollider = lineCollider;
    line.m_Transform = new Transform();

    physicsWorld.AddObject(&line);

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
                        float weight = 1.0f;
                        float radius = 20.0f;
                        Circle* circle = new Circle(mousePosition, weight, radius);
                        circle->hasGravity = true;

                        CircleCollider* circleCollider = new CircleCollider(mousePosition, radius);
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