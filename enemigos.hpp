#ifndef enemigos_h
#define enemigos_h
#include <SFML/Graphics.hpp>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using namespace sf;

class Enemigo
{
public:
Vector2f speed;
Vector2f acc;
Sprite sprite;

Enemigo(Sprite sprite);

void drawTo(RenderWindow &window);
void update();


};

class EnemigoT
{
public:
Vector2f speed;
Vector2f acc;
Sprite sprite;

EnemigoT(Sprite sprite);

void drawTo(RenderWindow &window);
void update();


};

class EnemigoA
{
public:
Vector2f speed;
Vector2f acc;
Sprite sprite;

EnemigoA(Sprite sprite);

void drawTo(RenderWindow &window);
void update();


};

#endif