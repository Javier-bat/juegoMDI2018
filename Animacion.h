/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Animacion.h
 * Author: german
 *
 * Created on 11 de junio de 2018, 23:25
 */

#ifndef ANIMACION_H
#define ANIMACION_H

#include <SFML/Graphics.hpp>

class Animacion {
public:
    Animacion(sf::Texture &textura, int x, int y, int w, int h, int count, float speed);
    virtual ~Animacion();
    void actualizar();
    bool termina();
    void mostrar(sf::RenderWindow &window, sf::Vector2f posicion);
    std::vector<sf::IntRect> frames;
    sf::Sprite spriteExplosion;

private:
    float frame; 
    float speed;
};

#endif /* ANIMACION_H */

