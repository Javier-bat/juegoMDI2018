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
#include "PantallaJuego.h"
#include "ConstantesGlobales.h"
#include "Menu.h"
using namespace std;

MenuPrincipal::MenuPrincipal() {
}

int MenuPrincipal::Run(sf::RenderWindow &App) {
    bool running = true;
    int itemSeleccionado = 0;
    vector<Asteroide> asteroides;
    sf::Texture fondo;
    sf::Sprite sprite;
    sf::Texture texturaAsteroide;
    sf::Text titulo;
    sf::Text tituloSinglePlayer;
    sf::Text tituloSalir;
    sf::Font font;


    App.setFramerateLimit(60);
    App.setMouseCursorVisible(false);
    fondo.loadFromFile("Imagenes/back.png"); //cargo la imagen de la carpeta
    sprite.setTexture(fondo); //le seteo la textura
    //seteo el tamaño del fondo
    sprite.setOrigin(anchoResolucion / 15, altoResolucion / 5);

    //musica y sonnidos
    musicaFondo.openFromFile("musica/wyver9_ArcadeTitle.wav"); //Agregar credito a wyver9 pendiente
    musicaFondo.setLoop(true);
    musicaFondo.play();
    musicaFondo.setVolume(50);

    // Creamos un SoundBuffer
    sf::SoundBuffer buffer;
    sf::SoundBuffer buffer2;
    //Cargamos un archivo en el buffer
    if (!buffer.loadFromFile("musica/selectNoise.wav")) {
        return EXIT_FAILURE;
    }
    if (!buffer2.loadFromFile("musica/Menu Selection Click.wav")) {
        return EXIT_FAILURE;
    }


    //Creamos un sonido
    sf::Sound cambiarSeleccion;
    sf::Sound seleccionar;
    // Le asignamos el buffer
    cambiarSeleccion.setBuffer(buffer2);
    seleccionar.setBuffer(buffer);
    // establecemos el volumen
    cambiarSeleccion.setVolume(100);
    seleccionar.setVolume(100);

    //finMusica y sonidos

    if (!texturaAsteroide.loadFromFile("Imagenes/asteroideGrande.png")) {
    }

    ConfigurarTexto(font, titulo, tituloSinglePlayer, tituloSalir, "Asteroids", "Juego individual", "Salir");
    ConfigurarTamanoTexto(titulo, tituloSinglePlayer, tituloSalir, 56, 36, 36);
    ConfigurarPosicionTexto(titulo, tituloSinglePlayer, tituloSalir, 0);

    while (running) {
        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
        if (asteroides.size() <= 10) {
            Asteroide asteroide = Asteroide(texturaAsteroide,0);
            asteroides.push_back(asteroide);
        }
        for (int i = 0; i < asteroides.size(); i++) {

        }

        App.clear();

        App.draw(sprite);
        for (int i = 0; i < asteroides.size(); i++) {
            asteroides[i].verificarExistencia(i, asteroides);
            asteroides[i].Mostrar(App);
            asteroides[i].ActualizarPosicion();
        }
        App.draw(titulo);
        App.draw(tituloSinglePlayer);
        App.draw(tituloSalir);
        App.display();

        //Este bloque de codigo hace que el menu sea navegable con las flechas
        SeleccionarOpcion(itemSeleccionado, tituloSinglePlayer, tituloSalir, running, App,cambiarSeleccion);

    }
    return -1;
}

void MenuPrincipal::OpcionUno(sf::RenderWindow &App,bool &running) {
    running=false;
    musicaFondo.stop();
    PantallaJuego p1;
    p1.Run(App);
}
void MenuPrincipal::OpcionDos(){
    std::exit(-1);
}


