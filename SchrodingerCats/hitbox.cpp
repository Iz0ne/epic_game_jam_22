#include"hitbox.h"

//short: Hitbox Constructor
//params:
//return: none
hitbox::hitbox(sf::Vector2f position, sf::Vector2f dimension){

    //Set rectangle position
    mRectangle.left=position.x;
    mRectangle.top=position.y;

    //Set rectangle dimension
    mRectangle.width=dimension.x;
    mRectangle.height=dimension.y;
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
    mRectangle.left=newPosition.x;
    mRectangle.top=newPosition.y;
}

//short: set hitbox position
//params:
//return: none
void hitbox::setDimension(sf::Vector2f newDimension){
    mRectangle.width=newDimension.x;
    mRectangle.height=newDimension.y;
}

//short: get rectangleHitbox
sf::FloatRect& hitbox::getRectangle(void){
    return mRectangle;
}

//short: set hitbox position
//params:
//return: none
void hitbox::draw(sf::RenderTarget& renderTarget) const{
    sf::RectangleShape hitBox(sf::Vector2f(mRectangle.width,mRectangle.height));
    hitBox.setFillColor(sf::Color(0,0,255));
    hitBox.setPosition(sf::Vector2f(mRectangle.left,mRectangle.top));
    renderTarget.draw(hitBox);
}
