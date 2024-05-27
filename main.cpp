#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include "grid.hpp"
#include "player.hpp"
#include "enemigos.hpp"
#include "bg.hpp"
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


    int random = 645 - (rand() % 150);
    Texture kirbyTexture;
    if(!kirbyTexture.loadFromFile("images/kirby2dnb.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    kirbyTexture.setRepeated(true);

    Sprite kirby;
    kirby.setTexture(kirbyTexture);
    kirby.setTextureRect(IntRect(0,0, 200, 160));
    //kirby.setScale(0.5f, 0.5f); para reducir tamaño
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
    meta.setScale(0.6f, 0.6f); //para reducir el tamaño

    Enemigo enemy1(meta);

    Texture pastoTexture;
    if(!pastoTexture.loadFromFile("images/pasto.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    pastoTexture.setRepeated(true);


    Sprite pasto;
    pasto.setTexture(pastoTexture);
    pasto.setTextureRect(IntRect(0,0, 200, 160));
    //pasto.setScale(0.5f, 0.5f);
    //int opacidad = 255;
    pasto.setPosition(90,800);
    Pasto fondo(pasto);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
            if (event.type == Event::KeyPressed)
            {
                if (event.mouseButton.button == Keyboard::Space)
                {
                    p.click();
                }
            }
        }


        window.clear(Color(51,51,51));
        fondo.drawTo(window);
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


  
