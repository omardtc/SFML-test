
#ifndef life_h
#define life_h
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Vida
{
public:
    Sprite sprite;

    Vida(Sprite sprite, float x, float y);

    void drawTo(RenderWindow &window);
    void update();
};

#endif