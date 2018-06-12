/*
 *
 * 
 * 
 */

/* 
 * 
 * 
 * 
 * 
 */

#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

#include "Luna.h"
#include "ConstantesGlobales.h"
#include <random>
#include <signal.h>
using namespace std;

Luna::Luna(sf::Texture &texturaNave) {
    spriteLuna.setTexture(texturaNave);
    this->generarOrigen();
    spriteLuna.setPosition(x, y);
    spriteLuna.setScale(0.5, 0.5);
    
    spriteLuna.setRotation((float)(rand() % 359));
    
   
}

void Luna::Mostrar(sf::RenderWindow &window) {
    window.draw(spriteLuna);
}

void Luna::ActualizarPosicion() {
     srand(time(NULL));
     int num = (250+rand()%((altoResolucion-250)-100));
    spriteLuna.move(sf::Vector2f(movimientoX, movimientoY));
    if((int)spriteLuna.getPosition().y > num-12 && (int)spriteLuna.getPosition().y <num+12){
    
        movimientoY=0;
    }
    
    
    
}
void Luna::setMovimientoY(int movimientoY){
    this->movimientoY = movimientoY;

}

void Luna::generarOrigen() {

    movimientoX = 0;
    y = 0;
    x = (250+rand() % (anchoResolucion-250)-250); //Genera posicion aleatoria para el ancho
   movimientoY = rand() %3 +1;
   
}
Luna::~Luna(){

}
void Luna::verificarExistencia(int indice, std::vector<Luna> &vector) {
    int posX = spriteLuna.getPosition().x;
    int posY = spriteLuna.getPosition().y;
    if (posX > anchoResolucion + 100 || posX < 0 || posY < 0 || posY > altoResolucion + 100) {
        vector.erase(vector.begin() + indice);
    }
}

