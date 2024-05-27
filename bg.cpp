#include "bg.hpp"

Pasto::Pasto(Sprite sprite)
{
    this->sprite = sprite;
}

void Pasto::drawTo(RenderWindow &window)
{
    window.draw(this->sprite);
}