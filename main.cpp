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
int ancho=1024;
int alto=720;

int main(int argc, char** argv) {

   sf::RenderWindow window(sf::VideoMode(ancho, alto), "Asteroids",sf::Style::Fullscreen);
   

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.display();
    }

    return 0;
}

