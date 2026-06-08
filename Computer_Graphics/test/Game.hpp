#pragma once
#include <SFML/Graphics.hpp>

class Game{
    public:
    Game();
    void run();
    private:
    sf::RenderWindow m_window;
    sf::CircleShape m_shape;
};