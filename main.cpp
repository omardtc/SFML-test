#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "grid.hpp"
using namespace sf;

int width = 400;
int height = 400;
int numCells = 10;

int main()
{
    RenderWindow window(VideoMode(800, 800), "Echo Dash");
    window.setFramerateLimit(10);
    Grid grid(numCells, numCells, width, height);
    Texture kirbyTexture;
    //CircleShape shape(100.f);
    //shape.setFillColor(Color(160,178,32));
    if(!kirbyTexture.loadFromFile("images/kirby.png.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    kirbyTexture.setRepeated(true);

    Sprite kirby;
    kirby.setTexture(kirbyTexture);
    kirby.setTextureRect(IntRect(0,0, 800, 181));
    int opacidad = 255;


    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    int x = event.mouseButton.x;
                    int y = event.mouseButton.y;
                    grid.click(x,y);
                }
            }
        }


        window.clear(Color(51,51,51));
        grid.update();
        grid.drawTo(window);
        window.draw(kirby);
        window.display();
    }

    return 0;
}