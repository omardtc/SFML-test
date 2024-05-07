#include <SFML/Graphics.hpp>
#include "grid.hpp"
using namespace sf;

int width = 400;
int height = 400;
int numCells = 10;

int main()
{
    RenderWindow window(VideoMode(400, 400), "Hola Ohio");
    window.setFramerateLimit(10);
    Grid grid(numCells, numCells, width, height);
    //CircleShape shape(100.f);
    //shape.setFillColor(Color(160,178,32));

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
        //window.draw(shape);
        window.display();
    }

    return 0;
}