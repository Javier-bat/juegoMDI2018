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
    spriteBala.setPosition(nave.getPosition().x,nave.getPosition().y);
    velocity = {(float)(std::cos(nave.getRotation()*(PI/180)))*10,(float)(std::sin(nave.getRotation()*(PI/180)))*10};
    
}

void Bala::disparo(game::Ship &nave){
        apretado = true;
}

void Bala::mostrar(sf::RenderWindow &window, game::Ship &nave){
        if(apretado){
            if((spriteBala.getPosition().x <= altoResolucion || spriteBala.getPosition().x >= 0) && (spriteBala.getPosition().y <= anchoResolucion || spriteBala.getPosition().y >= 0)  ){
                window.draw(spriteBala);
                spriteBala.move(velocity);
            }
        } else {
            apretado = false;
        }
}


Bala::~Bala() {
};
