#ifndef HITBOX_H_INCLUDED
#define HITBOX_H_INCLUDED
#include <SFML/Graphics.hpp>

class hitbox{
    public:
    //Constructor&Destructor
    hitbox() = default;
    hitbox(sf::Vector2f position, sf::Vector2f dimension);
    ~hitbox();

    //Setter functions
    void setPosition(sf::Vector2f newPosition);
    void setDimension(sf::Vector2f newDimension);


    //Getter functions
    sf::FloatRect& getRectangle(void);

    //Other functions
    void draw(sf::RenderTarget& renderTarget) const;


    protected:
    sf::FloatRect mRectangle;
};
#endif // HITBOX_H_INCLUDED
