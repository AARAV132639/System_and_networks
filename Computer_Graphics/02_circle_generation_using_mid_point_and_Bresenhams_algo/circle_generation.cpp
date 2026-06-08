#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

//common pixel plot function

void plotCirclePoints(int xc, int yc, int x, int y, sf::VertexArray& points)
{
    points.append(sf::Vertex(sf::Vector2f(xc + x, yc + y), sf::Color::White));
    points.append(sf::Vertex(sf::Vector2f(xc - x, yc + y), sf::Color::White));
    points.append(sf::Vertex(sf::Vector2f(xc + x, yc - y), sf::Color::White));
    points.append(sf::Vertex(sf::Vector2f(xc - x, yc - y), sf::Color::White));

    points.append(sf::Vertex(sf::Vector2f(xc + y, yc + x), sf::Color::White));
    points.append(sf::Vertex(sf::Vector2f(xc - y, yc + x), sf::Color::White));
    points.append(sf::Vertex(sf::Vector2f(xc + y, yc - x), sf::Color::White));
    points.append(sf::Vertex(sf::Vector2f(xc - y, yc - x), sf::Color::White));
}

//mid point circle implementation

void drawMidpointCircle(int xc, int yc, int r, sf::VertexArray&points)
{
    int x=0;
    int y=r;

    int p= 1-r;

    while(x<=y)
    {
        plotCirclePoints(xc, yc, x, y, points);
        x++;

        if(p<0) p = p + 2*x+1;

        else {
            y--;
            p = p +2*(x-y)+1;
        }
    }
}

void drawBresenham(int xc, int yc, int r, sf::VertexArray&points)
{
    int x=0;
    int y=r;

    int d= 3-2*r;

    while(x<=y)
    {
        plotCirclePoints(xc, yc, x, y, points);

        if(d<0) d = d +4*x+6;

        else
        {
            d = d + 4*(x-y) +10;
            y--;
        }
        x++;
    }
}

//main function

int main()
{
    int xc, yc, r;

    cout<<"Enter center (xc yc):";
    cin>>xc>>yc;
    cout<<endl;

    cout<<"Enter Radius";
    cin>>r;
    cout<<endl;

    int choice;

    cout<<"Enter choice: ";
    cin>>choice;

    sf::RenderWindow window(sf::VideoMode(800,600),"Midpoint Circle");

    sf::VertexArray points(sf::Points);

    switch(choice)
    {
        case 1:
            drawMidpointCircle(xc,yc,r, points);
            break;

        case 2:
            drawBresenham(xc, yc, r, points);
            break;
        
        default:
                return 0;
    }

    

   

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