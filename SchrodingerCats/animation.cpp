#include"animation.h"

using namespace std;

animation::animation(int initFrameXPos, int initFrameYPos, int initFrameWidth, int initFrameHeight, const std::string spriteSheetPath){

    //Load texture (spriteSheet)
    if(!mTexture.loadFromFile(spriteSheetPath)){
        cerr<<"Character error: Loading texture"<<endl;
        system("pause");
    }
    //Create frames positions/dimensions
    for(int i(0); i<mNumFrames;i++){
        mFrames[i]= {initFrameXPos + i*initFrameHeight, initFrameYPos, initFrameWidth, initFrameHeight};
    }

}

void  animation::applyToSprite(sf::Sprite& sprite){
    sprite.setTexture(mTexture);
    sprite.setTextureRect(mFrames[mIdxFrame]);
}

void animation::update(float deltaTime){
    mEnlapsedTime += deltaTime;
    while(mEnlapsedTime >= mHoldTime){
        mEnlapsedTime -= mHoldTime;
        advance();
    }
}

void animation::advance(void){
    if(++mIdxFrame >= mNumFrames){
        mIdxFrame=0;
    }
}

