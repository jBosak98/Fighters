#include "main.h"
#include "values.h"


class Player: public Entity{
public:
  bool thrustAttack;
  int horizontalMotion;
  int verticalMotion;


  Player(){
    name = "player";
    horizontalMotion = NONE;
    verticalMotion = NONE;
  }

  void update(){
    performAction(horizontalMotion);
    performAction(verticalMotion);
    if(horizontalMotion != NONE || verticalMotion != NONE){
      anim.walk(direction);
    } else {anim.indexTexture = 0 + direction;}
    anim.update();

    horizontalMotion = NONE;
    verticalMotion = NONE;
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
