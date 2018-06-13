/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Configuracion.h
 * Author: gabrielascurra
 *
 * Created on 12 de junio de 2018, 21:01
 */

#ifndef CONFIGURACION_H
#define CONFIGURACION_H

#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/Sprite.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Keyboard.hpp>


class Configuracion {
public:
    Configuracion();
    int run(sf::RenderWindow &window,sf::Sprite &fondo,sf::Font &fuente);
    void ConfigurarTexto(sf::Font &font,std::vector<sf::Text> &texto,std::vector<std::string> mensajes);
    void Dibujar(std::vector<sf::Text> texto,sf::RenderWindow &window);
    void ConfigurarPosicion(std::vector<sf::Text> &text);
    std::vector<sf::Text> CrearArrayTexto(int tamano);
private:
    bool running=true;
    sf::Clock reloj;
    sf::Time tiempo;
};

#endif /* CONFIGURACION_H */

