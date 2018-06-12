/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Bala.h
 * Author: german
 *
 * Created on 4 de junio de 2018, 16:01
 */

#ifndef BALA_H
#define BALA_H

#include <SFML/Graphics/Sprite.hpp>

#include "Ship.h"


class Bala {
public:
    Bala(game::Ship &nave, sf::Texture &textura);
    virtual ~Bala();
    void mostrar(sf::RenderWindow &window);
    sf::Sprite spriteBala;
    sf::Vector2f velocity;
  
};

#endif /* BALA_H */
