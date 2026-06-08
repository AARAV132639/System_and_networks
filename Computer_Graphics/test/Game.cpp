#include "Game.hpp"

Game:: Game(): m_window(sf::VideoMode(800,600),"Multi-file SFML Setup")
{
    m_shape.setRadius(80.f);
    m_shape.setFillColor(sf::Color::Cyan);
    m_shape.setPosition(320.f,220.f);
}

void Game::run()
{
    while(m_window.isOpen())
    {
        sf::Event event;

        while(m_window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed) m_window.close();
        }

        m_window.clear();
        m_window.draw(m_shape);
        m_window.display();
    }

}