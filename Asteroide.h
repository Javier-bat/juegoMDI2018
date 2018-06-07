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

class Asteroide {
public:
    Asteroide(sf::Texture &texturaNave);
    void Mostrar(sf::RenderWindow &window);
    void ActualizarPosicion();
    void verificarExistencia(int &cantidad,int indice,std::vector<Asteroide> &vector);
private:
    void generarOrigen();
   // sf::Texture texturaNave;
    sf::Sprite spriteNave;
    int movimientoX;
    int x;
    int y;
    int movimientoY;
    int randomSeed=0;
};

#endif /* ASTEROIDE_H */

