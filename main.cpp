#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "grid.hpp"
#include "player.hpp"
#include "enemigos.hpp"
using namespace sf;

int width = 800;
int height = 800;
int numCells = 20;
string name;

int main()
{
    RenderWindow window(VideoMode(800, 800), "Echo Dash");
    window.setFramerateLimit(10);
    Grid grid(numCells, numCells, width, height);

    //cout << "Introduzca su nombre" << endl;
    //cin >> name;

    int random = -360+rand()%440;

    Texture kirbyTexture;
    if(!kirbyTexture.loadFromFile("images/kirby2dnb.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    kirbyTexture.setRepeated(true);

    Sprite kirby;
    kirby.setTexture(kirbyTexture);
    kirby.setTextureRect(IntRect(0,0, 200, 160));
    int opacidad = 255;
    kirby.setPosition(0,645);
    Player p(name, kirby);

    Texture metaTexture;
    if(!metaTexture.loadFromFile("images/meta.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    metaTexture.setRepeated(true);

    Sprite meta;
    meta.setTexture(metaTexture);
    meta.setPosition(400, random);
    Enemigo enemy1(meta);

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
                    p.click();
                }
            }
        }


        window.clear(Color(51,51,51));
        //grid.update();
        p.update();
        enemy1.update();
        grid.drawTo(window);
        p.drawTo(window);
        enemy1.drawTo(window);
        window.display();
    }

    return 0;
}