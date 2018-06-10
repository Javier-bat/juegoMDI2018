/* 
 * File:   main.cpp
 * Author: gabrielascurra
 *
 * Created on 22 de mayo de 2018, 11:47
 */
#define SFML_STATIC
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Pantalla.h"
#include "MenuPrincipal.h"
#include "PantallaJuego.h"
#include "Ship.h"
#include "ConstantesGlobales.h"
#include <list>
using namespace std;

/*
 * 
 */
//Resolucion,aún hay que trabajar en esto
std::vector<Pantalla*> pantallas;

int pantalla;

int main(int argc, char** argv) {
    //Setea la resolucion de la pantalla
   sf::RenderWindow window(sf::VideoMode(anchoResolucion,altoResolucion), "Asteroids",sf::Style::Fullscreen);
   
   MenuPrincipal menuP;
   menuP.Run(window);
   
    return 0;
}

