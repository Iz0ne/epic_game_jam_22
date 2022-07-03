#include"tilemap.h"

bool tilemap::load(sf::Vector2u tileSize, const int* tiles, unsigned int tileNumX, unsigned int tileNumY, std::string tileSetPath){
    //store tile pointer
    mTiles = tiles;

    //Load the texture
    if(!mTileSet.loadFromFile(tileSetPath)){
        return false;
    }

    //Resize the vertex array (num of vertex) depending on the number of tiles in the tilemap X/Y
    mVertices.setPrimitiveType(sf::Quads);
    mVertices.resize(tileNumX*tileNumY*4);            //Multiplied by 4 (4 vertex per tile)

    //populate the vertex array with one quad per tile
    for(unsigned int i=0; i<tileNumX; ++i){
        for(unsigned j=0; j<tileNumY; ++j){

            //get the current tile ID number (code 0,1,2,3)
            int tileNumber = mTiles[i + j*tileNumX];

            //find its position in the tileSet texture
            int tu = tileNumber % (mTileSet.getSize().x/tileSize.x);    //What is Tu get the
            int tv = tileNumber / (mTileSet.getSize().x/tileSize.x);    //What is Tv get the integer value (num of time looped over)

            //get a pointer to the current tile's quad
            sf::Vertex* quad = &mVertices[(i + j*tileNumX)*4];  //Multiplied by 4 -> [0 1 2 3] -> [4 5 6 7]

            //define current tile's 4 corners positions quad[0] = *quad -> quad[1] = *(quad+1)
            quad[0].position = sf::Vector2f(i*tileSize.x, j*tileSize.y);
            quad[1].position = sf::Vector2f((i+1)*tileSize.x, j*tileSize.y);
            quad[2].position = sf::Vector2f((i+1)*tileSize.x, (j+1)*tileSize.y);
            quad[3].position = sf::Vector2f(i*tileSize.x, (j+1)*tileSize.y);

            //define current tile's 4 corners textures
            quad[0].texCoords = sf::Vector2f(tu*tileSize.x, tv*tileSize.y);
            quad[1].texCoords = sf::Vector2f((tu+1)*tileSize.x, tv*tileSize.y);
            quad[2].texCoords = sf::Vector2f((tu+1)*tileSize.x, (tv+1)*tileSize.y);
            quad[3].texCoords = sf::Vector2f(tu*tileSize.x, (tv+1)*tileSize.y);
        }
    }
    return true;
}

void tilemap::draw(sf::RenderTarget& renderTarget, sf::RenderStates renderStates) const{
    //Apply the transformation
    renderStates.transform *= getTransform();

    //Apply the tileset texture
    renderStates.texture = &mTileSet;

    //Draw the vertex array
    renderTarget.draw(mVertices,renderStates);
}

bool tilemap:: checkCollision(character player) const{
    int tileNumber = mTiles[int(((player.getSprite().getPosition().x+16)/32)) + int(((player.getSprite().getPosition().y+28)/32))*16];
    //std::cout<<"TileNumber: "<<tileNumber<<std::endl;

    if(tileNumber!=0){
        //std::cout<<"Error"<<std::endl;
        return true;
    }
    return false;
}
