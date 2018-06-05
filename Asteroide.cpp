/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Asteroide.cpp
 * Author: gabriel
 * 
 * Created on 2 de junio de 2018, 14:52
 */

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "Asteroide.h"
#include <time.h>

Asteroide::Asteroide() {
    if (!texturaNave.loadFromFile("Imagenes/asteroideGrande.png")) {
    }
    spriteNave.setTexture(texturaNave);
    srand(time(NULL));
    movimientoX=-3+rand()%2 + 2;
   int  y= rand()%sf::VideoMode::getDesktopMode().height;
   std::cout<<"Posicion:"+std::to_string(y)<<std::endl;
   spriteNave.setPosition(y,0);
       std::cout<<"Valor: "+ std::to_string(movimientoX)<<std::endl;//Esto es solo una traza para mostrar el número generado

}
void Asteroide::Mostrar(sf::RenderWindow &window){
    window.draw(spriteNave);
}
void Asteroide::ActualizarPosicion(){
    spriteNave.move(sf::Vector2f(movimientoX,2));
    spriteNave.rotate(0.5);
}

