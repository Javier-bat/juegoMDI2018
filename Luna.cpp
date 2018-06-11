/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Luna.cpp
 * Author: root
 * 
 * Created on 10 de junio de 2018, 01:05
 */

#include "Luna.h"
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "ConstantesGlobales.h"

#include <time.h>
#include <random>
using namespace std;
Luna::Luna(sf::Texture &texturaLuna) {
   spriteLuna.setTexture(texturaLuna); 
   this->generarOrigen();
   
    
}
void Luna::Mostrar(sf::RenderWindow &window) {
    window.draw(spriteLuna);
}


void Luna::generarOrigen() {

  y=0;
  x=rand() % anchoResolucion;//Genera posicion aleatoria para el ancho
movimientoY=3;  
movimientoX=0;
}
void Luna::verificarExistencia(int indice){
    int posX=spriteLuna.getPosition().x;
    int posY=spriteLuna.getPosition().y;
    if(posX > anchoResolucion+100 || posX<0 || posY<0 || posY>altoResolucion+100){
        indice =1;
    }
    else{
        indice =0;
    }
}
