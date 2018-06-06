/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Asteroide.cpp
 * Author: gabriel
 * 
 * Created on 2 de junio de 2018, 14:52
 */

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "Asteroide.h"
#include "ConstantesGlobales.h"
#include <time.h>

Asteroide::Asteroide() {
    int multiplicadorMovimiento;
    if (!texturaNave.loadFromFile("Imagenes/asteroideGrande.png")) {
    }
    spriteNave.setTexture(texturaNave);
    this->generarOrigen();
    //Esto inicializa una semilla en base a la fecha,para evitar que se genere el mismo numero
    srand(time(NULL));
    movimientoX = rand() % 4;
    //Este bloque,genera un numero entre 0 y 1,si es 1,hace que el movimiento sea negativo,si es 0 lo deja positivo
    multiplicadorMovimiento=rand() % 2;
    if(multiplicadorMovimiento == 1){
        movimientoX=-movimientoX;
    }
    //Fin del bloque
    int y = rand() % altoResolucion;
    std::cout << "Posicion:" + std::to_string(y) << std::endl;//Traza
    spriteNave.setPosition(y, x);
    std::cout << "Valor: " + std::to_string(movimientoX) << std::endl; //Esto es solo una traza para mostrar el número generado

}

void Asteroide::Mostrar(sf::RenderWindow &window) {
    window.draw(spriteNave);
}

void Asteroide::ActualizarPosicion() {
    spriteNave.move(sf::Vector2f(movimientoX, movimientoY));
    spriteNave.rotate(0.5);
}
void Asteroide::generarOrigen() {
    int ladoDeOrigen;
    srand(time(NULL));
    ladoDeOrigen=rand() % 2;
    std::cout<<"Random generado:"<<ladoDeOrigen<<std::endl;
    switch (ladoDeOrigen){
        case 0:
            x=0;
            movimientoY=2;
        break;
        default:
            x= altoResolucion;
            movimientoY=-2;
        break;
    }
}

