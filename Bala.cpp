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
    velocity = {(float)(std::cos(nave.getSprite().getRotation()*(PI/180)))*10,(float)(std::sin(nave.getSprite().getRotation()*(PI/180)))*10};
    
}

void Bala::mostrar(sf::RenderWindow &window){
                window.draw(spriteBala);
                spriteBala.move(velocity);
}


Bala::~Bala() {
};

void Bala::colisiona(std::vector <Bala> &balas, std::vector <Asteroide> &asteroides, Animacion &explosionUno, sf::RenderWindow &App){
    for(int i=0;i < asteroides.size();i++){
            for(int j=0;j < balas.size();j++){
                if(asteroides[i].getSprite().getGlobalBounds().intersects(balas[j].spriteBala.getGlobalBounds())){      
                    sf::Vector2f posicion = {(asteroides[i].getSprite().getPosition().x+balas[j].spriteBala.getPosition().x)/2,(asteroides[i].getSprite().getPosition().y+balas[j].spriteBala.getPosition().y)/2};
                    do{
                        explosionUno.mostrar(App,posicion);    
                        explosionUno.actualizar();
                    }while(!explosionUno.termina());
                    asteroides.erase(asteroides.begin()+i);
                    balas.erase(balas.begin()+j);
                }    
            }
        }   
}