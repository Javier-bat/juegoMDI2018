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
#include "Nave.h"

PantallaJuego::PantallaJuego() {
}

int PantallaJuego::Run(sf::RenderWindow &App) {
    bool running=true;
    int puntaje=0;
    sf::Font font;
    sf::Text score;
    Nave naveJugador;
    
    
    //Carga la tipografía
    if (!font.loadFromFile("font/Cave-Story.ttf")) {
        //Aquí hay que manejar el error
    }
    //Setea la tipografia
    score.setFont(font);
    //Para evitar un uso innecesario del procesador,limita los fps a 60
    App.setFramerateLimit(60);
    //Desactiva el mouse,ya que no es necesario para jugar
    App.setMouseCursorVisible(false);

    score.setCharacterSize(32);

    while (running) {
        //Actualiza el score en cada vuelta del bucle
        score.setString("Score"+ std::to_string(puntaje));
        //Esto es necesario para matar el programa cuando se cierra la ventana
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
        puntaje++;
        App.clear();
        naveJugador.mostrarNave(App);
        App.draw(score);
        App.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            naveJugador.moverNave("derecha");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            naveJugador.moverNave("izquierda");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            naveJugador.moverNave("arriba");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            naveJugador.moverNave("abajo");
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
            
            return (-1);
        }
    }
    return -1;
}

