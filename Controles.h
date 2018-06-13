/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controles.h
 * Author: gabrielascurra
 *
 * Created on 12 de junio de 2018, 23:02
 */

#ifndef CONTROLES_H
#define CONTROLES_H

#include <SFML/Window/Keyboard.hpp>
#include <vector>


class Controles {
public:
    Controles();
    //Getters
    sf::Keyboard::Key ObtenerControlArriba();
    sf::Keyboard::Key ObtenerControlAbajo();
    sf::Keyboard::Key ObtenerControlDerecha();
    sf::Keyboard::Key ObtenerControlIzquierda();
    sf::Keyboard::Key ObtenerControlGirarIzquierda();
    sf::Keyboard::Key ObtenerControlGirarDerecha();
    sf::Keyboard::Key ObtenerControlDisparar();
    //Setter
    void SetearControlArriba(sf::Keyboard::Key tecla);
    void SetearControlAbajo(sf::Keyboard::Key tecla);
    void SetearControlDerecha(sf::Keyboard::Key tecla);
    void SetearControlIzquierda(sf::Keyboard::Key tecla);
    void SetearControlGirarIzquierda(sf::Keyboard::Key tecla);
    void SetearControlGirarDerecha(sf::Keyboard::Key tecla);
    void SetearControlDisparar(sf::Keyboard::Key tecla);
    //Persistir controles
    void PersistirControles(std::vector<sf::Keyboard::Key> controles);
private:
    sf::Keyboard::Key controlArriba;
    sf::Keyboard::Key controlAbajo;
    sf::Keyboard::Key controlDerecha;
    sf::Keyboard::Key controlIzquierda;
    sf::Keyboard::Key controlGirarIzquiera;
    sf::Keyboard::Key controlGirarDerecha;
    sf::Keyboard::Key controlDisparar;
};

#endif /* CONTROLES_H */

