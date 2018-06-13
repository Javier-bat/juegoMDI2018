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
#include <SFML/Window/Keyboard.hpp>
#include <SFML/Audio/Sound.hpp>
#include "ConstantesGlobales.h"
#include "Configuracion.h"

Menu::Menu() {
}
Menu::Menu(const Menu& orig){}
Menu::~Menu(){}
void Menu::ConfigurarTexto(sf::Font &fuente,sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,sf::Text &opcionTres,string mensajeTitulo,string mensajeUno,string mensajeDos,string mensajeTres){
    fuente.loadFromFile("font/Cave-Story.ttf");
    font=fuente;
    titulo.setFont(fuente);
    opcionUno.setFont(fuente);
    opcionDos.setFont(fuente);
    opcionTres.setFont(fuente);
    
    titulo.setString(mensajeTitulo);
    opcionUno.setString(mensajeUno);
    opcionDos.setString(mensajeDos);
    opcionTres.setString(mensajeTres);
    
    titulo.setFillColor(sf::Color::Yellow);
}
void Menu::ConfigurarTamanoTexto(sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,sf::Text &opcionTres,int tamanoTitulo,int tamanoUno,int tamanoDos){
    
    titulo.setCharacterSize(tamanoTitulo);
    opcionUno.setCharacterSize(tamanoUno);
    opcionDos.setCharacterSize(tamanoDos);
    opcionTres.setCharacterSize(tamanoDos);
}
void Menu::ConfigurarPosicionTexto(sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,sf::Text &opcionTres,int offset){
    sf::FloatRect textRec=titulo.getGlobalBounds();
    titulo.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);
    opcionUno.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);
    opcionDos.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);
    opcionTres.setOrigin(textRec.left + textRec.width / 2.0f, textRec.top + textRec.height / 2.0f);

    titulo.setPosition(anchoResolucion / 2, (altoResolucion / 2) - offset);
    opcionUno.setPosition(titulo.getPosition().x , titulo.getPosition().y + 60);
    opcionDos.setPosition(titulo.getPosition().x , titulo.getPosition().y + 90);
    opcionTres.setPosition(titulo.getPosition().x , titulo.getPosition().y + 120);
}
void Menu::SeleccionarOpcion(sf::RenderWindow &window,sf::Sprite &fondo,int &itemSeleccionado,sf::Text &opcionUno,sf::Text &opcionDos, sf::Text &opcionTres,bool &running,sf::RenderWindow &App,sf::Sound &cambiarSeleccion){
   // reloj.restart();
    tiempo=reloj.getElapsedTime();
    if(tiempo.asSeconds() > 0.15){
    switch (itemSeleccionado) {
            case 0:
                opcionUno.setFillColor(sf::Color::Red);
                opcionDos.setFillColor(sf::Color::White);
                opcionTres.setFillColor(sf::Color::White);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                   cambiarSeleccion.play();
                    itemSeleccionado = 1;
                    reloj.restart();
                }
                break;
            case 1:
                opcionUno.setFillColor(sf::Color::White);
                opcionDos.setFillColor(sf::Color::Red);
                opcionTres.setFillColor(sf::Color::White);
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    cambiarSeleccion.play();
                    itemSeleccionado = 0;
                    opcion=false;
                    reloj.restart();
                }
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
                    cambiarSeleccion.play();
                    itemSeleccionado = 2;
                    opcion=false;
                    reloj.restart();
                }
                break;
        case 2:
            opcionUno.setFillColor(sf::Color::White);
            opcionDos.setFillColor(sf::Color::White);
            opcionTres.setFillColor(sf::Color::Red);
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
                    cambiarSeleccion.play();
                    itemSeleccionado = 1;
                    reloj.restart();
                }
        }
}
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) {
            if (itemSeleccionado == 0) {
                OpcionUno(App,running);
                
            }
            if (itemSeleccionado == 1 && !opcion) {
                reloj.restart();
                OpcionDos(window,fondo,opcion);
                
            }
            if(itemSeleccionado == 2){
                OpcionTres();
            }
        
        }
}
void Menu::OpcionDos(sf::RenderWindow &window,sf::Sprite &fondo,bool &opcion){
    Configuracion conf;
    conf.run(window,fondo,font,opcion);
}



