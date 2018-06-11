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

#include "Luna.h"
#include "ConstantesGlobales.h"
#include <random>
using namespace std;

Luna::Luna(sf::Texture &texturaNave) {
    spriteLuna.setTexture(texturaNave);
    this->generarOrigen();
    //Esto inicializa una semilla en base a la fecha,para evitar que se genere el mismo numero
    spriteLuna.setPosition(x, y);
    spriteLuna.setScale(0.8, 0.8);
}

void Luna::Mostrar(sf::RenderWindow &window) {
    window.draw(spriteLuna);
}

void Luna::ActualizarPosicion() {
     srand(time(NULL));
     int num = (100+rand()%((altoResolucion-99)-100));
    spriteLuna.move(sf::Vector2f(movimientoX, movimientoY));
    if(spriteLuna.getPosition().y >= num){
    
        movimientoY=0;
    }
    
}
void Luna::setMovimientoY(int movimientoY){
    this->movimientoY = movimientoY;

}

void Luna::generarOrigen() {

    movimientoX = 0;
    y = 0;
    x = (100+rand() % (anchoResolucion-100)-100); //Genera posicion aleatoria para el ancho
   movimientoY = rand() %3 +1;
}

void Luna::verificarExistencia(int indice, std::vector<Luna> &vector) {
    int posX = spriteLuna.getPosition().x;
    int posY = spriteLuna.getPosition().y;
    if (posX > anchoResolucion + 100 || posX < 0 || posY < 0 || posY > altoResolucion + 100) {
        vector.erase(vector.begin() + indice);
    }
}

