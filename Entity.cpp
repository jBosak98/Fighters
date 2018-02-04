#include "values.h"
class Entity{
public:
  float x,y,dx,dy,dir;
  bool isAlive;
  std::string name;
  Animation anim;

  Entity(){isAlive=1;}

  void settings(Animation &a, int X, int Y,float Dir = 0){
    x = X;
    y = Y;
    anim = a;
    dir = Dir;

  }

  virtual void update(){};

  void draw(RenderWindow &app){
    Texture textt;
    textt.loadFromFile(PLAYER_TEXTURE);
    anim.sprite.setTexture(textt);
    anim.sprite.setPosition(x,y);
    anim.sprite.setTextureRect(IntRect(0,80,80,80));
    anim.sprite.setOrigin(40,40);

    app.draw(anim.sprite);
  }
};
