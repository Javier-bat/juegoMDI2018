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

const float degree2radian = (3.14159f / 180.0f);
 
const float resistencia = 3.0f; //Velocidad de resistencia contra el movimiento de la nave (Esto ara que se pare poco a poco cuando se deje de acelerar )
const float aceleracion = 10.0f; //Aceleración en pixel/segundo2 de la nave cuando se aplica empuje
const float velocidadRotacion = 200.0f; //Velocidad de rotación de la nave en grados/segundo
 
namespace game //Un namespace para evitar cualquier colisión de nombres accidental
{
 //Clase Ship derivada de Transformable y Drawable
 //La clase transformable nos proporciona métodos para girar y mover la nave
 class Ship: public sf::Transformable, public sf::Drawable
 {
 public:
  Ship();
  ~Ship();
 
  //Inicializa la nave a sus valores iniciales
  void reset();
 
  //Función que actualizara la lógica de la nave
  void update( float delta_time_seconds );
 
  //Definición de la función virtual de sf::Drawable
  void draw ( sf::RenderTarget &target, sf::RenderStates states ) const;
  sf::Sprite spriteNave;
  sf::ConvexShape getForma();
 protected:
  sf::Vector2f velocidadNave; //Velocidad de la nave
 
  sf::ConvexShape formaNave; //Representación gráfica de la nave
 
  
 
 };
};
 


#endif /* SHIP_H */

