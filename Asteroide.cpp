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
Asteroide::Asteroide(sf::Texture &texturaNave,int randomer) {
    spriteNave.setTexture(texturaNave);
    this->generarOrigen(randomer);
    //Esto inicializa una semilla en base a la fecha,para evitar que se genere el mismo numero
    spriteNave.setPosition(x, y);
    spriteNave.setScale(0.8,0.8);
    cout<<"Posicion x:"<<spriteNave.getPosition().x<<" Posicion y:"<<spriteNave.getPosition().y<<endl;
}

void Asteroide::Mostrar(sf::RenderWindow &window) {
    window.draw(spriteNave);
}

void Asteroide::ActualizarPosicion() {
    spriteNave.move(sf::Vector2f(movimientoX, movimientoY));
    spriteNave.rotate(0.5);
}
void Asteroide::generarOrigen(int randomer) {
    int ladoDeOrigen;
    srand(std::random_device()() * randomer);
    x=rand() % anchoResolucion;
    ladoDeOrigen=rand() % 4;
    movimientoX = rand() % 4;
    
    switch (ladoDeOrigen){
        case 0:
            y=0;
            movimientoY=2;
        break;
        case 1:
            y=altoResolucion;//Hace que la pos
            movimientoY=-2;
        default:
            //x= altoResolucion;
            //movimientoY=-2;
            cout<<ladoDeOrigen<<endl;
        break;
    }
     if(x < anchoResolucion/2 && movimientoX<0 && y==0){
        movimientoX= -movimientoX;
    }
    if(x < anchoResolucion/2 && movimientoX<0 && y==altoResolucion){
        movimientoX= movimientoX * (-1);
    }
    if(x==0 && y==0 && movimientoX<0){
        movimientoX=movimientoX * (-1);
    }if(y> anchoResolucion/2 && x> altoResolucion/2 && movimientoX>0){
        movimientoX=-movimientoX;
        //movimientoY=-movimientoY;
    }
    
}
void Asteroide::verificarExistencia(int &cantidad,int indice,std::vector<Asteroide> &vector){
    int posX=spriteNave.getPosition().x;
    int posY=spriteNave.getPosition().y;
    if(posX > anchoResolucion+100 || posX<0 || posY<0 || posY>altoResolucion+100){
        vector.erase(vector.begin()+indice);
    }
}
