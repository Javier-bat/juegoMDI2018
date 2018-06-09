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
#include "ConstantesGlobales.h"
using namespace std;

MenuPrincipal::MenuPrincipal() {
}

int MenuPrincipal::Run(sf::RenderWindow &App) {
    bool running = true;
    int itemSeleccionado = 0;
    sf::Texture fondo;
    sf::Sprite sprite;
    
    App.setFramerateLimit(60);
    App.setMouseCursorVisible(false);
    fondo.loadFromFile("Imagenes/back.png"); //cargo la imagen de la carpeta
    sprite.setTexture(fondo); //le seteo la textura
     //seteo el tamaño del fondo
    sprite.setOrigin(anchoResolucion/15,altoResolucion/5);
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
    tituloSinglePlayer.setString("Juego individual");
    tituloSalir.setString("Salir");

    titulo.setCharacterSize(56);

    //Centrar texto en pantalla
    sf::FloatRect textRec = titulo.getGlobalBounds();
    titulo.setColor(sf::Color::Yellow);
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
        App.clear();
        App.draw(sprite);
        App.draw(titulo);
        App.draw(tituloSinglePlayer);
        App.draw(tituloSalir);
        App.display();
        
                //Este bloque de codigo hace que el menu sea navegable con las flechas
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && itemSeleccionado == 0) {
            itemSeleccionado = 1;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && itemSeleccionado == 1) {
            itemSeleccionado = 0;
        }
        if (itemSeleccionado == 0) {
            tituloSinglePlayer.setColor(sf::Color::Red);
            tituloSalir.setColor(sf::Color::White);
        }
        if (itemSeleccionado == 1) {
            tituloSalir.setColor(sf::Color::Red);
            tituloSinglePlayer.setColor(sf::Color::White);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
            if (itemSeleccionado == 0) {
                running = false;
                PantallaJuego p1;
                p1.Run(App);
            }
            if (itemSeleccionado == 1) {
                return (-1);
            }
        }
        //Fin del bloque

    }
    return -1;
}

