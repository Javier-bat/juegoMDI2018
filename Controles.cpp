/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Controles.cpp
 * Author: gabrielascurra
 * 
 * Created on 12 de junio de 2018, 23:02
 */

#include <fstream>
#include <iostream>

#include "Controles.h"

Controles::Controles() {
    std::vector<sf::Keyboard::Key> controles;
    int ordenTecla=1;

    std::ifstream input("controles.cntrl");
    if (!input.is_open()) {
        std::cout << "No se pudo abrir el fucking archivo" << std::endl;
    }
    int teclan;
    std::vector<sf::Keyboard::Key> vectorTeclas;
    while (input >> teclan) {
        sf::Keyboard::Key tecl = (sf::Keyboard::Key)teclan;
        vectorTeclas.push_back(tecl);
        switch(ordenTecla){
            case 1:
                SetearControlArriba(tecl);
                break;
            case 2:
                SetearControlAbajo(tecl);
                break;
            case 3:
                SetearControlDerecha(tecl);
                break;
            case 4:
                SetearControlIzquierda(tecl);
                break;
            case 5:
                SetearControlGirarIzquierda(tecl);
                break;
            case 6:
                SetearControlGirarDerecha(tecl);
                break;
            case 7:
                SetearControlDisparar(tecl);
                break;
        }
        std::cout << "Teclas cargadas correctamente" << std::endl;
        ordenTecla++;
    }

}

sf::Keyboard::Key Controles::ObtenerControlArriba() {
    return controlArriba;
}

void Controles::PersistirControles(std::vector<sf::Keyboard::Key> controles) {
    std::ofstream output("controles.cntrl");
    for (int i = 0; i < controles.size(); i++) {
        output << controles[i] << std::endl;
    }
    output.close();
    std::cout << "Persistencia completa" << std::endl;

}

void Controles::SetearControlArriba(sf::Keyboard::Key tecla) {
    controlArriba=tecla;
}

void Controles::SetearControlAbajo(sf::Keyboard::Key tecla) {
    controlAbajo=tecla;
}

void Controles::SetearControlDerecha(sf::Keyboard::Key tecla) {
    controlDerecha=tecla;
}

void Controles::SetearControlIzquierda(sf::Keyboard::Key tecla) {
    controlIzquierda=tecla;
}

void Controles::SetearControlGirarIzquierda(sf::Keyboard::Key tecla) {
    controlIzquierda=tecla;
}

void Controles::SetearControlGirarDerecha(sf::Keyboard::Key tecla) {
    controlGirarDerecha=tecla;
}

void Controles::SetearControlDisparar(sf::Keyboard::Key tecla) {
    controlDisparar=tecla;
}
