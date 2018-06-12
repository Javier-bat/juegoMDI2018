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
#include <SFML/Graphics.hpp>
#include "Asteroide.h"
#include <array>
#include <list>
#include <SFML/Audio/Music.hpp>

class PantallaJuego {
public:
    PantallaJuego();
    int Run(sf::RenderWindow &App);
    void setRunning(bool run);
private:
    sf::Texture texturaNave;
    sf::Texture texturaNave2;
    sf::Texture texturaNave3;
    sf::Texture texturaLuna;
    sf::Texture texturaBala;
    sf::Texture fondo; // creo una textura para el fondo
    sf::Texture explosion;
    //Sonidos
    sf::Music musicaFondo;
    //Texto
    sf::Text score;
};

#endif /* PANTALLAJUEGO_H */

