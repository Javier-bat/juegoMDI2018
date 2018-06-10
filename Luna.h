/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Luna.h
 * Author: root
 *
 * Created on 10 de junio de 2018, 01:05
 */

#ifndef LUNA_H
#define LUNA_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/Texture.hpp>

class Luna {
public:
    Luna(sf::Texture &texturaLuna);
    void Mostrar(sf::RenderWindow &window);
    sf::Sprite getSprite();
    void verificarExistencia(int indice);


private:
    int y;
    int x;
    int movimientoY;
    int movimientoX;
    void generarOrigen();
    sf::Sprite spriteLuna;
};

#endif /* LUNA_H */