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
void Menu::ConfigurarTexto(sf::Font &fuente,sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,string mensajeTitulo,string mensajeUno,string mensajeDos){
    fuente.loadFromFile("font/Cave-Story.ttf");
    
    titulo.setFont(fuente);
    opcionUno.setFont(fuente);
    opcionDos.setFont(fuente);
    
    titulo.setString(mensajeTitulo);
    opcionUno.setString(mensajeUno);
    opcionDos.setString(mensajeDos);
    
    titulo.setFillColor(sf::Color::Yellow);
}
void Menu::ConfigurarTamanoTexto(sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,int tamanoTitulo,int tamanoUno,int tamanoDos){
    
    titulo.setCharacterSize(tamanoTitulo);
    opcionUno.setCharacterSize(tamanoUno);
    opcionDos.setCharacterSize(tamanoDos);
}

