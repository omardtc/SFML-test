#ifndef player_h
#define player_h
#include <SFML/Graphics.hpp>
#include <vector>
#include <bits/stdc++.h>
#include "enemigos.hpp"
#include "life.hpp"
#include "coin.hpp"
using namespace std;
using namespace sf;

class Player
{
public:
Sprite sprite;
string nombre;
int vidas = 3;
Vector2f speed = {0.f, 0.f};
Vector2f acc = {0.f, 20.f};
vector<Enemigo> enemigos;
vector<EnemigoA> enemigosa;
vector<EnemigoT> enemigost;
vector<Coin> monedas;
vector<Vida> lifes;

Player(string nombre, Sprite sprite);

void click(); 
void moveR();
void moveL();
void drawTo(RenderWindow &window);
void update();
bool choque();
bool puntos();

};

#endif 