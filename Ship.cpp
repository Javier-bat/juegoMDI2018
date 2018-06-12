/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   ship.cpp
 * Author: root
 * 
 * Created on 30 de mayo de 2018, 02:45
 */

#include "Ship.h" //Inclusión de las definición de la clase nave
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include<SFML/Config.hpp>
#include <complex>
#include <math.h>
#include "ConstantesGlobales.h"

namespace game
{
 Ship::Ship()
 {
//  Define la figura que representara la nave
  m_shipShape.setPointCount( 3 ); //Será un triangulo
  m_shipShape.setPoint( 0, sf::Vector2f( 10.0f, 0.0f ) );
  m_shipShape.setPoint( 1, sf::Vector2f(-10.0f, 7.5f ) );
  m_shipShape.setPoint( 2, sf::Vector2f(-10.0f,-7.5f ) );
     
  m_shipShape.setFillColor( sf::Color( 0,0,0,0 ) );
  m_shipShape.setOutlineColor(sf::Color::White);
  m_shipShape.setOutlineThickness(2);
  m_shipShape.setPosition( 0.0f, 0.0f );
     

  reset();
 }
 
 Ship::~Ship()
 {
 }
 
 //Inicializa la nave a sus valores iniciales
 void Ship::reset()
 {
  setPosition( anchoResolucion/2, altoResolucion/2); //Lo colocamos en el centro de la pantalla
  setRotation( 270.0f );   //lo ponemos con giro cero
  m_ship_velocity.x = 0.0f;  //Lo paramos para que no se mueva
  m_ship_velocity.y = 0.0f;
 }
 
 //Función que actualizara la lógica de la nave
 void Ship::update( float delta_time_seconds )
 {
  //Comprobación del teclado
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Left  ) )    //Si pulsamos cursor izquierda
      move(m_ship_velocity.x = -2.0f,m_ship_velocity.y = 0.0f);
      
 
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Right  ) )   //Si pulsamos cursor derecha
      move(m_ship_velocity.x = 2.0f,m_ship_velocity.y = 0.0f);
 
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) )    //Si pulsamos cursor arriba
     move(m_ship_velocity.x = 0.0f,m_ship_velocity.y = -2.0f);
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::Down) )    //Si pulsamos cursor  abajo
     move(m_ship_velocity.x = 0.0f,m_ship_velocity.y = 2.0f);
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) //con Z gira en sentido antihorario
      rotate( -1.0f * m_ship_rotation_velocity * delta_time_seconds );
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::X)) //con X gira en sentido horario     
      rotate( m_ship_rotation_velocity * delta_time_seconds );
    
  //{
   //Cogemos la dirección en la que mira la nave
   float rotation = getRotation();
 
   //Cogemos cual es su direccion en coordenadas cartesianas
   //NOTA - SFML trabaja en grados[0...360] y las ecuaciones matemáticas estándar trabajan en radianes[0...2*Pi]
   float cosRotation = std::cos( rotation * degree2radian );
  float sinRotation = std::sin( rotation * degree2radian );
 
   //Damos un acelerón a la nave
   m_ship_velocity.x += m_ship_aceleration * delta_time_seconds * cosRotation;
   m_ship_velocity.y += m_ship_aceleration * delta_time_seconds * sinRotation;
//  }
 
  //Comprobamos si la nave se mueve
  //La velocidad es la longitud del vector velocidad
  float ship_speed = std::sqrt( (m_ship_velocity.x * m_ship_velocity.x) + (m_ship_velocity.y * m_ship_velocity.y) );
  if( ship_speed > 0 ) //Si la nave se esta moviendo
  {
   //Vemos cual es la direccion del movimiento
   float angle_of_velocity = std::atan2( m_ship_velocity.y/ship_speed , m_ship_velocity.x/ship_speed );
 
   //Aplico la resistencia en la direccion del movimiento
      m_ship_velocity.x -= m_ship_drag_force * delta_time_seconds * std::cos( angle_of_velocity );
       m_ship_velocity.y -= m_ship_drag_force * delta_time_seconds * std::sin( angle_of_velocity );
 
   //Compruebo la nueva velocidad
   ship_speed = std::sqrt( (m_ship_velocity.x * m_ship_velocity.x) + (m_ship_velocity.y * m_ship_velocity.y) );
 
   //Si es menos que cero, paro la nave para que no retroceda
   if( ship_speed < 0.0f ) m_ship_velocity = sf::Vector2f( 0.0f, 0.0f );
    
   //Actualizo la posición de la nave
  // move( m_ship_velocity * delta_time_seconds );
 
   //Comprueba la posición
   sf::Vector2f position = getPosition();
 
   //Si se sale por los laterales izquierdo o derecho
   //los muevo hasta el lado contrario
   if( position.x <= -10.0f ) position.x = 1900.0f + 10.0f;
   else if( position.x >= 2000.0f ) position.x = - 10.0f;
 
   //Si se sale por los laterales superior o inferior
   //Pongo limite
   if( position.y <= 10.0f ) position.y = 00.0f + 10.0f;
   else if( position.y >= 1020.0f ) position.y = 1020.0f;
 

 
   //Ponemos la posición que obtenemos
   setPosition( position );
  }
 }
 
 //Definición de la función virtual de sf::Drawable
 void Ship::draw ( sf::RenderTarget &target, sf::RenderStates states ) const
 {
  //Aplicamos a la transformación que nos viene la transformación que tiene la nave
  states.transform *= getTransform();
 
  //Dibujamos la representación gráfica de la nave con la transformación calculada
 target.draw( m_shipShape, states );
 
  //NOTA - Una transformación contiene la información de posición, rotación y escalado...
 }
 
};
