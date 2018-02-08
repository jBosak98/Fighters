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

void keyboardInputs(Player *player){
  if(player->name.compare("key") == 0){
    if(Keyboard::isKeyPressed(Keyboard::Right)) player->horizontalMotion = GOES_RIGHT;
    if(Keyboard::isKeyPressed(Keyboard::Left)) player->horizontalMotion = GOES_LEFT;
    if(Keyboard::isKeyPressed(Keyboard::Up)) player->verticalMotion = GOES_UP;
    if(Keyboard::isKeyPressed(Keyboard::Down)) player->verticalMotion = GOES_DOWN;
    if(Keyboard::isKeyPressed(Keyboard::Space)) player->operation = JUMP;
  } else if(player->name.compare("wasd") == 0){
    if(Keyboard::isKeyPressed(Keyboard::D)) player->horizontalMotion = GOES_RIGHT;
    if(Keyboard::isKeyPressed(Keyboard::A)) player->horizontalMotion = GOES_LEFT;
    if(Keyboard::isKeyPressed(Keyboard::W)) player->verticalMotion = GOES_UP;
    if(Keyboard::isKeyPressed(Keyboard::S)) player->verticalMotion = GOES_DOWN;
    if(Keyboard::isKeyPressed(Keyboard::X)) player->operation = JUMP;
  }
}



void loop(RenderWindow &app, std::list<Entity*> &entities, Sprite background){
  while (app.isOpen()) {
    isDesireToClose(app);
    app.clear();
    app.draw(background);
    for(auto i:entities){
      i->update();
      if(i->name.empty() == 0){
        keyboardInputs((Player*)i);
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
  Player *player = new Player("key");
  Player *anotherPlayer = new Player("wasd");

  Texture playerTexture;
  playerTexture.loadFromFile(PLAYER_TEXTURE);
  Animation playerAnimation(playerTexture,80,80);

  anotherPlayer->settings(playerAnimation,APP_WIDTH/3,APP_HEIGHT/2, RIGHT);
  player->settings(playerAnimation,APP_WIDTH/3*2,APP_HEIGHT/2, LEFT);
  entities.push_back(player);
  entities.push_back(anotherPlayer);

  Texture backgroundTexture;
  backgroundTexture.loadFromFile(BACKGROUND_TEXTURE);
  Sprite background(backgroundTexture);

  loop(app, entities, background);

}
