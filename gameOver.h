/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   
 * Author: r
 *
 * Created on 27 de mayo de 2018, 11:55
 */

#ifndef GAMEOVER_H
#define GAMEOVER_H
#include "Menu.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class gameOver : public Menu {
public:

     gameOver(int score);
    int Run(sf::RenderWindow &App);
    sf::Music musicaFondo;
    void OpcionUno(sf::RenderWindow &App, bool &running);
    void OpcionTres();
private:
    int score;
};




#endif /* MENUPRINCIPAL_H */
