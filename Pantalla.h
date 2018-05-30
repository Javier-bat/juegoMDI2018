/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Pantalla.h
 * Author: gabrielascurra
 *
 * Created on 27 de mayo de 2018, 11:48
 */

#ifndef PANTALLA_H
#define PANTALLA_H

#include <SFML/Graphics/RenderWindow.hpp>


class Pantalla {
public:
    virtual int Run (sf::RenderWindow &App) = 0;

};

#endif /* PANTALLA_H */

