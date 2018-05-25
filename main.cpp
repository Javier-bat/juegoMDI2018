/* 
 * File:   main.cpp
 * Author: gabrielascurra
 *
 * Created on 22 de mayo de 2018, 11:47
 */
#define SFML_STATIC
#include <cstdlib>
#include <SFML/Graphics.hpp>

using namespace std;

/*
 * 
 */
//Resolucion,aún hay que trabajar en esto
int alto=sf::VideoMode::getDesktopMode().height;
int ancho=sf::VideoMode::getDesktopMode().width;

int main(int argc, char** argv) {
    //Setea la resolucion de la pantalla
   sf::RenderWindow window(sf::VideoMode(ancho,alto), "Asteroids",sf::Style::Fullscreen);
   
   //Tipografia
   sf::Font font;
   if (!font.loadFromFile("font/Cave-Story.ttf")){
       //Aquí hay que manejar el error
   }
   sf::Text titulo;
   sf::Text tituloSinglePlayer;
   
   titulo.setFont(font);
   tituloSinglePlayer.setFont(font);
   
   titulo.setString("Asteroids");
   tituloSinglePlayer.setString("Juego individual");
   
   titulo.setCharacterSize(56);
   
   //Centrar texto en pantalla
   sf::FloatRect textRec = titulo.getLocalBounds();
   titulo.setOrigin(textRec.left + textRec.width/2.0f , textRec.top + textRec.height/2.0f);
   titulo.setPosition(sf::Vector2f(window.getSize().x/2,window.getSize().y/2));
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(titulo);
        window.draw(tituloSinglePlayer);
        window.display();
        
    }

    return 0;
}

