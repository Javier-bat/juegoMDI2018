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
void Asteroide::generarOrigen() {
    int ladoDeOrigen;
    srand(std::random_device()());//Semilla para rand()
    ladoDeOrigen=rand() % 5;
    movimientoX = rand() % 4;
    
    switch (ladoDeOrigen){
        case 0://Aparecen desde arriba
            y=0;
            x=rand() % anchoResolucion;//Genera posicion aleatoria para el ancho
            movimientoY=2;
            //Ambos if, hacen que los asteroides convergan hacia el centro
            if(x > anchoResolucion/2 && movimientoX>=0) {
                movimientoX=-movimientoX;
            }else
                if(x < anchoResolucion/2 && movimientoX<=0) 
                movimientoX=movimientoX *(-1);
        break;
        case 1://Aparecen desde abajo
            y=altoResolucion;
            x=rand() % anchoResolucion;//Genera posicion aleatoria para el ancho
            movimientoY=-2;
            //Ambos if, hacen que los asteroides convergan hacia el centro
            if(x < anchoResolucion/2 && movimientoX<=0){
                movimientoX=movimientoX *(-1);
            }else
                if(x>anchoResolucion/2 && movimientoX>=0){
                    movimientoX=-movimientoX;
                }
            break;
        case 2://Aparecen del lado izquierdo
            y=rand() % altoResolucion;
            x=0;
            if(movimientoX==0) {//Es para evitar que la rotacion saque al asteroide de la pantalla
                movimientoX+=1;
            }
            //Ambos if, hacen que los asteroides convergan hacia el centro
            if(y > altoResolucion/2 && movimientoY>=0){
                movimientoY=-2;
                
            }if(y < altoResolucion/2 && movimientoY<=0){
                    movimientoY=2;
            }
            break;
        default://Aparecen del lado derecho
            y=rand() % altoResolucion;
            x=anchoResolucion;
            movimientoX=-movimientoX;
            if(movimientoX == 0) {//Es para evitar que la rotacion saque al asteroide de la pantalla
                movimientoX-=1;
            }if(y > altoResolucion/2 && movimientoY>=0){
                movimientoY=-2;
            }if(y < altoResolucion/2 && movimientoY<=0){
                    movimientoY=2;
            }
            break;
    }
    
}
void Asteroide::verificarExistencia(int indice,std::vector<Asteroide> &vector){
    int posX=spriteNave.getPosition().x;
    int posY=spriteNave.getPosition().y;
    if(posX > anchoResolucion+100 || posX<0 || posY<0 || posY>altoResolucion+100){
        vector.erase(vector.begin()+indice);
    }
}
