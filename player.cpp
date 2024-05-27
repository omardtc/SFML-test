#include "player.hpp"

Player::Player(string nombre, Sprite sprite)
{
    this->nombre = nombre;
    this->speed = {0.f, 0.f};
    this->vidas = 3;
    this->sprite = sprite;
    this->acc = {0.f, 0.f};
}

void Player::click()
{
        this->speed = {0.f, -50.f};
        this->acc.y = 5.f;
}

void Player::drawTo(RenderWindow &window)
{
    window.draw(this->sprite);
}

void Player::update()
{
    this->speed.y += this->acc.y;

    if(this->speed.y < -145.f)
    {
        this->speed.y = -25.f;
    }
    this->sprite.move(this->speed);

    if(this->sprite.getPosition().y + 160 > 800)
    {
        this->sprite.setPosition(0, 645);
    }

    if(this->sprite.getPosition().y < -18)
    {
        this->speed.y = 0.f;
        this->sprite.setPosition(0,-18);
    }
} 