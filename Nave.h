/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nave.h
 * Author: gabrielascurra
 *
 * Created on 28 de mayo de 2018, 23:43
 */

#ifndef NAVE_H
#define NAVE_H

#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>


class Nave {
public:
    Nave();
    void mostrarNave(sf::RenderWindow &window);
    void moverNave();
    
private:
    /*Estas variables se setean como globales,para evitar que el sprite
    se renderize como un cuadro blanco*/
    sf::Texture texture;
    sf::Sprite sprite;
    
};

#endif /* NAVE_H */

