/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Menu.h
 * Author: gabrielascurra
 *
 * Created on 10 de junio de 2018, 20:06
 */

#ifndef MENU_H
#define MENU_H

#include <SFML/Graphics/Text.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Graphics/Sprite.hpp>
using namespace std;

class Menu {
public:
    Menu();
    Menu(const Menu& orig);
    virtual ~Menu();
    void ConfigurarTexto(sf::Font &fuente,sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,sf::Text &opcionTres,string mensajeTitulo,string mensajeUno,string mensajeDos,string mensajeTres);
    void ConfigurarTamanoTexto(sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,sf::Text &opcionTres,int tamanoTitulo,int tamanoUno,int tamanoDos);
    void ConfigurarPosicionTexto(sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,sf::Text &opcionTres,int offset);
    void SeleccionarOpcion(sf::RenderWindow &window,sf::Sprite &fondo,int &itemSeleccionado,sf::Text &opcionUno,sf::Text &opcionDos,sf::Text &opcionTres,bool &running,sf::RenderWindow &App,sf::Sound &cambiarSeleccion);
    virtual void OpcionUno(sf::RenderWindow &App,bool &running){cout<<"Opcion uno"<<endl;}
    void OpcionDos(sf::RenderWindow &window,sf::Sprite &fondo,bool &opcion);
    virtual void OpcionTres(){};
private:
    sf::Clock reloj;
    sf::Time tiempo;
    sf::Font font;
protected:
    bool opcion = false;
};

#endif /* MENU_H */

