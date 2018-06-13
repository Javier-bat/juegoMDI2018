/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animacion.cpp
 * Author: german
 * 
 * Created on 11 de junio de 2018, 23:25
 */

#include "Animacion.h"
#include <SFML/Graphics.hpp>
#include <unistd.h>

Animacion::Animacion(sf::Texture &textura, int x, int y, int w, int h, int count, float speed) {
    frame = 0;
    this->speed = speed;

    for (int i=0;i< count;i++){
            frames.push_back( sf::IntRect(x+i*w, y, w, h)  );
       
    }    
    spriteExplosion.setTexture(textura);
    spriteExplosion.setOrigin(w/2,h/2);
    spriteExplosion.setTextureRect(frames[0]);
    
}

void Animacion::actualizar(){
   
    frame += speed;
    if (frame >= frames.size()) 
        frame -= frames.size();
    if (frames.size() > 0) 
        
        spriteExplosion.setTextureRect( frames[int(frame)] );
 

}

bool Animacion::termina(){
    	  return frame + speed > frames.size();
}

Animacion::~Animacion() {
}

void Animacion::mostrar(sf::RenderWindow &window, sf::Vector2f posicion){
    spriteExplosion.setPosition(posicion);
       

    window.draw(spriteExplosion);
}