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


      //Este método es mucho mejor que el #pragma one
      //sobre todo hay que evitar usar #pragma pues no son estándar
 
#include <SFML/Graphics.hpp> //Inclusión de las clases de SFML2 graficas
 
const float degree2radian = (3.14159f / 180.0f);
 
const float m_ship_drag_force = 3.0f; //Velocidad de resistencia contra el movimiento de la nave (Esto ara que se pare poco a poco cuando se deje de acelerar )
const float m_ship_aceleration = 10.0f; //Aceleración en pixel/segundo2 de la nave cuando se aplica empuje
const float m_ship_rotation_velocity = 240.0f; //Velocidad de rotación de la nave en grados/segundo
 
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
 
 protected:
  sf::Vector2f m_ship_velocity; //Velocidad de la nave
 
  sf::ConvexShape m_shipShape; //Representación gráfica de la nave
 
  
 
 };
};
 


#endif /* SHIP_H */

