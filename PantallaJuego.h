/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PantallaJuego.h
 * Author: gabrielascurra
 *
 * Created on 27 de mayo de 2018, 12:27
 */

#ifndef PANTALLAJUEGO_H
#define PANTALLAJUEGO_H
#include "Pantalla.h"
#include <SFML/Graphics.hpp>
#include "Asteroide.h"
#include <array>
#include <list>
#include <SFML/Audio/Music.hpp>

class PantallaJuego : public Pantalla {
public:
    PantallaJuego();
    int Run(sf::RenderWindow &App);
    void setRunning(bool run);
    sf::Music musicaFondo;
private:
    sf::Texture texturaNave;
    sf::Texture texturaNave2;
    sf::Texture texturaNave3;
    sf::Texture fondo; // creo una textura para el fondo
};

#endif /* PANTALLAJUEGO_H */

