#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <SFML/Graphics.hpp>
#include<string>
#include"animation.h"
#include"hitbox.h"


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

    void setHeading(const sf::Vector2f& heading);
    void setVelocity(const sf::Vector2f& velocity);
    void setSpeed(float speed);

    void setPosition(const sf::Vector2f& position);
    sf::Vector2f getPosition(void);

    sf::Vector2f& getHeading(void);

    void update(float detlaTime);
    void draw(sf::RenderTarget& renderTarget) const;

    //Will be deleted afterwards
    sf::Sprite& getSprite(void);

    void setHitBoxParameters(float xOffset, float yOffset, float width, float height);
    void drawHitbox(bool drawHitbox);

    protected:
    float mSpeed=200.0f;
    sf::Vector2f mHeading;
    sf::Vector2f mVelocity;
    sf::Vector2f mPosition;
    sf::Sprite mSprite;
    bool mDrawHitbox = false;
    sf::Vector2f mHitboxOffset;
    hitbox mHitbox;


    animation mAnimations[int(mAnimationIdx::Count)];
    mAnimationIdx currentAnimation = mAnimationIdx::walkingDown;

};

#endif // CHARACTER_H_INCLUDED
