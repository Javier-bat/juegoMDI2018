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
    std::vector<Asteroide> asteroides;
    sf::Texture texturaAsteroide;
    
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
    if (!texturaAsteroide.loadFromFile("Imagenes/asteroideGrande.png")) {
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
        if( asteroides.size() <= 10){
            Asteroide asteroide=Asteroide(texturaAsteroide);
            asteroides.push_back(asteroide);
        }
        for(int i=0;i< asteroides.size();i++){
            
        }
        
        App.clear();
        App.draw(sprite);
        for(int i=0;i < asteroides.size();i++){
            asteroides[i].verificarExistencia(i,asteroides);
            asteroides[i].Mostrar(App);
            asteroides[i].ActualizarPosicion();
        }
        App.draw(titulo);
        App.draw(tituloSinglePlayer);
        App.draw(tituloSalir);
        App.display();
        
        //Este bloque de codigo hace que el menu sea navegable con las flechas
        switch (itemSeleccionado) {
            case 0:
                tituloSinglePlayer.setColor(sf::Color::Red);
                tituloSalir.setColor(sf::Color::White);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    itemSeleccionado = 1;
                break;
            case 1:
                tituloSinglePlayer.setColor(sf::Color::White);
                tituloSalir.setColor(sf::Color::Red);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    itemSeleccionado = 0;
                break;
        }
        
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
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

