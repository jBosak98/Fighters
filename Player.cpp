#include "main.h"
#include "values.h"


class Player: public Entity{
public:
  bool thrustAttack;
  int horizontalMotion;
  int verticalMotion;
  int lastAction;

  Player(){
    name = "player";
    horizontalMotion = NONE;
    lastAction = NONE;
  }
  
  void update(){
    performAction(horizontalMotion);
    performAction(verticalMotion);
    if(horizontalMotion != NONE || verticalMotion != NONE){
      anim.walk(direction);
    } else {anim.indexTexture = 0 + direction;}
    anim.update();

    lastAction = horizontalMotion;
    horizontalMotion = NONE;
    verticalMotion = NONE;
  }

  void performAction(int action){
    int speed = 4;
    switch(action){
      case GOES_RIGHT:
      direction = RIGHT;
      x += speed;
      break;

      case GOES_LEFT:
      direction = LEFT;
      x -= speed;
      break;

      case GOES_UP:
      y -= speed;
      break;

      case GOES_DOWN:
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
