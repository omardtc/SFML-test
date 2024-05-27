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
        this->sprite.setPosition(this->sprite.getPosition().x, 620);
        this->speed.y = 0.f;
        this->acc = {0.f, 0.f};
    }

    if(this->sprite.getPosition().y < -18)
    {
        this->speed.y = 0.f;
        this->sprite.setPosition(this->sprite.getPosition().x,-18);
    }

    if(this->sprite.getPosition().x < 0)
    {
        this->speed.x = 0.f;
        this->sprite.setPosition(0, this->sprite.getPosition().y);
    }

    if(this->sprite.getPosition().x + 100 > 800)
    {
        this->speed.x = 0.f;
        this->sprite.setPosition(700, this->sprite.getPosition().y);
    }
    this->speed.x =0.f;
} 

void Player::moveR()
{
    this->sprite.setScale(0.5f, 0.5f);
    this->speed.x = 10;
    this->sprite.move(this->speed);
}

void Player::moveL()
{
    this->sprite.setScale(-0.5f, 0.5f);
    this->speed.x = -10;
    this->sprite.move(this->speed);
}