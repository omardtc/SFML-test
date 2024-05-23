#include "enemigos.hpp"

Enemigo::Enemigo(Sprite sprite)
{
    this->speed = {-15.f, 0.f};
    this->acc = {0.f,0.f};
    this->sprite = sprite; 
}

void Enemigo::drawTo(RenderWindow &window)
{
    window.draw(this->sprite);
}

void Enemigo::update()
{
    this->speed.x = -15;
    this->sprite.move(this->speed);
}