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
    std::vector<Asteroide> asteroides;
    std::vector<Luna> lunas;
    sf::Clock syncronice_timer;
    game::Ship nave;
    std::vector<Bala> balas;
    sf::Texture texturaBala;
    int cantBalas = 0;
    sf::Texture texturaLuna;
    sf::Clock relojLuna;
    sf::Time timeLuna;
    float tiempoLuna=0;
    bool hayLuna;
    //Fin de declaracion de variables
    
//musica y sonidos
    musicaFondo.openFromFile("musica/ZanderNoriega-DarkerWaves.wav"); //Agregar credito a Zander Noriega pendiente
    musicaFondo.setLoop(true);
    musicaFondo.play();


 //finMusica y sonidos
    
    if(!texturaLuna.loadFromFile("Imagenes/1346946235.png")){
    
    }
    
    if (!texturaNave.loadFromFile("Imagenes/asteroideMarron.png")) {
    }
    if (!texturaNave2.loadFromFile("Imagenes/asteroideChico.png")) {
    }
     if (!texturaNave3.loadFromFile("Imagenes/asteroideLlama.png")) {
    }
    if(!texturaBala.loadFromFile("Imagenes/new_bullet.png")){
        return -1;
    }
    
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

       
        
        
    float delta_time_seconds = syncronice_timer.restart().asSeconds();


        //Actualiza el score en cada vuelta del bucle
        score.setString("Score"+ std::to_string(puntaje));
        //Esto es necesario para matar el programa cuando se cierra la ventana

        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
        if( asteroides.size() <= 10){
           
            Asteroide asteroide=Asteroide(texturaNave);
            Asteroide asteroide2=Asteroide(texturaNave);
            Asteroide asteroide3=Asteroide(texturaNave);
            Asteroide asteroide4=Asteroide(texturaNave2);
            Asteroide asteroide5=Asteroide(texturaNave3);

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
         
      if( lunas.size() < 1 && cantidadAsteroides > 20  ){
            relojLuna.restart();           
            Luna luna=Luna(texturaLuna);
            lunas.push_back(luna);
            hayLuna=true;

        }
        timeLuna =relojLuna.getElapsedTime();
        tiempoLuna=timeLuna.asSeconds();
        if(tiempoLuna>30.0 && hayLuna){
           for(int i=0;i< lunas.size();i++){
            lunas[i].setMovimientoY(2);
            hayLuna=false;
        }
        }
        
        for(int i=0;i< lunas.size();i++){
            
           lunas[i].verificarExistencia(i,lunas);
        }            
           nave.update(delta_time_seconds);
          

        puntaje++;
        //limpiamos la pantalla
        App.clear();
        //dibujamos la pantalla
        App.draw(sprite); //dibujo fondo
        App.draw(score);
        App.draw(nave);
        
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
            Bala bala(nave, texturaBala);
            balas.push_back(bala);
            balas[cantBalas].disparo(nave);
            cantBalas++;
                
        }
        
        for(int i =0; i<balas.size() ;i++){
            balas[i].mostrar(App,nave);
            if(balas[i].apretado == false){
                balas[i].~Bala();
                cantBalas--;
            }
        }
        
        for(int i=0;i < asteroides.size();i++){
            asteroides[i].Mostrar(App);
            asteroides[i].ActualizarPosicion();
        }
        for(int i=0;i < lunas.size();i++){
                lunas[i].Mostrar(App);
                lunas[i].ActualizarPosicion();
            
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

