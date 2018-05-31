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
#include <cstdlib>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "Nave.h"

using namespace std;

Nave::Nave() {
    if (!texture.loadFromFile("image.png")) {
        // error...
    }
    sprite.setTexture(texture);
    float x = sf::VideoMode::getDesktopMode().height;
    float y = sf::VideoMode::getDesktopMode().width;

}

void Nave::mostrarNave(sf::RenderWindow &window) {
    window.draw(sprite);
}

void Nave::moverNave(string direccion) {
    sf::Vector2f movimiento(0,0);
    if (direccion == "derecha"){
        movimiento.x=2;
    }
    if (direccion == "izquierda"){
        movimiento.x=-2;
    }
    if(direccion == "abajo"){
        movimiento.y=2;
    }
    if(direccion == "arriba"){
        movimiento.y=-2;
    }
    sprite.move(movimiento);
}

