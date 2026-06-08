#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

void putPixel(int x, int y, sf::VertexArray&points)
{
    points.append(sf::Vertex(
        sf::Vector2f((float)x, (float)y),
        sf::Color::White 
    ));
}

void drawLineSlope(int x1, int y1, int x2, int y2, sf::VertexArray&points)
{
    if(x1==x2)
    {
        cout<<"Vertical line not supported in Slope method\n";
        return;
    }

    float m= (float)(y2-y1)/(x2-x1);

    if(x1>x2)
    {
        swap(x1,x2);
        swap(y1,y2);
    }

    for(int x=x1; x<=x2;x++)
    {
        float y= y1 + m*(x-x1);

        cout<<"("<<x<<","<<round(y)<<")"<<endl;

        putPixel(x, round(y), points);
    }
}

int main()
{
    int x1, x2, y1, y2;

    cout<<"Enter x1 y1: ";
    cin>>x1>>y1;

    cout<<endl;

    cout<<"Enter x2 y2: ";
    cin>>x2>>y2;

    sf::RenderWindow window(
        sf::VideoMode({800,600}),
        "Slope method drawing"
    );

    sf::VertexArray points(sf::PrimitiveType::Points);

    drawLineSlope(x1,y1, x2, y2, points);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed) window.close();
        }

        window.clear(sf::Color::Black);
        window.draw(points);
        window.display();
    }
    return 0;
}