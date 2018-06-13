/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Configuracion.cpp
 * Author: gabrielascurra
 * 
 * Created on 12 de junio de 2018, 21:01
 */

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Window.hpp>
#include <SFML/Window/Event.hpp>
#include "ConstantesGlobales.h"
#include "Configuracion.h"
#include "iostream"

Configuracion::Configuracion() {

}

int Configuracion::run(sf::RenderWindow& window, sf::Sprite& fondo, sf::Font &fuente) {
    std::vector<sf::Text> textoss;
    std::vector<std::string> mensajes;
    textoss=CrearArrayTexto(15);
    //Creacion de strings para los texts
    mensajes.push_back("Esquema de controles (ESC para volver)");
    mensajes.push_back("Arriba");
    mensajes.push_back("Abajo");
    mensajes.push_back("Derecha");
    mensajes.push_back("Izquierda");
    mensajes.push_back("Giro a la izquierda");
    mensajes.push_back("Giro a la derecha");
    mensajes.push_back("Disparar");
    mensajes.push_back("W");
    mensajes.push_back("S");
    mensajes.push_back("D");
    mensajes.push_back("A");
    mensajes.push_back("Flecha izquierda");
    mensajes.push_back("Flecha derecha");
    mensajes.push_back("Espacio");

    ConfigurarTexto(fuente, textoss, mensajes);
    ConfigurarPosicion(textoss);

    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }

        window.clear();
        window.draw(fondo);
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            running = false;
        }
        Dibujar(textoss, window);
        window.display();
    }
    return -1;
}

void Configuracion::ConfigurarTexto(sf::Font& font, std::vector<sf::Text>& texto, std::vector<std::string> mensajes) {
    for (int i = 0; i < texto.size(); i++) {
        texto[i].setFont(font);
        texto[i].setString(mensajes[i]);
    }
    texto[0].setCharacterSize(46);
    texto[0].setFillColor(sf::Color::Yellow);
}

void Configuracion::Dibujar(std::vector<sf::Text> texto, sf::RenderWindow& window) {
    for (int i = 0; i < texto.size(); i++) {
        window.draw(texto[i]);
    }
}

void Configuracion::ConfigurarPosicion(std::vector<sf::Text>& text) {
    int offsetX = 30;
    int offsetY = 60;
    sf::FloatRect textRec = text[0].getGlobalBounds();

    text[0].setOrigin((textRec.left + textRec.width / 2.0f) - 50, textRec.top + textRec.height / 2.0f);
    text[0].setPosition((anchoResolucion / 2) -30, altoResolucion / 2 -40);


    for (int i = 1; i < text.size(); i++) {
        text[i].setOrigin((textRec.left + textRec.width / 2.0f) , textRec.top + textRec.height / 2.0f);
        if (i == 8) {
            offsetX = 30;
            offsetY = -240;
        }

        text[i].setPosition((anchoResolucion / 2) + offsetY, (altoResolucion / 2) + offsetX);
        offsetX += 30;

    }

}
std::vector<sf::Text> Configuracion::CrearArrayTexto(int tamano){
    std::vector<sf::Text> vector;
    for(int i=0;i<tamano;i++){
        sf::Text texto;
        vector.push_back(texto);
    }
    return vector;
}
