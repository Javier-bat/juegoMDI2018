/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.cpp
 * Author: gabrielascurra
 * 
 * Created on 10 de junio de 2018, 20:06
 */

#include "Menu.h"
#include <SFML/Graphics/Text.hpp>

Menu::Menu() {
}
void Menu::ConfigurarTexto(sf::Font &fuente,sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos){
    fuente.loadFromFile("font/Cave-Story.ttf");
    
    titulo.setFont(fuente);
    opcionUno.setFont(fuente);
    opcionDos.setFont(fuente);
}

