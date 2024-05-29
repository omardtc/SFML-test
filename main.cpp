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

float getRandom(float min, float max)
{
    return min + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / (max-min)));
}

int main()
{
    RenderWindow window(VideoMode(800, 800), "Echo Dash");
    window.setFramerateLimit(10);
    Grid grid(numCells, numCells, width, height);
    srand(static_cast<unsigned int>(time(nullptr)));

    // cout << "Introduzca su nombre" << endl;
    // cin >> name;

    int random = 550 - (rand() % 150);
    int random1 = 650 - (rand() % 150);
    Texture kirbyTexture;
    if (!kirbyTexture.loadFromFile("images/kirby2dnb.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    kirbyTexture.setRepeated(true);

    Sprite kirby;
    kirby.setTexture(kirbyTexture);
    kirby.setTextureRect(IntRect(0, 0, 200, 160));
    kirby.setScale(0.5f, 0.5f);
    kirby.setOrigin(118, 98);
    int opacidad = 255;
    kirby.setPosition(118, 670);
    Player p(name, kirby);

    Texture metaTexture;
    if (!metaTexture.loadFromFile("images/meta.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    metaTexture.setRepeated(true);

    Sprite meta;
    meta.setTexture(metaTexture);
    meta.setPosition(800, random);
    meta.setScale(0.4f, 0.4f); // para reducir el tamaño



    Texture gordoTexture;
    if (!gordoTexture.loadFromFile("images/gordo.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    gordoTexture.setRepeated(true);

    Sprite gordo;
    gordo.setTexture(gordoTexture);
    gordo.setPosition(800, 650);
    gordo.setScale(0.5f, 0.5f); // para reducir el tamaño
    gordo.setOrigin(80, 80);

    Texture flameTexture;
    if (!flameTexture.loadFromFile("images/flamer.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    flameTexture.setRepeated(true);

    Sprite flame;
    flame.setTexture(flameTexture);
    flame.setPosition(800, random1);
    flame.setScale(0.1f, 0.1f); // para reducir el tamaño

    Texture pastoTexture;
    if (!pastoTexture.loadFromFile("images/montanas.jpg"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    pastoTexture.setRepeated(true);

    Sprite pasto;
    pasto.setTexture(pastoTexture);
    // pasto.setTextureRect(IntRect(0,0, 200, 160));
    pasto.setScale(2.5f, 2.0f);
    // int opacidad = 255;
    // pasto.setPosition(-20, 700);
    Pasto fondo(pasto);

    p.enemigos.push_back(Enemigo(meta, getRandom(100, 700)));
    p.enemigosa.push_back(EnemigoA(flame, getRandom(100, 700)));
    p.enemigost.push_back(EnemigoT(gordo, getRandom(100, 700)));

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();

            if (event.mouseButton.button == Keyboard::Space || event.mouseButton.button == Keyboard::Up || Keyboard::isKeyPressed(Keyboard::W))
            {
                p.click();

                // if(rando()%3 == 0){Enemigo* e1 = new Enemigo(sprite);
                // enemigos.push_back(e1);}
            }
        }

        if (Keyboard::isKeyPressed(Keyboard::D) || Keyboard::isKeyPressed(Keyboard::Right))
        {
            p.moveR();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left) || Keyboard::isKeyPressed(Keyboard::A))
        {
            p.moveL();
        }

        window.clear(Color(51, 51, 51));
        // grid.update();
        p.update();
        // p.enemigos[0].update();
        p.enemigost[0].update();
        p.enemigosa[0].update();
        for (auto &enemigo : p.enemigos)
        {
            enemigo.update();
            enemigo.drawTo(window);
        }


        /**
          for(int i = 0; i < p.enemigost.size(); i++)
          {

          }
          for(int i = 0; i < p.enemigosa.size(); i++)
          {


          }
          */
        grid.drawTo(window);
        fondo.drawTo(window);
        p.drawTo(window);
        // p.enemigos[0].drawTo(window);
        p.enemigost[0].drawTo(window);
        p.enemigosa[0].drawTo(window);

        window.display();
    }

    return 0;
}
