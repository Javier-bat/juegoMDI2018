/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   asteroide.cpp
 * Author: root
 * 
 * Created on 30 de mayo de 2018, 05:14
 */

#include "Asteroide.h"
#include <ctime>
#include "config.hpp"


Ball::Ball()
    : sf::Sprite()
{
	// Establecemos la textura de la bola
	texture_ball.loadFromFile("Imagenes/asteroideGrande.png");
	this->setTexture(texture_ball);

	// Establecemos su sonido
	//this->buffer.loadFromFile("data/hitball.wav");
	//this->sound.setBuffer(buffer);

	// Establecemos el origen de la bola en su centro
//	this->setOrigin(1.6f,100.0f);
	// Establecemos la posición de la bola en el centro de la ventana
        srand((unsigned)time(0));
        int number = ((rand() % 1900));
        this->setPosition(number,-100.0f);

	// Definimos la velocidad
	this->speed.x = 0.0f;
	this->speed.y = 500.0f;
}
void Ball::reset(){
 srand((unsigned)time(0));
    int number = ((rand() % 1900));
        this->setPosition(number,-100.0f);

	// Definimos la velocidad
	this->speed.x = 0.0f;
	this->speed.y = 500.0f;
}
void Ball::update2( float delta_time_seconds )
{
	// Obtenemos los cuatro laterales de la bola
	float left = this->getPosition().x - this->getOrigin().x;
	float right = this->getPosition().x + this->getOrigin().x;
	float top = this->getPosition().y - this->getOrigin().y;
	float bottom = this->getPosition().y + this->getOrigin().y;

	// Comprobamos si choca contra las paredes
	bool tocoSuelo =false;
	if (bottom >= HEIGHT && speed.y > 0)
	{
            tocoSuelo=true;
	}
	// Movemos la bola multiplicando la velocidad por el tiempo pasado
	this->move(delta_time_seconds * this->speed.x, delta_time_seconds* this->speed.y);
}

float Ball::getSpeedX() const
{
	return speed.x;
}
