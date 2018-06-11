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
#include "ConstantesGlobales.h"

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
void Menu::ConfigurarPosicionTexto(sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,int offset){
    sf::FloatRect textRec=titulo.getGlobalBounds();
    titulo.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);
    opcionUno.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);
    opcionDos.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);

    titulo.setPosition(anchoResolucion / 2, (altoResolucion / 2) - offset);
    opcionUno.setPosition(titulo.getPosition().x , titulo.getPosition().y + 60);
    opcionDos.setPosition(titulo.getPosition().x , titulo.getPosition().y + 90);
}


