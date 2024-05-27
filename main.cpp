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


    int random = 550 - (rand() % 150);
    int random1 = 650 - (rand() % 150);
    Texture kirbyTexture;
    if(!kirbyTexture.loadFromFile("images/kirby2dnb.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    kirbyTexture.setRepeated(true);

    Sprite kirby;
    kirby.setTexture(kirbyTexture);
    kirby.setTextureRect(IntRect(0,0, 200, 160));
    kirby.setScale(0.5f, 0.5f);
    int opacidad = 255;
    kirby.setPosition(0,620);
    Player p(name, kirby);

    Texture metaTexture;
    if(!metaTexture.loadFromFile("images/meta.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    metaTexture.setRepeated(true);

    Sprite meta;
    meta.setTexture(metaTexture);
    meta.setPosition(800, random);
    meta.setScale(0.4f, 0.4f); //para reducir el tamaño

    Enemigo enemy1(meta);

    Texture gordoTexture;
    if(!gordoTexture.loadFromFile("images/gordo.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    gordoTexture.setRepeated(true);

    Sprite gordo;
    gordo.setTexture(gordoTexture);
    gordo.setPosition(800, 650);
    gordo.setScale(0.5f, 0.5f); //para reducir el tamaño
    gordo.setOrigin(80,80);
    EnemigoT enemy2(gordo);


    Texture flameTexture;
    if(!flameTexture.loadFromFile("images/flamer.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    flameTexture.setRepeated(true);

    Sprite flame;
    flame.setTexture(flameTexture);
    flame.setPosition(800, random1);
    flame.setScale(0.1f, 0.1f); //para reducir el tamaño
    EnemigoA enemy3(flame);

    Texture pastoTexture;
    if(!pastoTexture.loadFromFile("images/montanas.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    pastoTexture.setRepeated(true);


    Sprite pasto;
    pasto.setTexture(pastoTexture);
    //pasto.setTextureRect(IntRect(0,0, 200, 160));
    pasto.setScale(2.5f, 2.0f);
    //int opacidad = 255;
    //pasto.setPosition(-20, 700);
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
                if (event.mouseButton.button == Keyboard::Space || event.mouseButton.button == Keyboard::Up )
                {
                    p.click();
                }
                if (Keyboard::isKeyPressed(Keyboard::Right))
                {
                    p.moveR();
                }
                if(Keyboard::isKeyPressed(Keyboard::Left))
                {
                    p.moveL();
                }
            }
        }


        window.clear(Color(51,51,51));
        //grid.update();
        p.update();
        enemy1.update();
        enemy2.update();
        enemy3.update();
        grid.drawTo(window);
        fondo.drawTo(window);
        p.drawTo(window);
        enemy1.drawTo(window);
        
        enemy2.drawTo(window);
        enemy3.drawTo(window);

        window.display();
    }

    return 0;
}


  
