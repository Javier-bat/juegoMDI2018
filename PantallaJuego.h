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
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Sound.hpp>

class PantallaJuego {
public:
    PantallaJuego();
    int Run(sf::RenderWindow &App);
    void setRunning(bool run);
private:
    sf::Texture texturaAsteroide;
    sf::Texture texturaAsteroide2;
    sf::Texture texturaAsteroide3;
    sf::Texture texturaLuna;
    sf::Texture texturaBala;
    sf::Texture texturaNaveReal;
    sf::Texture fondo; // creo una textura para el fondo
    sf::Texture explosion;
    //Sonidos
    sf::Music musicaFondo;
    sf::SoundBuffer explosionNaveBuffer;
    sf::Sound explosionNaveSound;
    sf::SoundBuffer explosionAstBuffer;
    sf::Sound explosionAstSound;
    //Texto
    sf::Text score;
    sf::Text cuentaRegresiva;
};

#endif /* PANTALLAJUEGO_H */

