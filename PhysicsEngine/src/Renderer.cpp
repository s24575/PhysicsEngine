#include "Renderer.h"

Renderer::Renderer()
{

}

void Renderer::OnResize(uint32_t width, uint32_t height)
{

}

void Renderer::Render(sf::RenderWindow& window, const PhysicsWorld& physicsWorld)
{
    for (Object* object : physicsWorld.GetObjects())
    {
        object->update();
        object->draw(window, sf::RenderStates());
    }
}