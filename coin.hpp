
#ifndef coin_h
#define coin_h
#include <SFML/Graphics.hpp>
using namespace sf;
using namespace std;

class Coin 
{
public:
    Sprite sprite;

    Coin(Sprite sprite, float posX, float posY);

    void drawTo(RenderWindow &window);
    void update();
};

#endif