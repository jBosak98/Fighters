#include "main.h"
#include "values.h"
#include <list>
#include <iostream>


void isDesireToClose(RenderWindow &app){
  Event event;
  while(app.pollEvent(event)) {
    if((event.type == Event::Closed) ||
       (Keyboard::isKeyPressed(Keyboard::Escape)))
        app.close();
      }
}

void keyboardInputs(Player &player){
  if(Keyboard::isKeyPressed(Keyboard::Right)) player.horizontalMotion = GOES_RIGHT;
  if(Keyboard::isKeyPressed(Keyboard::Left)) player.horizontalMotion = GOES_LEFT;
  if(Keyboard::isKeyPressed(Keyboard::Up)) player.verticalMotion = GOES_UP;
  if(Keyboard::isKeyPressed(Keyboard::Down)) player.verticalMotion = GOES_DOWN;
  if(Keyboard::isKeyPressed(Keyboard::Space)) player.operation = JUMP;
}



void loop(RenderWindow &app, std::list<Entity*> &entities, Sprite background){
  while (app.isOpen()) {
    isDesireToClose(app);
    app.clear();
    app.draw(background);
    for(auto i:entities){
      i->update();
      if(i->name.compare("player") == 0){
        Player *player =(Player*) i;
        keyboardInputs(*player);

      }
      i->draw(app);
    }
    app.display();
  }
}

void gameStart(){
  RenderWindow app(VideoMode(APP_WIDTH,APP_HEIGHT), GAME_NAME);
  app.setFramerateLimit(60);

  std::list<Entity*> entities;
  Player *player = new Player();

  Texture playerTexture;
  playerTexture.loadFromFile(PLAYER_TEXTURE);
  Animation playerAnimation(playerTexture,80,80);

  player->settings(playerAnimation,APP_WIDTH/2,APP_HEIGHT/2, RIGHT);
  entities.push_back(player);

  Texture backgroundTexture;
  backgroundTexture.loadFromFile(BACKGROUND_TEXTURE);
  Sprite background(backgroundTexture);

  loop(app, entities, background);

}
