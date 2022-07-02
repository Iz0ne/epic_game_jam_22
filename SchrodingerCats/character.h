#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include<string>
#include"animation.h"

class character{
    private:
    enum class mAnimationIdx{
        walkingUp,
        walkingDown,
        walkingRight,
        walkingLeft,
        Count
    };


    public:
    character(const sf::Vector2f position, std::string spriteSheetPath);
    ~character();

    void setVelocityDirection(const sf::Vector2f& direction);
    void setSpeed(float speed);

    void update(float detlaTime);
    void draw(sf::RenderTarget& renderTarget) const;



    protected:
    float mSpeed=200.0f;
    sf::Vector2f mDirection;
    sf::Vector2f mVelocity;
    sf::Vector2f mPosition;
    sf::Sprite mSprite;
    sf::Texture mTexture;
    animation mAnimations[int(mAnimationIdx::Count)];
    mAnimationIdx currentAnimation = mAnimationIdx::walkingDown;

};

#endif // CHARACTER_H_INCLUDED
