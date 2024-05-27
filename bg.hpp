#ifndef bg_h
#define bg_h
#include <SFML/Graphics.hpp>
#include <vector>
#include <bits/stdc++.h>
using namespace std;
using namespace sf;

class Pasto
{
public:
Sprite sprite;


Pasto(Sprite sprite);

 
void drawTo(RenderWindow &window);

};

#endif 