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
  formaNave.setPointCount( 3 ); //Será un triangulo
  formaNave.setPoint( 0, sf::Vector2f( 10.0f, 0.0f ) );
  formaNave.setPoint( 1, sf::Vector2f(-10.0f, 7.5f ) );
  formaNave.setPoint( 2, sf::Vector2f(-10.0f,-7.5f ) );
     
  formaNave.setFillColor( sf::Color( 0,0,0,0 ) );
  formaNave.setOutlineColor(sf::Color::White);
  formaNave.setOutlineThickness(2);
  formaNave.setPosition( 0.0f, 0.0f );
    
  if(anchoResolucion>600||altoResolucion>1439){
      formaNave.setScale(1,1);
  
  }else{formaNave.setScale(0.7,0.7);}
  reset();
 }
 
 Ship::~Ship()
 {
 }
 sf::ConvexShape Ship::getForma(){
     return this->formaNave;
 }
 //Inicializa la nave a sus valores iniciales
 void Ship::reset()
 {
  setPosition( anchoResolucion/2, altoResolucion/2); //Lo colocamos en el centro de la pantalla
  setRotation( 270.0f );   //lo ponemos con giro cero
  velocidadNave.x = 0.0f;  //Lo paramos para que no se mueva
  velocidadNave.y = 0.0f;
 }
 
 //Función que actualizara la lógica de la nave
 void Ship::update( float delta_time_seconds )
 {
  //Comprobación del teclado
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::A  ) )    //Si pulsamos cursor izquierda
      move(velocidadNave.x = -2.0f,velocidadNave.y = 0.0f);
      
 
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::D  ) )   //Si pulsamos cursor derecha
      move(velocidadNave.x = 2.0f,velocidadNave.y = 0.0f);
 
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )    //Si pulsamos cursor arriba
     move(velocidadNave.x = 0.0f,velocidadNave.y = -2.0f);
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::S) )    //Si pulsamos cursor  abajo
     move(velocidadNave.x = 0.0f,velocidadNave.y = 2.0f);
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //con Z gira en sentido antihorario
      rotate( -1.0f * velocidadRotacion * delta_time_seconds );
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //con X gira en sentido horario     
      rotate( velocidadRotacion * delta_time_seconds );
    
  //{
   //Cogemos la dirección en la que mira la nave
   float rotation = getRotation();
 
   //Cogemos cual es su direccion en coordenadas cartesianas
   //NOTA - SFML trabaja en grados[0...360] y las ecuaciones matemáticas estándar trabajan en radianes[0...2*Pi]
   float cosRotation = std::cos( rotation * degree2radian );
  float sinRotation = std::sin( rotation * degree2radian );
 
   //Damos un acelerón a la nave
   velocidadNave.x += aceleracion * delta_time_seconds * cosRotation;
   velocidadNave.y += aceleracion * delta_time_seconds * sinRotation;
//  }
 
  //Comprobamos si la nave se mueve
  //La velocidad es la longitud del vector velocidad
  float ship_speed = std::sqrt( (velocidadNave.x * velocidadNave.x) + (velocidadNave.y * velocidadNave.y) );
  if( ship_speed > 0 ) //Si la nave se esta moviendo
  {
   //Vemos cual es la direccion del movimiento
   float angle_of_velocity = std::atan2( velocidadNave.y/ship_speed , velocidadNave.x/ship_speed );
 
   //Aplico la resistencia en la direccion del movimiento
      velocidadNave.x -= resistencia * delta_time_seconds * std::cos( angle_of_velocity );
       velocidadNave.y -= resistencia * delta_time_seconds * std::sin( angle_of_velocity );
 
   //Compruebo la nueva velocidad
   ship_speed = std::sqrt( (velocidadNave.x * velocidadNave.x) + (velocidadNave.y * velocidadNave.y) );
 
   //Si es menos que cero, paro la nave para que no retroceda
   if( ship_speed < 0.0f ) velocidadNave = sf::Vector2f( 0.0f, 0.0f );
    
   //Actualizo la posición de la nave
  // move( m_ship_velocity * delta_time_seconds );
 
   //Comprueba la posición
   sf::Vector2f position = getPosition();
 
   //Si se sale por los laterales izquierdo o derecho
   //los muevo hasta el lado contrario
   if( position.x <= -15.0f ) position.x = anchoResolucion - 15.0f;
   else if( position.x >= anchoResolucion-10.0f ) position.x = - 15.0f;
 
   //Si se sale por los laterales superior o inferior
   //Pongo limite
   if( position.y <= 10.0f ) position.y = 00.0f + 10.0f;
   else if( position.y >= altoResolucion ) position.y = altoResolucion;
 

 
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
 target.draw( formaNave, states );
 
  //NOTA - Una transformación contiene la información de posición, rotación y escalado...
 }
 
};
