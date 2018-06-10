

#ifndef LUNA_H
#define LUNA_H

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Sprite.hpp>


class Luna {
public:
    Luna(sf::Texture &texturaNave);
    void Mostrar(sf::RenderWindow &window);
    void ActualizarPosicion();
    void verificarExistencia(int indice,std::vector<Luna> &vector);
    void abc(sf::RenderWindow &window,std::vector<Luna> &asteroides);
    sf::Sprite getSprite();
       void setMovimientoY(int movimientoY);
private:
 
    void generarOrigen();
   // sf::Texture texturaNave;
    sf::Sprite spriteLuna;
    int movimientoX;
    int y;
    int x;
    int movimientoY;
    int randomSeed=0;
};

#endif /* LUNA_H */

