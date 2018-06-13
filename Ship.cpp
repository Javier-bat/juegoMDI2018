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
#include <iostream>
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
    
     // formaNave.setScale(1,1);
  
        float escalaX=(anchoResolucion*0.0416666)/100;
    float escalaY=(altoResolucion*0.0740740740)/100;
     formaNave.setScale(escalaX,escalaY);

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
      move(velocidadNave.x = -velocidadMovimientoX,velocidadNave.y = 0.0f);
      
 
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::D  ) )   //Si pulsamos cursor derecha
      move(velocidadNave.x = velocidadMovimientoX,velocidadNave.y = 0.0f);
 
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::W ) )    //Si pulsamos cursor arriba
     move(velocidadNave.x = 0.0f,velocidadNave.y = -velocidadMovimientoY);
  if( sf::Keyboard::isKeyPressed( sf::Keyboard::S) )    //Si pulsamos cursor  abajo
     move(velocidadNave.x = 0.0f,velocidadNave.y = velocidadMovimientoY);
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) //con Z gira en sentido antihorario
      rotate( -1.0f * velocidadRotacion * delta_time_seconds );
  
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) //con X gira en sentido horario     
      rotate( velocidadRotacion * delta_time_seconds );
    

 
  //Comprobamos si la nave se mueve
  float velocidadDeNave = std::sqrt( (velocidadNave.x * velocidadNave.x) + (velocidadNave.y * velocidadNave.y) );
  if( velocidadDeNave > 0 ) //Si la nave se esta moviendo
  {   
 
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
 
 //Definición de la función sf::Drawable
 void Ship::draw ( sf::RenderTarget &target, sf::RenderStates states ) const
 {
  //Aplicamos a la transformación que nos viene la transformación que tiene la nave
  states.transform *= getTransform();
 
  //Dibujamos la representación gráfica de la nave con la transformación calculada
 target.draw( formaNave, states );
 
 }
 
};
