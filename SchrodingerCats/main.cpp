#include <SFML/Graphics.hpp>
#include<chrono>
#include"character.h"
#include"object.h"
#include"tilemap.h"

using namespace std;

int main()
{
    //Create window
    sf::RenderWindow window(sf::VideoMode(512, 256), "Schrodinger's Cats");
    window.setVerticalSyncEnabled(true);

    //create tileMap
    const int level[]=
    {
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,
        1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,
    };

    tilemap mapLevel;
    if(!mapLevel.load(sf::Vector2u(32,32),level,16,8,"../SpriteSheets/Tileset/tileset.png")){
        return -1;
    }


    //Create players
    character player1({100.0f,100.0f},"../SpriteSheets/Characters/pipo-nekonin029.png");
    character player2({100.0f,100.0f},"../SpriteSheets/Characters/pipo-nekonin026.png");

    object tunnelEffect({256.0f,128.0f},"../SpriteSheets/Objects/pipo-popupemotes015.png");

    //Create time point for measurement
    auto timePoint = std::chrono::steady_clock::now();

    //Open main window
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        //Compute detla time
        float deltaTime;{
            const auto newTimePoint = std::chrono::steady_clock::now();
            deltaTime = std::chrono::duration<float>(newTimePoint - timePoint).count();
            timePoint = newTimePoint;
        }

        //Handle Player1 keyboard
        sf::Vector2f p1Direction = {0.0f, 0.0f};

        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
            p1Direction.y -= 1.0f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left)){
            p1Direction.x -= 1.0f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
            p1Direction.y += 1.0f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right)){
            p1Direction.x += 1.0f;
        }

        //Handle Player2 keyboard
        sf::Vector2f p2Direction = {0.0f, 0.0f};
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
            p2Direction.y -= 1.0f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::A)){
            p2Direction.x -= 1.0f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            p2Direction.y += 1.0f;
        }
        if(sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            p2Direction.x += 1.0f;
        }

        player1.setVelocityDirection(p1Direction);
        player2.setVelocityDirection(p2Direction);
        player1.update(deltaTime);
        player2.update(deltaTime);
        tunnelEffect.update(deltaTime);
        window.clear();
        window.draw(mapLevel);
        tunnelEffect.draw(window);
        player1.draw(window);
        player2.draw(window);

        window.display();
    }

    return 0;
}

