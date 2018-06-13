/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   MenuPrincipal.h
 * Author: gabrielascurra
 *
 * Created on 27 de mayo de 2018, 11:55
 */

#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class MenuPrincipal : public Menu {
public:
    MenuPrincipal(void);
    int Run(sf::RenderWindow &App);
    sf::Music musicaFondo;
    void OpcionUno(sf::RenderWindow &App, bool &running);
    void OpcionTres();
private:
    
};




#endif /* MENUPRINCIPAL_H */

