#include <SFML/Graphics.hpp>

#include "Renderer.h"
#include "objects/Circle.h"
#include "objects/Line.h"
#include "dynamics/ImpulseSolver.h"

#include "collision/colliders/CircleCollider.h"

int main()
{
    uint32_t width = 1280;
    uint32_t height = 720;
    sf::ContextSettings contextSettings(0, 0, 8);
    sf::RenderWindow window(sf::VideoMode(width, height), "PhysicsEngine", sf::Style::Default, contextSettings);

    Renderer renderer;
    PhysicsWorld physicsWorld;
    ImpulseSolver impulseSolver;

    physicsWorld.AddSolver(&impulseSolver);

    Line line1(glm::vec2(0.0f, (float)height), glm::vec2(1.0f, 0.0f), (float)width, 1.0f);
    LineCollider* lineCollider1 = new LineCollider(line1.m_Origin, line1.m_Direction, line1.m_Distance);
    line1.m_LineCollider = lineCollider1;
    line1.m_Transform = new Transform();
    physicsWorld.AddObject(&line1);

    Line line2(glm::vec2((float)width, (float)height), glm::vec2(0.0f, -1.0f), (float)height, 1.0f);
    LineCollider* lineCollider2 = new LineCollider(line2.m_Origin, line2.m_Direction, line2.m_Distance);
    line2.m_LineCollider = lineCollider2;
    line2.m_Transform = new Transform();
    physicsWorld.AddObject(&line2);

    Line line3(glm::vec2((float)width, 1.0f), glm::vec2(-1.0f, 0.0f), (float)width, 1.0f);
    LineCollider* lineCollider3 = new LineCollider(line3.m_Origin, line3.m_Direction, line3.m_Distance);
    line3.m_LineCollider = lineCollider3;
    line3.m_Transform = new Transform();
    physicsWorld.AddObject(&line3);

    Line line4(glm::vec2(0.0f, 0.0f), glm::vec2(0.0f, 1.0f), (float)height, 1.0f);
    LineCollider* lineCollider4 = new LineCollider(line4.m_Origin, line4.m_Direction, line4.m_Distance);
    line4.m_LineCollider = lineCollider4;
    line4.m_Transform = new Transform();
    physicsWorld.AddObject(&line4);

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
                    clock.restart();
                    break;
                }
                case sf::Event::MouseButtonPressed:
                {
                    if (event.mouseButton.button == sf::Mouse::Left)
                    {
                        glm::vec2 mousePosition((float)event.mouseButton.x, (float)event.mouseButton.y);
                        float weight = 1.0f;
                        float radius = 20.0f;
                        Circle* circle = new Circle(mousePosition, radius, weight);
                        circle->m_HasGravity = true;

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