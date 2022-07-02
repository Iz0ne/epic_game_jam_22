#ifndef ANIMATION_H_INCLUDED
#define ANIMATION_H_INCLUDED
#include <SFML/Graphics.hpp>
#include<string>
#include<iostream>

class animation{

    public:
    animation() = default;
    animation(int initFrameXPos, int initFrameYPos, int initFrameWidth, int initFrameHeight, const std::string spriteSheetPath);
    void applyToSprite(sf::Sprite& sprite);
    void update(float deltaTime);

    private:
    void advance(void);

    private:
    static constexpr int mNumFrames = 3;
    static constexpr float mHoldTime = 0.1f; //Holding time of frame on scree
    sf::Texture mTexture;
    sf::IntRect mFrames[mNumFrames];
    int mIdxFrame = 0;
    float mEnlapsedTime = 0.0f;       //Keep track of time passed*/
};

#endif // ANIMATION_H_INCLUDED
