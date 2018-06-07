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
#include <random>
using namespace std;
Asteroide::Asteroide(sf::Texture &texturaNave) {
    
    spriteNave.setTexture(texturaNave);
    this->generarOrigen();
    //Esto inicializa una semilla en base a la fecha,para evitar que se genere el mismo numero
    srand(std::random_device()() %360);
    int y = rand() % altoResolucion;
    spriteNave.setPosition(y, x);
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
    srand(std::random_device()() % 360);
    y = rand() % altoResolucion;
    ladoDeOrigen=rand() % 2;
    movimientoX = rand() % 4;
    
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
     if(y < anchoResolucion/2 && movimientoX<0 && x==0){
        movimientoX= -movimientoX;
        cout<<"Movimiento en x modificado:"<<movimientoX<<endl;
    }
    if(y < anchoResolucion/2 && movimientoX<0 && x==altoResolucion){
        movimientoX= movimientoX * (-1);
    }
    
}
void Asteroide::verificarExistencia(int &cantidad,int indice,std::vector<Asteroide> &vector){
    int posX=spriteNave.getPosition().x;
    int posY=spriteNave.getPosition().y;
    if(posX > anchoResolucion || posY > altoResolucion){
        cantidad=-1;
        vector.erase(vector.begin()+indice);
        cout<<"Tamaño del vector="<<vector.size()<<endl;
    }
}
