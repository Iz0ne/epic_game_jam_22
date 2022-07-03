#include"hitbox.h"

//short: Hitbox Constructor
//params:
//return: none
hitbox::hitbox(sf::Vector2f position, sf::Vector2f dimension){
    mPosition=position;
    mDimension=dimension;
}

//short: Hitbox Destructor
//params: none
//return: none
hitbox::~hitbox(){
}

//short: set hitbox position
//params:
//return: none
void hitbox::setPosition(sf::Vector2f newPosition){
    mPosition=newPosition;
}

//short: set hitbox position
//params:
//return: none
void hitbox::setDimension(sf::Vector2f newDimension){
    mDimension=newDimension;
}

//short: set hitbox position
//params:
//return: none
void hitbox::draw(sf::RenderTarget& renderTarget) const{
    sf::RectangleShape hitBox(sf::Vector2f(mDimension.x,mDimension.y));
    hitBox.setFillColor(sf::Color(0,0,255));
    hitBox.setPosition(sf::Vector2f(mPosition.x,mPosition.y));
    renderTarget.draw(hitBox);
}
