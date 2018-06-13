/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ship.h
 * Author: root
 *
 * Created on 30 de mayo de 2018, 02:45
 */

#ifndef SHIP_H
#define SHIP_H


#include <SFML/Graphics.hpp>

#include "ConstantesGlobales.h" 

const float velocidadRotacion = 200.0f; //Velocidad de rotación de la nave en grados/segundo

namespace game //Un namespace para evitar cualquier colisión de nombres accidental
{

 class Ship: public sf::Transformable, public sf::Drawable
 {
 public:
  Ship();
  ~Ship();
 
  //Inicializa la nave a sus valores iniciales
  void reset();
 
  //Función que actualiza la nave
  void update( float delta_time_seconds );
 
  //draw 
  void draw ( sf::RenderTarget &target, sf::RenderStates states ) const;
  
  sf::ConvexShape getForma();
 protected:
  sf::Vector2f velocidadNave; //Velocidad de la nave
 
  sf::ConvexShape formaNave; //Representación gráfica de la nave
 const float velocidadMovimientoX = (anchoResolucion*0.104166)/100;
const float velocidadMovimientoY = (altoResolucion*0.1851851)/100;
  
 
 };
};
 


#endif /* SHIP_H */

