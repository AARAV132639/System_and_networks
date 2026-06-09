#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

using namespace std;

//helper function
void plotEllipsePoints(int xc, int yc, int x, int y, sf::VertexArray& points)
{
    points.append(sf::Vertex(
        sf::Vector2f(xc + x, yc + y),
        sf::Color::White));

    points.append(sf::Vertex(
        sf::Vector2f(xc - x, yc + y),
        sf::Color::White));

    points.append(sf::Vertex(
        sf::Vector2f(xc + x, yc - y),
        sf::Color::White));

    points.append(sf::Vertex(
        sf::Vector2f(xc - x, yc - y),
        sf::Color::White));
}

//midpoint ellipse algorithm

void drawMidpointEllipse(int xc, int yc, int rx, int ry, sf::VertexArray&points)
{
   double dx, dy, d1, d2;

    int x=0;
    int y = ry;

    double rx2 = (double)rx*rx;
    double ry2= (double) ry*ry;

    d1= ry2-(rx2*ry) +(0.25*rx2);

    dx = 2*ry2*x;
    dy = 2*rx2*y;

    //region 1
    while(dx<=dy)
    {
        plotEllipsePoints(xc, yc, x, y, points);

        if(d1<0)
        {
            x++;

            dx = dx + (2*ry*ry);

            d1 = d1+ dx + (ry*ry);
        }

        else{
            x++;
            y--;

            dx= dx + (2*ry*ry);

            dy = dy - (2*rx*rx);

            d1 = d1 + dx - dy +(ry*ry);
        }
    }

    //region 2

    d2 = ((ry*ry)*((x+ 0.5f)*(x + 0.5f))) + ((rx*rx)*((y-1)*(y-1))) - (rx*rx*ry*ry);

    while(y>=0)
    {
        plotEllipsePoints(xc, yc, x, y, points);

        if(d2>0)
        {
            y--;

            dy = dy-(2*rx*rx);
        }

        else
        {
            y--;
            x++;

            dx = dx+ (2*ry*ry);
            dy= dy- (2*rx*rx);

            d2 =d2 + dx -dy +(rx*rx);
        }
    }
}

int main()
{
    int xc, yc;

    int rx, ry;

    cout<< "enter centre(xc, yc): ";
    cin>>xc>>yc;

    cout<<"Enter rx and ry: ";
    cin>>rx>>ry;

    sf::RenderWindow window(sf::VideoMode(800,600), "Midpoint Ellipse");

    sf::VertexArray points(sf::Points);

    drawMidpointEllipse(xc, yc, rx, ry, points);

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