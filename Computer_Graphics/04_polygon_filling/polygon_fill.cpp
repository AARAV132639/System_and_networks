#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void drawLine(int x1, int y1, int x2, int y2, sf::Image& image, sf::Color color)
{
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    int sx = (x1 < x2) ? 1 : -1;
    int sy = (y1 < y2) ? 1 : -1;

    int err = dx - dy;

    while (true)
    {
        image.setPixel(x1, y1, color);

        if (x1 == x2 && y1 == y2)
            break;

        int e2 = 2 * err;

        if (e2 > -dy)
        {
            err -= dy;
            x1 += sx;
        }

        if (e2 < dx)
        {
            err += dx;
            y1 += sy;
        }
    }
}

void drawPolygon(sf::Image& image)
{
    sf::Color boundaryColor = sf::Color::White;

    drawLine(200, 150, 400, 100, image, boundaryColor);
    drawLine(400, 100, 550, 250, image, boundaryColor);
    drawLine(550, 250, 450, 450, image, boundaryColor);
    drawLine(450, 450, 250, 450, image, boundaryColor);
    drawLine(250, 450, 200, 150, image, boundaryColor);
}

void floodFill(int x, int y, sf::Color targetColor, sf::Color fillColor, sf::Image &image)
{
    if(x<0||y<0||x>=image.getSize().x||y>=image.getSize().y) return;

    if(image.getPixel(x,y)!= targetColor) return;

    image.setPixel(x,y,fillColor);

    floodFill(x +1, y , targetColor, fillColor, image);
    floodFill(x-1 , y , targetColor, fillColor, image);
    floodFill(x , y+1 , targetColor, fillColor, image);
    floodFill(x , y-1, targetColor, fillColor, image);
}

void boundaryFill(int x, int y,  sf::Color fillColor, sf::Color boundaryColor, sf::Image &image)
{
    if(x<0||y<0||x>=image.getSize().x||y>=image.getSize().y) return;

    sf::Color current = image.getPixel(x,y);

    if(current == boundaryColor|| current == fillColor) return;

    image.setPixel(x,y,fillColor);

    boundaryFill(x+1,y , fillColor, boundaryColor, image);
    boundaryFill(x-1 ,y , fillColor, boundaryColor, image);
    boundaryFill(x ,y+1, fillColor, boundaryColor, image);
    boundaryFill(x ,y-1 , fillColor, boundaryColor, image);
}

void scanLineFill(const vector<sf::Vector2i>&polygon, sf::Image &image, sf::Color fillColor)
{
    int n = polygon.size();

    int ymin= polygon[0].y;

    int ymax = polygon[0].y;

    for(int i=1; i<n;i++)
    {
        ymin = min(ymin, polygon[i].y);
        ymax = max(ymax, polygon[i].y);
    }

    for(int y= ymin;y<=ymax;y++)
    {
        vector<int>intersections;

        for(int i=0;i<n;i++)
        {
            int j =(i+1)%n;

            int x1 = polygon[i].x;
            int y1 = polygon[i].y;

            int x2= polygon[j].x;
            int y2= polygon[j].y;

            if(y1==y2) continue;

            if(y>=min(y1,y2)&&y<max(y1,y2))
            {
                int x = x1+ (double)(y-y1)*(x2-x1)/(y2-y1);

                intersections.push_back(x);
            }
        }

        sort(intersections.begin(), intersections.end());

        for(size_t i=0; i+1<intersections.size();i+=2)
        {
            for(int x = intersections[i];x<=intersections[i+1];x++)
            {
                image.setPixel(x,y,fillColor);
            }
        }
    }
}

int main()
{
    int choice;

    cout << "1. Boundary Fill\n";
    cout << "2. Flood Fill\n";
    cout<< "3. ScanLineFill\n";
    cout << "Enter Choice: ";
    cin >> choice;

    sf::RenderWindow window(
        sf::VideoMode(800, 600),
        "Polygon Filling"
    );

    sf::Image image;
    image.create(800, 600, sf::Color::Black);

    drawPolygon(image);

    //creating polygon data
    vector<sf::Vector2i>polygon = {
        {200,150},
        {400,100},
        {550,250},
        {450,450},
        {250,450}
    };

    if(choice == 1)
    {
        boundaryFill(
            350, 250,                 // seed point
            sf::Color::Red,           // fill color
            sf::Color::White,         // boundary color
            image
        );
    }
    else if(choice == 2)
    {
        floodFill(
            350, 250,                 // seed point
            sf::Color::Black,         // target color
            sf::Color::Green,         // fill color
            image
        );
    }

    else if(choice==3)
    {
        scanLineFill(
            polygon,
            image,
            sf::Color::Blue
        );
    }
    else
    {
        cout << "Invalid Choice\n";
        return 0;
    }

    sf::Texture texture;
    texture.loadFromImage(image);

    sf::Sprite sprite(texture);

    while(window.isOpen())
    {
        sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
            {
                window.close();
            }
        }

        window.clear();

        window.draw(sprite);

        window.display();
    }

    return 0;
}