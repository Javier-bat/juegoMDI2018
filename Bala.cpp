/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bala.cpp
 * Author: german
 * 
 * Created on 4 de junio de 2018, 16:01
 */

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include "Bala.h"
#include "Ship.h"


Bala::Bala(game::Ship &nave) {
    texturaBala.loadFromFile("Imagenes/new_bullet.png");
    spriteBala.setTexture(texturaBala);
    spriteBala.setPosition(nave.getPosition().x,nave.getPosition().y);
    spriteBala.setScale(0.25,0.25);
    spriteBala.setOrigin(nave.getOrigin().x,nave.getOrigin().y);
}

void Bala::mostrar(sf::RenderWindow &window){
    window.draw(spriteBala);
}

Bala::Bala(const Bala& orig) {
}

Bala::~Bala() {
}

void Bala::update(){
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::E)){
        spriteBala.setPosition(sf::Vector2f)
    }
}