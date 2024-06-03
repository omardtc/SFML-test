#include <SFML/Graphics.hpp>
#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include <conio.h> 
#include "grid.hpp"
#include "player.hpp"
#include "enemigos.hpp"
#include "coin.hpp"
#include "life.hpp"
#include "bg.hpp"
using namespace sf;
using namespace std;


int width = 800;
int height = 800;
int numCells = 20;
int puntaje = 0;
string name;

float getRandom(float min, float max)
{
    return min + (rand()/(float)RAND_MAX)*(max-min);
}

void showLoadingScreen() {
    cout << "Cargando..." << endl;
    cout << "[";
    for (int i = 0; i < 80; ++i) {
        cout << "=";
       // cout.flush();
        this_thread::sleep_for(chrono::milliseconds(100));
    }
    cout << "]" << endl;
}

bool showMainMenu() {
    cout << "Bienvenido a Echo Dash!" << endl; 
 cout<<"######    ####    ##  ##    ####             ####       ##      ####    ##  ## "<<endl; 
 cout<<"##       ##  ##   ##  ##   ##  ##            ## ##     ####    ##  ##   ##  ## "<<endl;
 cout<<"##       ##       ##  ##   ##  ##            ##  ##   ##  ##   ##       ##  ## "<<endl;
 cout<<"####     ##       ######   ##  ##            ##  ##   ######    ####    ######  "<<endl;
 cout<<"##       ##       ##  ##   ##  ##            ##  ##   ##  ##       ##   ##  ##  "<<endl;
 cout<<"##       ##  ##   ##  ##   ##  ##            ## ##    ##  ##   ##  ##   ##  ##  "<<endl;
 cout<<"######    ####    ##  ##    ####             ####     ##  ##    ####    ##  ##  "<<endl;
                                                                                 
cout << "Presione Enter para continuar..." << endl;
    getchar(); // Esperar a que el usuario presione Enter


   
showLoadingScreen();


    cout << "Instrucciones:" << endl;
    cout << "1. El juego consiste en que Kirby debe recolectar monedas pero al mismo tiempo debe de esquivar los obstaculos, los cuales apareceran en posiciones aleatorias"<<endl;
    cout << "2. Kirby tiene tres vidas (3 oportunidades de chocar con un enemigo)"<<endl;
    cout << "3. Si sucede esto el juego termina y se cierra el programa"<<endl;
    cout << "4. para moverse de izquierda a derecha se puedem utilizar:las teclas A o D y tambien las flechas"<<endl;
    cout << "5. Para brincar se puede utilizar la flecha de arriba, la barra de espacio y la tecla W"<<endl;



showLoadingScreen();

    cout << "Si quiere jugar, presione Enter. De lo contrario, cierre el programa." << endl;
    cout << "Tiempo limite: 20 segundos" << endl;

    auto start = chrono::steady_clock::now(); //steady, un reloj que no retrocede
    while (true) {
        auto end = chrono::steady_clock::now(); //now, regresa el tiempo actual
        auto diff = end - start;
        if (diff > chrono::seconds(20)) {
            cout << "Tiempo limite alcanzado. Cerrando el programa..." << endl;
            return false;
        }
        if (_kbhit()) { //Esperar hasta que se presione una tecla
            if (_getch() == '\r') { //Lee un carácter
                cout << "Comenzando el juego..." << endl;
                return true;
            }
        }
    }
}


int main()
{
    
   // if (!showMainMenu()) {
    //  return 0;
  //}
  
    RenderWindow window(VideoMode(800, 800), "Echo Dash");
    window.setFramerateLimit(10);
    Grid grid(numCells, numCells, width, height);
    srand(45);

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
    flame.setScale(0.1f, 0.1f); 
    Texture coinTexture;
    if (!coinTexture.loadFromFile("images/moneda.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    coinTexture.setRepeated(true);

    Sprite coin;
    coin.setTexture(coinTexture);
    coin.setPosition(800, 650);
    coin.setScale(0.1f, 0.1f); 
    //coin.setOrigin(80, 80);

    Texture vidaTexture;
    if (!vidaTexture.loadFromFile("images/life.png"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    vidaTexture.setRepeated(true);

    Sprite vida;
    vida.setTexture(vidaTexture);
    vida.setPosition(0, 0);
    vida.setScale(0.1f, 0.1f); // para reducir el tamaño
    vida.setOrigin(80, 80);

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

    Texture dTexture;
    if (!dTexture.loadFromFile("images/defeat.jfif"))
    {
        cout << "Error al cargar imagen" << endl;
    }
    dTexture.setRepeated(true);

    Sprite d;
    d.setTexture(dTexture);
    d.setPosition(0,0);
    d.setScale(     3.125f, 4.125f); 

   // p.enemigos.push_back(Enemigo(meta, getRandom(100, 700)));
    //p.enemigosa.push_back(EnemigoA(flame, getRandom(100, 700)));
    //p.enemigost.push_back(EnemigoT(gordo, getRandom(100, 700)));

     Clock clock;
    Clock gameOverClock; // Reloj para el tiempo de game over
    float timer = 0;
    bool gameOver = false;


    p.lifes.push_back(Vida(vida, 0, 10));
    p.lifes.push_back(Vida(vida, 40, 10));
    p.lifes.push_back(Vida(vida, 80, 10));

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
        float tiempo = clock.restart().asSeconds();
        timer+=tiempo;

           if (timer > 6.0f)
        {
            float randomY = getRandom(100, 600);
            float randomX = getRandom(100, 600);
            p.enemigos.push_back(Enemigo(meta, randomY));
            p.enemigosa.push_back(EnemigoA(flame, randomY));
            p.enemigost.push_back(EnemigoT(gordo, randomY));
            p.monedas.push_back(Coin(coin, randomX, randomY));
            timer = 0;
        }

        grid.drawTo(window);
        fondo.drawTo(window);

        for (int i = 0; i < p.lifes.size(); i++)
        {
            p.lifes[i].update();
            p.lifes[i].drawTo(window);
        }
/*
        for (int i = 0; i < p.monedas.size(); i++)
        {
            p.monedas[i].update();
            p.monedas[i].drawTo(window);
            if (p.puntos())
            {
                puntaje++;
                p.monedas.erase(p.monedas.begin() + i);
            }
        }
*/
for (int i = 0; i < p.monedas.size();)
{
    p.monedas[i].update();
    p.monedas[i].drawTo(window);
    if (p.puntos(p.monedas[i]))
    {
        puntaje++;
        p.monedas.erase(p.monedas.begin() + i); // Elimina esta moneda
    }
    else
    {
        ++i; 
    }
}

       
        for (int i = 0; i < p.enemigos.size(); i++)
        {
            p.enemigos[i].update();
            p.enemigos[i].drawTo(window);
        }
        for (int i = 0; i < p.enemigosa.size(); i++)
        {
            p.enemigosa[i].update();
            p.enemigosa[i].drawTo(window);
        }
        for (int i = 0; i < p.enemigost.size(); i++)
        {
            p.enemigost[i].update();
            p.enemigost[i].drawTo(window);
        }

        if (p.vidas > 0)
        {
            p.update();
            p.drawTo(window);
        }
        else
        {
            if (!gameOver)
            {
                gameOverClock.restart(); // Reiniciar el reloj al momento del game over
                gameOver = true;
            }
            window.draw(d); // Mostrar el sprite de game over que abarca toda la ventana
            if (gameOverClock.getElapsedTime().asSeconds() > 3.0f)
            {
                window.close(); // Cerrar la ventana después de 3 segundos
            }
        }

        Font font;
        if (!font.loadFromFile("images/font.ttf"))
        {
            cout << "Error al cargar la fuente" << endl;
        }
        Text textoPuntaje;
        textoPuntaje.setFont(font);
        textoPuntaje.setString("Puntaje: " + to_string(puntaje));
        textoPuntaje.setCharacterSize(24);
        textoPuntaje.setFillColor(Color::White);
        textoPuntaje.setPosition(600, 25);

        window.draw(textoPuntaje);
        window.display();
    }
    return 0;
}