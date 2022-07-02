#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include <SFML/Graphics.hpp>
#include"animation.h"

class object{

    private:
    enum class mAnimationIdx{
        idle,
        Count
    };

    public:
    object(const sf::Vector2f position, std::string spriteSheetPath);
    void update(float deltaTime);
    void draw(sf::RenderTarget& renderTarget) const;

    protected:
    sf::Vector2f mPosition;
    sf::Sprite mSprite;
    animation mAnimations[int(mAnimationIdx::Count)];
    mAnimationIdx currentAnimation = mAnimationIdx::idle;
};



#endif // OBJECT_H_INCLUDED
