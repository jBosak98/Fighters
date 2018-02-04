#include "main.h"
#include "values.h"
#include <list>




void createBackground(RenderWindow &app){
  Texture backgroundTexture;
  backgroundTexture.loadFromFile(BACKGROUND_TEXTURE);
  Sprite background(backgroundTexture);
  app.draw(background);
}
void isDesireToClose(RenderWindow &app){
  Event event;

  while(app.pollEvent(event)) {
    if((event.type == Event::Closed) ||
       (Keyboard::isKeyPressed(Keyboard::Escape)))
      app.close();

  }

}
void keyboardInputs(Player &player){
  if(Keyboard::isKeyPressed(Keyboard::Right)) player.actionPrimary = GOES_RIGHT;
  if(Keyboard::isKeyPressed(Keyboard::Left)) player.actionPrimary = GOES_LEFT;
  if(Keyboard::isKeyPressed(Keyboard::Up)) player.actionSecondary = GOES_UP;
  if(Keyboard::isKeyPressed(Keyboard::Down)) player.actionSecondary = GOES_DOWN;
}
void loop(RenderWindow &app, std::list<Entity*> &entities){
  while (app.isOpen()) {
    isDesireToClose(app);


    app.clear();
    createBackground(app);

    for(auto i:entities){
      if(i->name.compare("player") == 0){
        Player *player =(Player*) i;
        keyboardInputs(*player);
      }
      i->update();
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
  entities.push_back(player);

  player->x = APP_WIDTH/2;
  player->y = APP_HEIGHT/2;

  loop(app, entities);

}
