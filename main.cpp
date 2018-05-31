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
#include <list>
using namespace std;

/*
 * 
 */
//Resolucion,aún hay que trabajar en esto
int alto=sf::VideoMode::getDesktopMode().height;
int ancho=sf::VideoMode::getDesktopMode().width;
std::vector<Pantalla*> pantallas;

int pantalla;

int main(int argc, char** argv) {
    //Setea la resolucion de la pantalla
   sf::RenderWindow window(sf::VideoMode(ancho,alto), "Asteroids",sf::Style::Fullscreen);
   
   
   MenuPrincipal menuP;
   PantallaJuego pantallaJuego;
   pantallas.push_back(&menuP);
   pantallas.push_back(&pantallaJuego);
   
   while (pantalla >= 0) {
       pantalla = pantallas[pantalla] -> Run(window);
    }

   
    return 0;
}

