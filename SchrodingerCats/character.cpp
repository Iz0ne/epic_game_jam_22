#include"character.h"
using namespace std;

character::character(const sf::Vector2f position, std::string spriteSheetPath){

    //Set Walking animations
    mAnimations[int(mAnimationIdx::walkingDown)]=animation(0,0*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingLeft)]=animation(0,1*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingRight)]=animation(0,2*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingUp)]=animation(0,3*32,32,32,spriteSheetPath);

    mPosition=position;
}


character::~character(){
}


void character::setVelocityDirection(const sf::Vector2f& direction){
    mVelocity= direction * mSpeed;
    if(direction.x>0){
        currentAnimation=mAnimationIdx::walkingRight;
    }
    else if(direction.x<0){
        currentAnimation=mAnimationIdx::walkingLeft;
    }
    else if(direction.y>0){
        currentAnimation=mAnimationIdx::walkingDown;
    }
    else if(direction.y<0){
        currentAnimation=mAnimationIdx::walkingUp;
    }
}

void character::setSpeed(float speed){
    mSpeed=speed;
}

void character::draw(sf::RenderTarget& renderTarget) const{
    renderTarget.draw(mSprite);

    sf::RectangleShape rectangle(sf::Vector2f(13, 18));
    rectangle.setFillColor(sf::Color(0,0,255));
    rectangle.setPosition(sf::Vector2f(mSprite.getPosition().x+16-(rectangle.getSize().x/2)+0.5, mSprite.getPosition().y+10));
    renderTarget.draw(rectangle);
}

void character::update(float deltaTime){
    mPosition += mVelocity * deltaTime;
    mAnimations[int(currentAnimation)].update(deltaTime);
    mAnimations[int(currentAnimation)].applyToSprite(mSprite);

    mSprite.setPosition(mPosition);
}


sf::Sprite& character::getSprite(void){
    return mSprite;
}
