#include <iostream>
#include <SFML/Graphics.hpp>
using namespace sf;

class Animation{
public:
  float Frame;
  Sprite sprite;
  std::vector<IntRect> frames;
  Texture texture;
  int indexTexture;
  int lastTextures[5] = {0, 0, 0, 0, 0};



  Animation(){}
  Animation(Texture t, int width, int height){
    texture = t;
    Frame = 0;
    indexTexture = 0;
    for(int row = 0; row <= 7;row++){

      for(int column = 0; column < 10; column++){
        frames.push_back(IntRect(column*width,row*height,width,height));//for direction = RIGHT
        frames.push_back(IntRect((column+1)*width,row*height,(-1)*width,height));//here direction = LEFT
      }
    }
    sprite.setTexture(texture);
    sprite.setOrigin(width/2, height/2);
    sprite.setTextureRect(frames[0]);
  }

  void update(){
    if(frames.size() >0){
      sprite.setTextureRect(frames[indexTexture]);
    }

  }

  void walk(int direction){
    if(indexTexture >= 8 && indexTexture <= 13){
      if(nextTexture(indexTexture))
        indexTexture+=2;

    }else indexTexture = 8 + direction;

  }


bool nextTexture(int indexTexture){
  lastTextures[4] = lastTextures[3];
  lastTextures[3] = lastTextures[2];
  lastTextures[2] = lastTextures[1];
  lastTextures[1] = lastTextures[0];
  lastTextures[0] = indexTexture;
  if(lastTextures[0] == lastTextures[1] &&
     lastTextures[0] == lastTextures[2] &&
     lastTextures[0] == lastTextures[3] &&
     lastTextures[0] == lastTextures[4]){
       return true;
     }
  return false;
}
};
