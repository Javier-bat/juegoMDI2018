/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PantallaJuego.cpp
 * Author: gabrielascurra
 * 
 * Created on 27 de mayo de 2018, 12:27
 */

#include <SFML/Graphics/RenderWindow.hpp>

#include "PantallaJuego.h"

PantallaJuego::PantallaJuego() {
}

int PantallaJuego::Run(sf::RenderWindow &App) {
    bool running=true;

    //Tipografia
    sf::Font font;
    if (!font.loadFromFile("font/Cave-Story.ttf")) {
        //Aquí hay que manejar el error
    }
    sf::Text titulo;

    titulo.setFont(font);

    titulo.setString("Asteroids");

    titulo.setCharacterSize(56);

    while (running) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
        
        App.clear();
        App.draw(titulo);
        App.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
            
            return (-1);
        }
    }
    return -1;
}

