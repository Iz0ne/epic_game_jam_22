#ifndef TILEMAP_H_INCLUDED
#define TILEMAP_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>

class tilemap: public sf::Drawable, public sf::Transformable{

    public:
    bool load(sf::Vector2u tileSize, const int* tiles, unsigned int width, unsigned int height, std::string tileSetPath);


    private:
    virtual void draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const;

    private:
    sf::VertexArray mVertices;
    sf::Texture mTileSet;
};
#endif // TILEMAP_H_INCLUDED
