/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Asteroide.h
 * Author: gabriel
 *
 * Created on 2 de junio de 2018, 14:52
 */

#ifndef ASTEROIDE_H
#define ASTEROIDE_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>


class Asteroide {
public:
    Asteroide(sf::Texture &texturaNave,int velocidad);
    void Mostrar(sf::RenderWindow &window);
    void ActualizarPosicion();
    void verificarExistencia(int indice,std::vector<Asteroide> &vector);
    sf::Sprite getSprite();
    void setVelocidad(int velocidad);
private:
    void generarOrigen();
   // sf::Texture texturaNave;
    sf::Sprite spriteNave;
    int movimientoX;
    int y;
    int x;
    int movimientoY;
    int randomSeed=0;
};

#endif /* ASTEROIDE_H */

