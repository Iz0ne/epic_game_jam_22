#include"character.h"
using namespace std;

character::character(const sf::Vector2f position, std::string spriteSheetPath){

    //Set Animations
    mAnimations[int(mAnimationIdx::walkingDown)]=animation(0,0*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingLeft)]=animation(0,1*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingRight)]=animation(0,2*32,32,32,spriteSheetPath);
    mAnimations[int(mAnimationIdx::walkingUp)]=animation(0,3*32,32,32,spriteSheetPath);

    //Set character position
    mPosition=position;

    //Set sprite sheet position
    mSprite.setPosition(mPosition);
    mSprite.setTextureRect(sf::IntRect(mPosition.x,mPosition.y,32,32));

    //set hitBox (default = sprite dimension/position)
    mHitbox=hitbox(mPosition,sf::Vector2f(32.0,32.0));
    mHitboxOffset=sf::Vector2f(0.0f,0.0f);


}


character::~character(){
}

void character::setHeading(const sf::Vector2f& heading){
    mHeading=heading;
}


void character::setVelocity(const sf::Vector2f& velocity){
    mVelocity = velocity * mSpeed;
    if(mVelocity.x>0){
        currentAnimation=mAnimationIdx::walkingRight;
    }
    else if(mVelocity.x<0){
        currentAnimation=mAnimationIdx::walkingLeft;
    }
    else if(mVelocity.y>0){
        currentAnimation=mAnimationIdx::walkingDown;
    }
    else if(mVelocity.y<0){
        currentAnimation=mAnimationIdx::walkingUp;
    }
}

void character::setPosition(const sf::Vector2f& position){
    mPosition=position;
}

sf::Vector2f character::getPosition(void){
    return mPosition;
}

void character::setSpeed(float speed){
    mSpeed=speed;
}

void character::draw(sf::RenderTarget& renderTarget) const{
    renderTarget.draw(mSprite);

    if(mDrawHitbox){
        mHitbox.draw(renderTarget);
    }
}

void character::update(float deltaTime){
    mPosition += mVelocity * deltaTime;

    //Update Animation
    mAnimations[int(currentAnimation)].update(deltaTime);
    mAnimations[int(currentAnimation)].applyToSprite(mSprite);

    //Update Sprite position
    mSprite.setPosition(mPosition);

    //Update hitBox position
    mHitbox.setPosition(mPosition+mHitboxOffset);
}


sf::Sprite& character::getSprite(void){
    return mSprite;
}
sf::Vector2f& character::getHeading(void){
    return mHeading;
}

void character::setHitBoxParameters(float xOffset, float yOffset, float width, float height){
    mHitboxOffset=sf::Vector2f(xOffset,yOffset);
    mHitbox.setPosition(mPosition+mHitboxOffset);
    mHitbox.setDimension(sf::Vector2f(width,height));
}

void character::drawHitbox(bool drawHitbox){
    mDrawHitbox=drawHitbox;
}
