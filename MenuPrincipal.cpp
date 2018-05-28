/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuPrincipal.cpp
 * Author: gabrielascurra
 * 
 * Created on 27 de mayo de 2018, 11:55
 */

#include <unordered_map>
#include <iostream>

#include "MenuPrincipal.h"
#include "Pantalla.h"
#include "PantallaJuego.h"
using namespace std;

MenuPrincipal::MenuPrincipal(){}
int MenuPrincipal::Run(sf::RenderWindow &App) {
    bool running = true;

    //Tipografia
    sf::Font font;
    if (!font.loadFromFile("font/Cave-Story.ttf")) {
        //Aquí hay que manejar el error
    }
    sf::Text titulo;
    sf::Text tituloSinglePlayer;
    sf::Text tituloSalir;

    titulo.setFont(font);
    tituloSinglePlayer.setFont(font);
    tituloSalir.setFont(font);

    titulo.setString("Asteroids");
    tituloSinglePlayer.setString("1-Juego individual");
    tituloSalir.setString("0-Salir");

    titulo.setCharacterSize(56);

    //Centrar texto en pantalla
    sf::FloatRect textRec = titulo.getGlobalBounds();
    titulo.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);
    tituloSinglePlayer.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);
    tituloSalir.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);

    titulo.setPosition(sf::Vector2f(App.getSize().x / 2, App.getSize().y / 2));
    tituloSinglePlayer.setPosition(sf::Vector2f(App.getSize().x / 2, (App.getSize().y / 2) + 60));
    tituloSalir.setPosition(sf::Vector2f(App.getSize().x / 2, (App.getSize().y / 2) + 90));

    while (running) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
            return (-1);
        }
        
        App.clear();
        App.draw(titulo);
        App.draw(tituloSinglePlayer);
        App.draw(tituloSalir);
        App.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1)) {
            running=false;
            PantallaJuego p1;
            p1.Run(App);
        }
    }
    return -1;
}

