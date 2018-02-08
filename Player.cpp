#include "main.h"
#include "values.h"
using namespace sf;
#include <SFML/Graphics.hpp>


class Player: public Entity{
public:
  int horizontalMotion;
  int verticalMotion;
  int operation;
  int realY = 0;
  int jumpStep = 0;


  Player(String n){
    name = n;
    horizontalMotion = NONE;
    verticalMotion = NONE;
  }

  void update(){
    if(operation == JUMP){
      jump();
    }else{
      performAction(horizontalMotion);
      performAction(verticalMotion);
      if(horizontalMotion != NONE || verticalMotion != NONE){
        anim.walk(direction);
      }  else {anim.indexTexture = 0 + direction;}
    }

    anim.update();

    horizontalMotion = NONE;
    verticalMotion = NONE;
  }

  void jump(){
    int sign;
    if(jumpStep <14)sign = -1;
    else sign = 1;
    if(jumpStep%23 < 5){//case 0: 1: 2: 3: 4: 23: 24: 25: 26: 27:
      anim.indexTexture = getIdOfFrame(60);
      y+=9*sign;
    } else if(jumpStep>=10 && jumpStep <=17){//case:10: 11: 12: 13: 14: 15: 16: 17:
      anim.indexTexture = getIdOfFrame(62);
      y+=sign*7;
    } else{//case 5: 6: 7: 8: 9: 18: 19: 20: 21: 22:
      anim.indexTexture = getIdOfFrame(61);
      y+=8*sign;
    }

    jumpStep++;
    if(jumpStep == 28){
      operation = NONE;
      jumpStep = 0;
    }
  }

  void performAction(int action){
    int speed = 4;
    switch(action){
      case GOES_RIGHT:
      direction = RIGHT;
      if(x<=APP_WIDTH)
        x += speed;
      break;

      case GOES_LEFT:
      direction = LEFT;
      if(x>=0)
        x -= speed;
      break;

      case GOES_UP:
      if(y>=40)
        y -= speed;
      break;

      case GOES_DOWN:
      if(y<=APP_HEIGHT - 50)
        y += speed;
      break;

      case NONE:
      break;
    }
  }

  int getIdOfFrame(int index){
    return (index * 2) + direction;
  }
};
