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
#include <valarray>
#include "Bala.h"
#include "Ship.h"
#include "ConstantesGlobales.h"

#define PI  3.14159265358979

Bala::Bala(game::Ship &nave, sf::Texture &textura) {
    spriteBala.setTexture(textura);
    spriteBala.setScale(0.25,0.25);
    spriteBala.setPosition(nave.getSprite().getPosition().x,nave.getSprite().getPosition().y);
    velocity = {((float)(std::cos(nave.getSprite().getRotation()*(PI/180)))*10),((float)(std::sin(nave.getSprite().getRotation()*(PI/180)))*10)};
    
}

void Bala::mostrar(sf::RenderWindow &window){
                window.draw(spriteBala);
                spriteBala.move(velocity.x,velocity.y);
}


Bala::~Bala() {
};
