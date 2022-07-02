#ifndef OBJECT_H_INCLUDED
#define OBJECT_H_INCLUDED
#include"animation.h"

class object{

    private:
    enum class mAnimationIdx{
        idle,
        Count
    };


    public:
        object();
    protected:
    sf::Vector2f mPosition;
    animation mAnimations[int(mAnimationIdx::Count)];
    mAnimationIdx currentAnimation = mAnimationIdx::idle;
};



#endif // OBJECT_H_INCLUDED
