/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controles.h
 * Author: gabrielascurra
 *
 * Created on 12 de junio de 2018, 23:02
 */

#ifndef CONTROLES_H
#define CONTROLES_H

#include <SFML/Window/Keyboard.hpp>


class Controles {
public:
    Controles();
    sf::Keyboard::Key ObtenerControlArriba();
private:
    sf::Keyboard::Key controlArriba;
    sf::Keyboard::Key controlAbajo;
    sf::Keyboard::Key controlDerecha;
    sf::Keyboard::Key controlIzquierda;
    sf::Keyboard::Key controlGirarIzquiera;
    sf::Keyboard::Key controlGirarDerecha;
    sf::Keyboard::Key controlDisparar;
};

#endif /* CONTROLES_H */

