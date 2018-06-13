
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
#include <SFML/Window.hpp>

#include "Ship.h"
#include "Asteroide.h"
#include "Animacion.h"


class Bala {
public:
    Bala(game::Ship &nave, sf::Texture &textura);
    virtual ~Bala();
    void mostrar(sf::RenderWindow &window);
    sf::Sprite spriteBala;
    sf::Vector2f velocity;
    void colisiona(std::vector <Bala> &balas, std::vector <Asteroide> &asteroides, Animacion &explosionUno, sf::RenderWindow &App, int &puntaje);
    
};

#endif /* BALA_H */
