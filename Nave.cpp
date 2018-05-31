/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nave.cpp
 * Author: gabrielascurra
 * 
 * Created on 28 de mayo de 2018, 23:43
 */

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Nave.h"

Nave::Nave() {
    if (!texture.loadFromFile("image.png")) {
        // error...
    }
    sprite.setTexture(texture);
    float x=sf::VideoMode::getDesktopMode().height;
    float y=sf::VideoMode::getDesktopMode().width;
    
}
void Nave::mostrarNave(sf::RenderWindow &window){
    window.draw(sprite);
}
void Nave::moverNave(){
    sprite.move(sf::Vector2f(2,2));
}

