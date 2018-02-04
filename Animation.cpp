#include <SFML/Graphics.hpp>
using namespace sf;

class Animation{
public:
  float Frame;
  Sprite sprite;
  std::vector<IntRect> frames;


  Animation(){}
  Animation(Texture texture, int x, int y, int width, int height){
    Frame = 0;
    //for(int i = 0; i< count; i++){

    sprite.setTexture(texture);
    frames.push_back(IntRect(x,y,width,height));
    sprite.setOrigin(width/2, height/2);
    sprite.setTextureRect(IntRect(0,0,80,80));


    //}

  }
  void update(){

  }

};
