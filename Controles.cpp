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

#include "Controles.h"

Controles::Controles() {
}
sf::Keyboard::Key Controles::ObtenerControlArriba(){
    controlArriba=sf::Keyboard::Num0;
    return controlArriba;
}

