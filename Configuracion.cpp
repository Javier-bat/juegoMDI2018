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

int Configuracion::run(sf::RenderWindow& window, sf::Sprite& fondo, sf::Font &fuente,bool &opcion) {
    std::vector<sf::Text> textoss;
    int posicionDefecto = 0;
    std::vector<std::string> mensajes;
    sf::Text arriba;
    sf::Text abajo;
    sf::Text derecha;
    sf::Text izquierda;
    sf::Text gIzquierda;
    sf::Text gDerecha;
    sf::Text disparar;
    sf::Text salir;
    salir.setFont(fuente);

    sf::Text arribaControl;
    sf::Text abajoControl;
    sf::Text derechaControl;
    sf::Text izquierdaControl;
    sf::Text gIzquierdaControl;
    sf::Text gDerechaControl;
    sf::Text dispararControl;

    AnadirArray(textoss, mensajes, arriba, "Arriba");
    AnadirArray(textoss, mensajes, abajo, "Abajo");
    AnadirArray(textoss, mensajes, derecha, "Derecha");
    AnadirArray(textoss, mensajes, izquierda, "Izquierda");
    AnadirArray(textoss, mensajes, gIzquierda, "Giro a la izquierda");
    AnadirArray(textoss, mensajes, gDerecha, "Giro a la derecha");
    AnadirArray(textoss, mensajes, disparar, "Disparar");
    AnadirArray(textoss, mensajes, salir, "Salir");

    AnadirArray(textoss, mensajes, arribaControl, "W");
    AnadirArray(textoss, mensajes, abajoControl, "S");
    AnadirArray(textoss, mensajes, derechaControl, "D");
    AnadirArray(textoss, mensajes, izquierdaControl, "A");
    AnadirArray(textoss, mensajes, gDerechaControl, "Flecha izquierda");
    AnadirArray(textoss, mensajes, gIzquierdaControl, "Flecha derecha");
    AnadirArray(textoss, mensajes, dispararControl, "Espacio");

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
        SeleccionarOpcion(textoss, posicionDefecto,opcion);
        Dibujar(textoss, window);
        window.display();
    }
}

void Configuracion::ConfigurarTexto(sf::Font& font, std::vector<sf::Text>& texto, std::vector<std::string> mensajes) {
    for (int i = 0; i < texto.size(); i++) {
        texto[i].setFont(font);
        texto[i].setString(mensajes[i]);
    }
}

void Configuracion::Dibujar(std::vector<sf::Text> texto, sf::RenderWindow& window) {
    for (int i = 0; i < texto.size(); i++) {
        window.draw(texto[i]);
    }
}

void Configuracion::AnadirArray(std::vector<sf::Text>& textos, std::vector<std::string>& mensajes, sf::Text texto, std::string mensaje) {
    textos.push_back(texto);
    mensajes.push_back(mensaje);
}

void Configuracion::ConfigurarPosicion(std::vector<sf::Text>& text) {
    int offsetX = 30;
    int offsetY = 60;
    sf::FloatRect textRec = text[0].getGlobalBounds();

    text[0].setOrigin((textRec.left + textRec.width / 2.0f) - 50, textRec.top + textRec.height / 2.0f);
    text[0].setPosition((anchoResolucion / 2) + offsetY, altoResolucion / 2);


    for (int i = 1; i < text.size(); i++) {
        text[i].setOrigin((textRec.left + textRec.width / 2.0f) - 50, textRec.top + textRec.height / 2.0f);
        if (i == 8) {
            offsetX = 0;
            offsetY = -140;
        }

        text[i].setPosition((anchoResolucion / 2) + offsetY, (altoResolucion / 2) + offsetX);
        offsetX += 30;

    }

}

void Configuracion::SeleccionarOpcion(std::vector<sf::Text>& text, int& item,bool &opcion){
    tiempo = reloj.getElapsedTime();
    if (tiempo.asSeconds() > 0.15) {
        for (int i = 0; i < text.size(); i++) {
            if (i == item) {
                text[i].setFillColor(sf::Color::Red);
            } else {
                text[i].setFillColor(sf::Color::White);
                //text[i+6].setFillColor(sf::Color::White);
            }
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && item<7) {
            item = item + 1;
            reloj.restart();
        }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && item>0) {
            item = item - 1;
            reloj.restart();
        }if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return) && tiempo.asSeconds() > 0.15) {
            if(item==7){
                opcion=true;
            running=false;
            }
        }if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)){
            running=false;
        }
    }
}
