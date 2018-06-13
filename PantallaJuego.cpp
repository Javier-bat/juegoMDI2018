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
#include <unistd.h>
#include <thread>
#include <time.h>
#include "gameOver.h"

PantallaJuego::PantallaJuego() {
    fondo.loadFromFile("Imagenes/back.png"); //cargo la imagen de la carpeta
    texturaAsteroide.loadFromFile("Imagenes/asteroideGrande.png");
    texturaAsteroide2.loadFromFile("Imagenes/asteroideChico.png");
    texturaAsteroide3.loadFromFile("Imagenes/asteroideMediano.png");
    texturaLuna.loadFromFile("Imagenes/1346946235.png");
    texturaBala.loadFromFile("Imagenes/new_bullet.png");
    explosion.loadFromFile("Imagenes/explosion.png");
    texturaNaveReal.loadFromFile("Imagenes/pixil.png");

    //Inicializacion de sonidos
    musicaFondo.openFromFile("musica/ZanderNoriega-DarkerWaves.wav");
    explosionNaveBuffer.loadFromFile("musica/DeathFlash.flac");
    explosionNaveSound.setBuffer(explosionNaveBuffer);
    explosionAstBuffer.loadFromFile("musica/SFX_Explosion_03.wav");
    explosionAstSound.setBuffer(explosionAstBuffer);

}

int PantallaJuego::Run(sf::RenderWindow &App) {
    //Variables
    bool running = true;
    bool pausa = false;
    int puntaje = 0;
    sf::Font font;
    int cantidadAsteroides = 0;
    sf::Sprite sprite; //creo un sprite
    std::vector <Asteroide> asteroides;
    std::vector <Luna> lunas;
    sf::Clock syncronice_timer;
    game::Ship nave = game::Ship(texturaNaveReal);
    std::vector <Bala> balas;
    sf::Clock relojLuna;
    sf::Time timeLuna;
    float tiempoLuna = 0;
    sf::Clock relojJuego;
    sf::Time timeJuego;
    sf::Clock relojDisparo;
    sf::Time timeDisparo;
    int velocidadAsteroide = 0;   
    int tiempoSigNivel = 45;
    sf::Clock relojLuna2;
    sf::Time timeLuna2;
    bool exploto = false;
    bool colisionoConAst = false;
    int vidas=3;
    sf::Clock empiezaJuegoC;
    sf::Time empiezaJuegoT;
    bool noPausa = true;
    //Fin de declaracion de variables

    //musica y sonidos
    //Agregar credito a Zander Noriega pendiente
    musicaFondo.setLoop(true);
    musicaFondo.play();
    musicaFondo.setVolume(60);

    //finMusica y sonidos 
    Animacion explosionUno(explosion, 1, 1, 256, 256, 48, 0.3f);
    sprite.setTexture(fondo); //le seteo la textura
    //seteo el tamaño del fondo
    sprite.setOrigin(anchoResolucion / 15, altoResolucion / 5);

    //Carga la tipografía
    if (!font.loadFromFile("font/Cave-Story.ttf")) {
        //Aquí hay que manejar el error
    }
    //Setea la tipografia
    score.setFont(font);
    //Para evitar un uso innecesario del procesador,limita los fps a 60
    App.setFramerateLimit(75);
    //Para evitar efecto shuttering
    App.setVerticalSyncEnabled(true);
    //Desactiva el mouse,ya que no es necesario para jugar
    App.setMouseCursorVisible(false);
    score.setCharacterSize(32);
    cuentaRegresiva.setFont(font);
    cuentaRegresiva.setCharacterSize(55);




    while (running) {
        
        
        empiezaJuegoT=empiezaJuegoC.getElapsedTime();
        if((int)empiezaJuegoT.asSeconds()>3){
        timeJuego = relojJuego.getElapsedTime();
            
        if((int) timeJuego.asSeconds()>=1 && !pausa){
        
            tiempoSigNivel--;
            relojJuego.restart();
        }
        
        if (1 > tiempoSigNivel) {
            velocidadAsteroide += 1;
            
            tiempoSigNivel =45+ (velocidadAsteroide * 5);
        }


        float delta_time_seconds = syncronice_timer.restart().asSeconds();


        //Actualiza el score en cada vuelta del bucle
        score.setString("Score : " + std::to_string(puntaje) + "\nNivel    :  " + std::to_string(velocidadAsteroide + 1) + "\nTiempo para el siguiente nivel    :     " + std::to_string(tiempoSigNivel )+"\nVidas : "+std::to_string(vidas)); //Esto es necesario para matar el programa cuando se cierra la ventana

        sf::Event event;
        while (App.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                return (-1);
            }
        }
        if (asteroides.size() <= 10) {

            Asteroide asteroide = Asteroide(texturaAsteroide, velocidadAsteroide);
            Asteroide asteroide2 = Asteroide(texturaAsteroide, velocidadAsteroide);
            Asteroide asteroide3 = Asteroide(texturaAsteroide, velocidadAsteroide);
            Asteroide asteroide4 = Asteroide(texturaAsteroide2, velocidadAsteroide);
            Asteroide asteroide5 = Asteroide(texturaAsteroide3, velocidadAsteroide);

            asteroides.push_back(asteroide);
            asteroides.push_back(asteroide2);
            asteroides.push_back(asteroide3);
            asteroides.push_back(asteroide4);
            asteroides.push_back(asteroide5);

            cantidadAsteroides += 5;
        }
        for (int i = 0; i < asteroides.size(); i++) {
            asteroides[i].verificarExistencia(i, asteroides);
        }

        if (lunas.size() < 1 && (velocidadAsteroide + 1) >= 2 && (int) timeLuna2.asSeconds() >= 10) {
            relojLuna.restart();
            Luna luna = Luna(texturaLuna);
            lunas.push_back(luna);
        }
        timeLuna = relojLuna.getElapsedTime();
        tiempoLuna = timeLuna.asSeconds();
        if (tiempoLuna > 30.0) {
            for (int i = 0; i < lunas.size(); i++) {
                lunas[i].setMovimientoY(2);

            }
        }
        if (lunas.size() >= 1) {
            for (int i = 0; i < lunas.size(); i++) {

                lunas[i].verificarExistencia(i, lunas, relojLuna2);
            }
        }
        timeLuna2 = relojLuna2.getElapsedTime();

        nave.update(delta_time_seconds);

        
        //limpiamos la pantalla
        App.clear();
        //dibujamos la pantalla
        App.draw(sprite); //dibujo fondo

        for (int i = 0; i < lunas.size(); i++) {
            lunas[i].Mostrar(App);
            lunas[i].ActualizarPosicion();

        }
        App.draw(score);
        nave.mostrar(App);

        timeDisparo = relojDisparo.getElapsedTime();
        if (timeDisparo.asSeconds() > 0.25) {
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                Bala bala(nave, texturaBala);
                balas.push_back(bala);
                relojDisparo.restart();
            }
        }

        for (int i = 0; i < balas.size(); i++) {
            balas[i].mostrar(App);
            balas[i].colisiona(balas, asteroides, explosionUno, App, puntaje, lunas,colisionoConAst);
            if (balas[i].spriteBala.getPosition().x > anchoResolucion  || balas[i].spriteBala.getPosition().y > altoResolucion || balas[i].spriteBala.getPosition().x < 0  || balas[i].spriteBala.getPosition().y < 0) {
                balas.erase(balas.begin() + i);
            }
        }
        
         if (colisionoConAst) {
             
            colisionoConAst = false;
            explosionNaveSound.play();
            explosionNaveSound.setVolume(100);}
        for (int i = 0; i < asteroides.size(); i++) {
            asteroides[i].Mostrar(App);
            asteroides[i].ActualizarPosicion();
        }
        
        nave.colisiona(asteroides, nave, explosionUno, App, exploto, lunas);

        if (exploto) {
            musicaFondo.stop();
            exploto = false;
            explosionAstSound.play();
            explosionAstSound.setVolume(300);
            nave.reset();
            vidas--;
            velocidadAsteroide=0;
            tiempoSigNivel=45;
            while (asteroides.begin() != asteroides.end()) {
                asteroides.erase(asteroides.begin());
            };
            while (balas.begin() != balas.end()) {
                balas.erase(balas.begin());
            };
            while (lunas.begin() != lunas.end()) {
                lunas.erase(lunas.begin());
            };
            relojJuego.restart();
            musicaFondo.play();
            empiezaJuegoC.restart();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && pausa) {
            musicaFondo.pause();
            std::vector<sf::Sprite> sprites;
            sprites.push_back(sprite);
            sprites.push_back(nave.getSprite());
            for (int i = 0; i < lunas.size(); i++) {
                sprites.push_back(lunas[i].getSprite());
            }


            for (int i = 0; i < asteroides.size(); i++) {
                sprites.push_back(asteroides[i].getSprite());
            }
            MenuPausa menuPausa;
            menuPausa.run(App, sprites, running);
            musicaFondo.play();
            pausa = false;
            relojJuego.restart();
        }
        if(vidas<0){
            musicaFondo.pause();
            gameOver gameover(puntaje);
            gameover.Run(App);
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !pausa) {

            pausa = true;
        }
        App.display();
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num0)) {
            return (-1);
        }
        }else{
            relojJuego.restart();
            cuentaRegresiva.setString("El juego comienza en: "+std::to_string(3-(int)empiezaJuegoT.asSeconds()));
            cuentaRegresiva.setPosition(anchoResolucion/2.5,altoResolucion/3);
            App.clear();
            App.draw(sprite);
            App.draw(score);
            App.draw(cuentaRegresiva);
             nave.mostrar(App);
              if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && !pausa) {

            pausa = true;
        }
     if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) && pausa) {
            musicaFondo.pause();
            std::vector<sf::Sprite> sprites;
            sprites.push_back(sprite);
            sprites.push_back(nave.getSprite());
            for (int i = 0; i < lunas.size(); i++) {
                sprites.push_back(lunas[i].getSprite());
            }


            for (int i = 0; i < asteroides.size(); i++) {
                sprites.push_back(asteroides[i].getSprite());
            }
            MenuPausa menuPausa;
            menuPausa.run(App, sprites, running);
            musicaFondo.play();
            
            pausa = false;
            empiezaJuegoC.restart();
        }
            App.display();
        
        
        }}
    return -1;



}
