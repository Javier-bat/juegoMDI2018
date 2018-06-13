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
#include <SFML/Audio.hpp>
#include "ConstantesGlobales.h"

#include "MenuPausa.h"
#include "Ship.h"
#include "Menu.h"

MenuPausa::MenuPausa() {

}

int MenuPausa::run(sf::RenderWindow &window, std::vector<sf::Sprite> sprites, bool &seguirJuego) {
    sf::Font fuente;
    float origenX;
    float origenY;
    int itemSeleccionado = 0;
    sf::FloatRect textRec;
    sf::Text pausaTitulo;
    sf::Text pausaReanudar;
    sf::Text pausaConfig;
    sf::Text pausaSalir;
    
    //musica y sonidos
      	// Creamos un SoundBuffer
	sf::SoundBuffer buffer;
        sf::SoundBuffer buffer2;
	//Cargamos un archivo en el buffer
	if (!buffer.loadFromFile("musica/selectNoise.wav"))
	{
		return EXIT_FAILURE;
	}
        if (!buffer2.loadFromFile("musica/Menu Selection Click.wav"))
	{
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

    ConfigurarTexto(fuente,pausaTitulo,pausaReanudar,pausaConfig,pausaSalir,"Juego Pausado","Reanudar","Configurar","Salir");
    ConfigurarTamanoTexto(pausaTitulo,pausaReanudar,pausaConfig,pausaSalir,46,36,36);
    
    //Seteo de posiciones
    ConfigurarPosicionTexto(pausaTitulo,pausaReanudar,pausaConfig,pausaSalir,200);

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
        SeleccionarOpcion(window,sprites[0],itemSeleccionado,pausaReanudar,pausaConfig,pausaSalir,running,cambiarSeleccion);
        window.draw(pausaTitulo);
        window.draw(pausaReanudar);
        window.draw(pausaConfig);
        window.draw(pausaSalir);
        window.display();
    }
    return -1;

}
void MenuPausa::OpcionUno(sf::RenderWindow &App,bool &running){
    running=false;
}
void MenuPausa::OpcionTres(){
    std::exit(-1);
}
