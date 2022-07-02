#include"character.h"
using namespace std;

character::character(const sf::Vector2f position, std::string spriteSheetPath){

    //Set Walking animations
    mAnimations[int(mAnimationIdx::walkingDown)]=animation(0,0*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingLeft)]=animation(0,1*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingRight)]=animation(0,2*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingUp)]=animation(0,3*32,32,32,spriteSheetPath);

    mSprite.setTexture(mTexture);
    mSprite.setTextureRect(sf::IntRect(0,0,32,32));

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
}

void character::update(float deltaTime){
    mPosition += mVelocity * deltaTime;
    mAnimations[int(currentAnimation)].update(deltaTime);
    mAnimations[int(currentAnimation)].applyToSprite(mSprite);

    mSprite.setPosition(mPosition);
}
