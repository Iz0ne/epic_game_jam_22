#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
#include<iostream>
#include"character.h"

class tilemap: public sf::Drawable, public sf::Transformable{

    public:
    bool load(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, std::string tileSetPath);
    bool checkCollision(character player) const;

    private:
    virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;

    private:
    sf::VertexArray mVertices;
    sf::Texture mTileSet;
    const int* mTiles;
};
#endif // TILEMAP_H_INCLUDED
