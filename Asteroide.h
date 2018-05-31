/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   asteroide.h
 * Author: root
 *
 * Created on 30 de mayo de 2018, 05:14
 */

#ifndef ASTEROIDE_H
#define ASTEROIDE_H



#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Ball : public sf::Sprite
{
public:
    Ball();

	void update(sf::Time& delta);
        void update2( float delta_time_seconds );
        void reset();
	float getSpeedX() const;

private:
	sf::Texture texture_ball;
	sf::Vector2f speed;
	sf::SoundBuffer buffer;
	sf::Sound sound;
}; // class Ball



#endif /* ASTEROIDE_H */

