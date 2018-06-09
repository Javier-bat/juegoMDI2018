/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuPausa.cpp
 * Author: gabrielascurra
 * 
 * Created on 9 de junio de 2018, 12:23
 */

#include <SFML/Window/WindowStyle.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "ConstantesGlobales.h"

#include "MenuPausa.h"
#include "Ship.h"

MenuPausa::MenuPausa() {

}

int MenuPausa::run(sf::RenderWindow &window, std::vector<sf::Sprite> sprites, bool &seguirJuego,game::Ship nave) {
    sf::Font fuente;
    float origenX;
    float origenY;
    int itemSeleccionado = 0;
    sf::FloatRect textRec;
    sf::Text pausaTitulo;
    sf::Text pausaReanudar;
    sf::Text pausaSalir;

    fuente.loadFromFile("font/Cave-Story.ttf"); //Leer fuente
    //Seteo de fuentes
    pausaTitulo.setFont(fuente);
    pausaReanudar.setFont(fuente);
    pausaSalir.setFont(fuente);
    //Seteo de mensajes
    pausaTitulo.setString("Juego Pausado");
    pausaReanudar.setString("Reanudar");
    pausaSalir.setString("Salir");
    //Seteo de posiciones
    textRec = pausaTitulo.getGlobalBounds();
    origenX = textRec.left + textRec.width / 2.0f;
    origenY = textRec.top + textRec.height / 2.0f;
    pausaTitulo.setOrigin(origenX, origenY);
    pausaReanudar.setOrigin(origenX, origenY);
    pausaSalir.setOrigin(origenX, origenY);
    pausaTitulo.setPosition(anchoResolucion / 2, (altoResolucion / 2) - 200);
    pausaReanudar.setPosition(pausaTitulo.getPosition().x, pausaTitulo.getPosition().y + 60);
    pausaSalir.setPosition(pausaTitulo.getPosition().x, pausaTitulo.getPosition().y + 90);
    //Seteo de tamaño
    pausaTitulo.setCharacterSize(46);
    pausaReanudar.setCharacterSize(36);
    pausaSalir.setCharacterSize(36);
    pausaTitulo.setColor(sf::Color::Yellow);

    while (running) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
        window.clear(sf::Color::Transparent);
        for (int i = 0; i < sprites.size(); i++) {
            window.draw(sprites[i]);
        }
        switch (itemSeleccionado) {
            case 0:
                pausaReanudar.setColor(sf::Color::Red);
                pausaSalir.setColor(sf::Color::White);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
                    itemSeleccionado = 1;
                break;
            case 1:
                pausaReanudar.setColor(sf::Color::White);
                pausaSalir.setColor(sf::Color::Red);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
                    itemSeleccionado = 0;
                break;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            switch (itemSeleccionado) {
                case 0:
                    running = false;
                    break;
                case 1:
                    seguirJuego = false;
                    return -1;
                    break;
            }
        }
        window.draw(nave);
        window.draw(pausaTitulo);
        window.draw(pausaReanudar);
        window.draw(pausaSalir);
        window.display();
    }
    return -1;

}

