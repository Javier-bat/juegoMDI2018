/* 
 * File:   PantallaJuego.cpp
 * Author: gabrielascurra
 * 
 * Created on 27 de mayo de 2018, 12:27
 */

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "PantallaJuego.h"
#include "Ship.h"
#include "Asteroide.h"
#include "ConstantesGlobales.h"
#include "MenuPausa.h"
#include "Bala.h"
#include "Luna.h"
#include <list>
#include <iostream>
#include "Animacion.h"

PantallaJuego::PantallaJuego() {
}

int PantallaJuego::Run(sf::RenderWindow &App) {
    //Variables
    bool running=true;
    bool pausa=false;
    int puntaje=0;
    sf::Font font;
    sf::Text score;
    sf::Texture texturaNave;
    sf::Texture texturaNave2;
    sf::Texture texturaNave3;
    int cantidadAsteroides=0;
    sf::Sprite sprite;//creo un sprite
    std::vector <Asteroide> asteroides;
    std::vector <Luna> lunas;
    sf::Clock syncronice_timer;
    game::Ship nave;
    std::vector <Bala> balas;
    sf::Texture texturaBala;
    int cantBalas = 0;
    sf::Texture texturaLuna;
    
    sf::Clock relojLuna;
    sf::Time timeLuna;
    float tiempoLuna=0;
    sf::Clock relojJuego;
    sf::Time timeJuego;
    sf::Clock relojDisparo;
    sf::Time timeDisparo;
    int velocidadAsteroide = 0;
    sf::Texture explosion;
    sf::Vector2f posicion;
    //Fin de declaracion de variables
    
//musica y sonidos
    musicaFondo.openFromFile("musica/ZanderNoriega-DarkerWaves.wav"); //Agregar credito a Zander Noriega pendiente
    musicaFondo.setLoop(true);
    musicaFondo.play();


 //finMusica y sonidos
    
    if(!texturaLuna.loadFromFile("Imagenes/1346946235.png")){
    
    }

    
    if (!texturaNave.loadFromFile("Imagenes/asteroideGrande.png")) {
    }
    if (!texturaNave2.loadFromFile("Imagenes/asteroideChico.png")) {
    }
     if (!texturaNave3.loadFromFile("Imagenes/asteroideMediano.png")) {
    }
    if(!texturaBala.loadFromFile("Imagenes/new_bullet.png")){
           std::cout<<"no se pudo cargar"<<std::endl;
    }
    
    if(!explosion.loadFromFile("Imagenes/explosion.png")){
        std::cout<<"no se pudo cargar"<<std::endl;
    }
    
    Animacion explosionUno(explosion,1,1,256,256,48,0.3f);

    
    fondo.loadFromFile("Imagenes/back.png"); //cargo la imagen de la carpeta
    
    sprite.setTexture(fondo); //le seteo la textura
     //seteo el tamaño del fondo
    sprite.setOrigin(anchoResolucion/15,altoResolucion/5);
    
    //Carga la tipografía
    if (!font.loadFromFile("font/Cave-Story.ttf")) {
        //Aquí hay que manejar el error
    }
    //Setea la tipografia
    score.setFont(font);
    //Para evitar un uso innecesario del procesador,limita los fps a 60
    App.setFramerateLimit(60);
    //Para evitar efecto shuttering
    App.setVerticalSyncEnabled(true);
    //Desactiva el mouse,ya que no es necesario para jugar
    App.setMouseCursorVisible(false);
    score.setCharacterSize(32);


    
   
    
    while (running) {

    timeJuego = relojJuego.getElapsedTime();
    if((int)timeJuego.asSeconds() > 45 ){
        velocidadAsteroide += 1;
        relojJuego.restart();
    }
        
        
    float delta_time_seconds = syncronice_timer.restart().asSeconds();


        //Actualiza el score en cada vuelta del bucle
        score.setString("Score"+ std::to_string(puntaje)+ "\nNivel de Velocidad    :  "+std::to_string(velocidadAsteroide+1)+"\nTiempo para el siguiente nivel    :     "+std::to_string(45-(int)timeJuego.asSeconds()));        //Esto es necesario para matar el programa cuando se cierra la ventana

        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
        if( asteroides.size() <= 10){
           
            Asteroide asteroide=Asteroide(texturaNave);
            asteroide.setVelocidad(velocidadAsteroide);
            Asteroide asteroide2=Asteroide(texturaNave);
            asteroide2.setVelocidad(velocidadAsteroide);
            Asteroide asteroide3=Asteroide(texturaNave);
            asteroide3.setVelocidad(velocidadAsteroide);
            Asteroide asteroide4=Asteroide(texturaNave2);
            asteroide4.setVelocidad(velocidadAsteroide);
            Asteroide asteroide5=Asteroide(texturaNave3);
            asteroide5.setVelocidad(velocidadAsteroide);

            asteroides.push_back(asteroide);
            asteroides.push_back(asteroide2);
            asteroides.push_back(asteroide3);
            asteroides.push_back(asteroide4);
            asteroides.push_back(asteroide5);
            
            cantidadAsteroides+=5;
        }
        for(int i=0;i< asteroides.size();i++){
            asteroides[i].verificarExistencia(i,asteroides);
        }
         
      if( lunas.size() < 1 && cantidadAsteroides > 30  ){
            relojLuna.restart();           
            Luna luna= Luna(texturaLuna);
            lunas.push_back(luna);
        }
        timeLuna =relojLuna.getElapsedTime();
        tiempoLuna=timeLuna.asSeconds();
        if(tiempoLuna>20.0){
           for(int i=0;i< lunas.size();i++){
            lunas[i].setMovimientoY(2);
          
        }
        }
        
        for(int i=0;i< lunas.size();i++){
            
           lunas[i].verificarExistencia(i,lunas);
        }            
           nave.update(delta_time_seconds);

        
        //limpiamos la pantalla
        App.clear();
        //dibujamos la pantalla
        App.draw(sprite); //dibujo fondo
        App.draw(score);
        App.draw(nave);
 
        timeDisparo=relojDisparo.getElapsedTime();
        if(timeDisparo.asSeconds()>0.25){
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            Bala bala(nave, texturaBala);
            balas.push_back(bala);
            relojDisparo.restart(); 
            }
        }

        for(int i =0; i<balas.size() ;i++){
            balas[i].mostrar(App);
            if(balas[i].spriteBala.getPosition().x > anchoResolucion && balas[i].spriteBala.getPosition().y > altoResolucion ){
                balas.erase(balas.begin()+i);
            }
        }
                
        for(int i=0;i < asteroides.size();i++){
            asteroides[i].Mostrar(App);
            asteroides[i].ActualizarPosicion();
        }
        
        for(int i=0;i < lunas.size();i++){
                lunas[i].Mostrar(App);
                lunas[i].ActualizarPosicion();
               // if(sf::Keyboard::isKeyPressed(sf::Keyboard::L))
              //  {lunas[i].~Luna();}
                
        }
        
        for(int i=0;i < asteroides.size();i++){
            for(int j=0;j < balas.size();j++){
                if(asteroides[i].getSprite().getGlobalBounds().intersects(balas[j].spriteBala.getGlobalBounds())){      
                    posicion = {(asteroides[i].getSprite().getPosition().x+balas[j].spriteBala.getPosition().x)/2,(asteroides[i].getSprite().getPosition().y+balas[j].spriteBala.getPosition().y)/2};
                    do{
                        explosionUno.mostrar(App,posicion);
                        explosionUno.actualizar();
                    }while(!explosionUno.termina());
                    asteroides.erase(asteroides.begin()+i);
                    balas.erase(balas.begin()+j);
                    puntaje++;
                }
            }
        }   
        
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && pausa){
            musicaFondo.pause();
            std::vector<sf::Sprite> sprites;
            sprites.push_back(sprite);
            for(int i=0;i<asteroides.size();i++){
                sprites.push_back(asteroides[i].getSprite());
            }
            MenuPausa menuPausa;
            menuPausa.run(App,sprites,running,nave);
            musicaFondo.play();
            pausa=false;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !pausa){
          
            pausa=true;
        }
        App.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
            return (-1);
        }
    }
    return -1;

}

