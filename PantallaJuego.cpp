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
#include <SFML/Graphics.hpp>
#include "PantallaJuego.h"
#include "Ship.h"
#include "Asteroide.h"

#include <list>

PantallaJuego::PantallaJuego() {
}

int PantallaJuego::Run(sf::RenderWindow &App) {
    bool running=true;

    //Tipografia
    sf::Font font;
    if (!font.loadFromFile("font/Cave-Story.ttf")) {
        //Aquí hay que manejar el error
    }
    sf::Text titulo;

    titulo.setFont(font);

    titulo.setString("Asteroids");

    titulo.setCharacterSize(56);
    

    
   sf::Clock syncronice_timer;
    game::Ship nave;
    
    while (running) {
       
        
        
    float delta_time_seconds = syncronice_timer.restart().asSeconds();

        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
         
            
           nave.update(delta_time_seconds);
           ball.update2(delta_time_seconds);
           
        App.clear();
        App.draw(ball);
      
        App.draw(titulo);
         
       App.draw(nave);
        
       
       
        App.display();
        
       
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
            
            return (-1);
        }
    }
    return -1;
}

