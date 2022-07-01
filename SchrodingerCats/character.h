#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include<iostream>
#include<string>

class character{

    public:
    character(std::string texturePath, unsigned int numOfRow, unsigned int numOfCols);
    void moveCharacter(char direction);
    //void pickUpObject(void);
    //~character();


    protected:
    sf::Texture mTexture;
    sf::Sprite mSprite;

};

#endif // CHARACTER_H_INCLUDED
