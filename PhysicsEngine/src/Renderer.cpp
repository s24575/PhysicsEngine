#include "Renderer.h"

Renderer::Renderer()
    : m_Circle(50.0f),
    m_VertexArray(sf::Quads, 4)
{

}

void Renderer::OnResize(uint32_t width, uint32_t height)
{
    //m_Circle.setPosition(((float)width / 2) - m_Circle.getRadius(), ((float)height / 2) - m_Circle.getRadius());

    //m_VertexArray[0] = (sf::Vertex(sf::Vector2f(0.0f, 0.0f), sf::Color::Black));
    //m_VertexArray[1] = (sf::Vertex(sf::Vector2f(0.0f, height), sf::Color::Green));
    //m_VertexArray[2] = (sf::Vertex(sf::Vector2f(width, height), sf::Color::Yellow));
    //m_VertexArray[3] = (sf::Vertex(sf::Vector2f(width, 0.0f), sf::Color::Red));
}

void Renderer::Render(sf::RenderWindow& window, const PhysicsWorld& physicsWorld)
{

    for (const auto& entry : physicsWorld.GetObjects())
    {
        Object* object = entry.second;
        object->update();
        object->draw(window, sf::RenderStates());
    }
    //window.draw(m_VertexArray);
    //window.draw(m_Circle);
}