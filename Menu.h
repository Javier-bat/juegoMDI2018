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
using namespace std;

class Menu {
public:
    Menu();
    void ConfigurarTexto(sf::Font &fuente,sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,string mensajeTitulo,string mensajeUno,string mensajeDos);
    void ConfigurarTamanoTexto(sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,int tamanoTitulo,int tamanoUno,int tamanoDos);
    void ConfigurarPosicionTexto(sf::Text &titulo,sf::Text &opcionUno,sf::Text &opcionDos,int offset);
private:

};

#endif /* MENU_H */

