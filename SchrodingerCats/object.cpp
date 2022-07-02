#include"object.h"

object::object(const sf::Vector2f position, std::string spriteSheetPath){
    mAnimations[int(mAnimationIdx::idle)]=animation(0,0*32,32,32,spriteSheetPath);
    mSprite.setPosition(position);
}

void object::update(float deltaTime){
    mAnimations[int(currentAnimation)].update(deltaTime);
    mAnimations[int(currentAnimation)].applyToSprite(mSprite);
}

void object::draw(sf::RenderTarget& renderTarget) const{
    renderTarget.draw(mSprite);
}
