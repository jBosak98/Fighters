#include "main.h"
#include "values.h"


class Player: public Entity
{
public:
  bool thrustAttack;
  int actionPrimary;
  int actionSecondary;

   Player(){
    name = "player";
    actionPrimary = NONE;
  }


void update(){
  performAction(actionPrimary);
  performAction(actionSecondary);
    actionPrimary = NONE;
    actionSecondary = NONE;
  }
void performAction(int action){
  switch(action){
    case GOES_RIGHT:
      x += 3;
    break;
    case GOES_LEFT:
      x -= 3;
    break;
    case GOES_UP:
      y -= 3;
    break;
    case GOES_DOWN:
      y += 3;
    break;
  }
}
};
