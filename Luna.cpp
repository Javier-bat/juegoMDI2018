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
    
    
    spriteLuna.setRotation((float)(rand() % 359));
    
    
     if(anchoResolucion>600||altoResolucion>1439){
     spriteLuna.setScale(0.5, 0.5); 
  }else{spriteLuna.setScale(0.2,0.2);}
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
    y = -150;
    x = (250+rand() % (anchoResolucion-250)-250); //Genera posicion aleatoria para el ancho
   movimientoY = rand() %2 +1;
   
}
Luna::~Luna(){

}
void Luna::verificarExistencia(int indice, std::vector<Luna> &vector,sf::Clock relojLuna2) {
    int posX = spriteLuna.getPosition().x;
    int posY = spriteLuna.getPosition().y;
    if (posX > anchoResolucion + 100 || posX < 0 || posY < -200 || posY > altoResolucion + 500) {
        vector.erase(vector.begin() + indice);
        relojLuna2.restart();
    }
}

