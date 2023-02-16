#include <SFML/Graphics.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(640, 480), "Hello World");
    sf::VertexArray vao;
    vao.setPrimitiveType(sf::Quads);
    vao.append(sf::Vertex(sf::Vector2f(0.0f, 0.0f), sf::Color::Black));
    vao.append(sf::Vertex(sf::Vector2f(0.0f, 480.0f), sf::Color::Green));
    vao.append(sf::Vertex(sf::Vector2f(640.0f, 480.0f), sf::Color::Yellow));
    vao.append(sf::Vertex(sf::Vector2f(640.0f, 0.0f), sf::Color::Red));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(vao);
        window.display();
    }

    return 0;
}