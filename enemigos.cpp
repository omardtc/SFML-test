#include "enemigos.hpp"

Enemigo::Enemigo(Sprite sprite, float pos)
{
    this->speed = {-15.f, 0.f};
    this->acc = {0.f,0.f};
    this->sprite = sprite; 
    this->sprite.setPosition(800, pos);
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

EnemigoT::EnemigoT(Sprite sprite, float pos)
{
    this->sprite = sprite;
    this->speed = {-30.f, 0.f};
    this->acc = {0.f, 0.f};
    this->sprite.setPosition(800, pos);
}

void EnemigoT::drawTo(RenderWindow &window)
{
    window.draw(this->sprite);
}

void EnemigoT::update()
{
    
    this->speed.x = -30;
    this->sprite.move(this->speed);
    this->sprite.rotate(-15.0f);
}

EnemigoA::EnemigoA(Sprite sprite, float pos)
{
    this->sprite = sprite;
    this->speed = {-25.f, 0.f};
    this->acc = {0.f, 0.f};
    this->sprite.setPosition(800, pos);
}

void EnemigoA::drawTo(RenderWindow &window)
{
    window.draw(this->sprite);
}

void EnemigoA::update()
{
    
    this->speed.x = -25;
    this->speed.y = -10;
    this->sprite.move(this->speed);
    this->sprite.rotate(-30);


}

