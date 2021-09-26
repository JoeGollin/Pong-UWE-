
#ifndef PONG_GAME_H
#define PONG_GAME_H

#include "Vector.h"
#include <SFML/Graphics.hpp>

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);
  void spawn();
  void score();

 private:
  bool collisionCheck(sf::Vector2i);
  sf::RenderWindow& window;
  sf::Font font;
  sf::Sprite ball;
  sf::Texture ball_texture;
  sf::Sprite red_paddle;
  sf::Sprite blue_paddle;
  sf::Texture red_paddle_texture;
  sf::Texture blue_paddle_texture;
  sf::Text red_score;
  sf::Text blue_score;
  sf::Text options_text;
  sf::Text blue_controls_text;
  sf::Text red_controls_text;
  sf::Text title_text;
  sf::Text winner_text_red;
  sf::Text winner_text_blue;
  int rscore = 0;
  int bscore = 0;
  int ballmx = 5;
  int ballmy = 5;

  bool in_menu;
  sf::Text menu_text;
};


#endif // PONG_GAME_H
