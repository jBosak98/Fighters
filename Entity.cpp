#include "values.h"

class Entity{
public:
  float x,y,dx,dy,dir;
  bool isAlive;
  std::string name;
  Animation anim;
  int direction;

  Entity(){isAlive=1;}

  void settings(Animation &a, int X, int Y,int dir){
    x = X;
    y = Y;
    anim = a;
    direction = dir;

  }

  virtual void update(){};

  void draw(RenderWindow &app){
    anim.sprite.setPosition(x,y);
    app.draw(anim.sprite);
  }
};
