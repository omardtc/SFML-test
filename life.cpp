#include "life.hpp"

Vida::Vida(Sprite sprite, float x, float y)
{
    this->sprite = sprite;
    this->sprite.setPosition(x,y);
}

void Vida::drawTo(RenderWindow &window)
{
    window.draw(this->sprite);
}

void Vida::update()
{
    this->sprite.move(0.f, 0.f);
}