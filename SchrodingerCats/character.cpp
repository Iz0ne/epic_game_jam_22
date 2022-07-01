#include"character.h"
using namespace std;

character::character(std::string texturePath, unsigned int numOfRow, unsigned int numOfCols){
    if(!mTexture.loadFromFile(texturePath)){
        cerr<<"Character error: Loading texture"<<endl;
    }
}

void character::moveCharacter(char direction){
    switch(direction){
        case 'up':
        break;

        case 'down':
        break;

        case 'right':
        break;

        case 'left':
        break;

        case 'idle':
        break;


        default:

        break;

    }
}
