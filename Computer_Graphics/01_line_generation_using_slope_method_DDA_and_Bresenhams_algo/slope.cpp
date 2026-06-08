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

//DDA logic
void drawLineDDA(int x1, int y1, int x2, int y2, sf::VertexArray&points)
{
    int dx = x2-x1;
    int dy = y2-y1;

    int steps = max(abs(dx),abs(dy));

    float xinc = dx/(float) steps;
    float yinc= dy/(float) steps;

    float x= x1;
    float y= y1;

    for(int i=0;i<=steps;i++)
    {
        cout<<"("<<round(x)<<","<<round(y)<<")\n";

        putPixel(round(x), round(y), points);

        x+=xinc;
        y+=yinc;
    }
}

void drawLineBresenham(int x1, int y1, int x2, int y2, sf::VertexArray&points)
{
    int dx = x2- x1;

    int dy = y2-y1;

    int p= 2*dy-dx;

    int x =x1;
    int y= y1;

    while(x<=x2)
    {
        cout<<"("<<x<<","<<y<<")\n";

        putPixel(x,y, points);

        if(p<0) p= p+2*dy;

        else{
            y++;
            p= p + 2*dy -2*dx;
        }
        x++;
    }
}

int main()
{
    int x1, x2, y1, y2;
    int choice;

    cout<<"Enter x1 y1: ";
    cin>>x1>>y1;

    cout<<endl;

    cout<<"Enter x2 y2: ";
    cin>>x2>>y2;

    cout<<"Enter choice";
    cin>>choice;

    sf::RenderWindow window(
        sf::VideoMode({800,600}),
        "Line generation algorithms"
    );

    sf::VertexArray points(sf::PrimitiveType::Points);

    //choice of algorithms
    switch(choice)
    {
        case 1:
            drawLineSlope(x1,y1, x2, y2, points);
            break;
        
        case 2:
            drawLineDDA(x1,y1,x2,y2,points);
            break;
        
        case 3:
            drawLineBresenham(x1,y1,x2,y2,points);
            break;
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