#include "coin.hpp"

Coin::Coin(Sprite sprite, float posX, float posY)
{
    this->sprite = sprite;
    this->sprite.setPosition(posX, posY);
}

void Coin::drawTo(RenderWindow &window)
{
    window.draw(this->sprite);
}

void Coin::update()
{
    this->sprite.move(0.f, 0.f);
}