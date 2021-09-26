
#include "Game.h"
#include "Vector.h"
#include <iostream>


Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
  in_menu = true;

  if (!font.loadFromFile("Data/Fonts/OpenSans-Bold.ttf"))
  {
    std::cout << "Font did not load \n";
  }
  title_text.setString("Pong.");
  title_text.setFont(font);
  title_text.setCharacterSize(40);
  title_text.setFillColor(sf::Color(255, 255, 0));
  title_text.setPosition(10, 10);

  menu_text.setString("[Enter] - Start the game\n[Esc] - Quit");
  menu_text.setFont(font);
  menu_text.setCharacterSize(20);
  menu_text.setFillColor(sf::Color(255,0,0,128));
  menu_text.setPosition(10, 60);

  if (!red_paddle_texture.loadFromFile("Data/Images/paddleRed.png"))
  {
    std::cout << "red paddle texture did not load" << std::endl;
  }
  red_paddle.setTexture(red_paddle_texture);
  red_paddle.setPosition(1060, 300);
  red_paddle.rotate(90);

  if (!blue_paddle_texture.loadFromFile("Data/Images/paddleBlue.png"))
  {
    std::cout << "red paddle texture did not load" << std::endl;
  }
  blue_paddle.setTexture(blue_paddle_texture);
  blue_paddle.setPosition(40, 300);
  blue_paddle.rotate(90);

  if (!ball_texture.loadFromFile("Data/Images/ballBlue.png"))
  {
    std::cout << "ball texture did not load " << std::endl;
  }
  ball.setTexture(ball_texture);
  ball.setPosition(
    window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
    window.getSize().y / 2 - menu_text.getGlobalBounds().height / 2);

  blue_score.setString(std::to_string(bscore));
  blue_score.setFont(font);
  blue_score.setCharacterSize(500);
  blue_score.setFillColor(sf::Color(50, 50, 50));
  blue_score.setPosition(60, 30);

  red_score.setString(std::to_string(rscore));
  red_score.setFont(font);
  red_score.setCharacterSize(500);
  red_score.setFillColor(sf::Color(50, 50, 50));
  red_score.setPosition(740, 30);

  options_text.setString("[Esc] to Exit");
  options_text.setFont(font);
  options_text.setCharacterSize(15);
  options_text.setFillColor(sf::Color(255, 251, 0));
  options_text.setPosition(window.getSize().x / 2 - options_text.getGlobalBounds().width / 2, 700);

  blue_controls_text.setString("Blue Player uses 'W' and 'S' to move the paddle");
  blue_controls_text.setFont(font);
  blue_controls_text.setCharacterSize(15);
  blue_controls_text.setFillColor(sf::Color(255, 251, 0));
  blue_controls_text.setPosition(5, 700);

  red_controls_text.setString("Red Player uses 'Up' and 'Down' to move the paddle");
  red_controls_text.setFont(font);
  red_controls_text.setCharacterSize(15);
  red_controls_text.setFillColor(sf::Color(255, 251, 0));
  red_controls_text.setPosition(680, 700);

  winner_text_red.setString("Red player wins!");
  winner_text_red.setFont(font);
  winner_text_red.setCharacterSize(40);
  winner_text_red.setFillColor(sf::Color(255,0,0));
  winner_text_red.setPosition(350,300);

  winner_text_blue.setString("Blue player wins!");
  winner_text_blue.setFont(font);
  winner_text_blue.setCharacterSize(40);
  winner_text_blue.setFillColor(sf::Color(0,236,255));
  winner_text_blue.setPosition(350,300);

  return true;
}

void Game::update(float dt)
{
  score();
  ball.move(ballmx,ballmy);
  // Ball bounces at top of screen
  if (ball.getPosition().y < 0)
  {
    ballmy = -ballmy;
  }
  // Ball Bounces at bottom of screen
  if (ball.getPosition().y > 715)
  {
    ballmy = -ballmy;
  }
  // Ball collides with blue paddle
  if (blue_paddle.getGlobalBounds().intersects(ball.getGlobalBounds()))
  {
    ballmx = -ballmx;
  }
  //Ball collides with red paddle
  if (red_paddle.getGlobalBounds().intersects(ball.getGlobalBounds()))
  {
    ballmx = -ballmx;
  }

}

void Game::render()
{

  if (in_menu)
  {
    window.draw(title_text);
    window.draw(menu_text);
    if (rscore == 5)
    {
      window.draw(winner_text_red);
    }
    else if (bscore == 5)
    {
      window.draw(winner_text_blue);
    }
  }
  else
  {
    window.draw(blue_score);
    window.draw(red_score);
    window.draw(ball);
    window.draw(blue_paddle);
    window.draw(red_paddle);
    window.draw(options_text);
    window.draw(blue_controls_text);
    window.draw(red_controls_text);

    if (rscore >= 5 or bscore >= 5)
    {
      score();
    }
    else
    {
      in_menu = false;
    }

  }
}

bool Game::collisionCheck(sf::Vector2i)
{

  return false;
}


void Game::keyPressed(sf::Event event)
{
  if (event.key.code == sf::Keyboard::Enter)
  {
    rscore = 0;
    bscore = 0;
    red_score.setString(std::to_string(rscore));
    blue_score.setString(std::to_string(bscore));
    in_menu = false;
    spawn();
  }
  else if (event.key.code == sf::Keyboard::Escape)
  {
    window.close();
  }

  if (event.key.code == sf::Keyboard::Up) // Move Red Paddle Up (Right Side)
  {
    if ((red_paddle.getPosition().y > (window.getSize().y - red_paddle.getGlobalBounds().height)) ||
        (red_paddle.getPosition().y < 0)) // If Paddle Hits Top Of Window
    {
      red_paddle.setPosition(1060, 600);
    }
    else
    {
      red_paddle.move(+0, -30);
    }
  }
  if (event.key.code == sf::Keyboard::Down) // Move Red Paddle Down (Right Side)
  {
    if ((red_paddle.getPosition().y > (window.getSize().y - red_paddle.getGlobalBounds().height)) ||
        (red_paddle.getPosition().y < 0)) // If Paddle Hits Top Of Window
    {
      red_paddle.setPosition(1060, 0);
    }
    else
    {
      red_paddle.move(+0, +30);
    }
  }
  if (event.key.code == sf::Keyboard::W) // Move Blue Paddle Up (Left Side)
  {
    if ((blue_paddle.getPosition().y > (window.getSize().y - blue_paddle.getGlobalBounds().height)) ||
        (blue_paddle.getPosition().y < 0)) // If Paddle Hits Top Of Window
    {
      blue_paddle.setPosition(40, 600);
    }
    else
    {
      blue_paddle.move(+0, -30);
    }
  }
  if (event.key.code == sf::Keyboard::S) // Move Blue Paddle Down (Left Side)
  {
    if ((blue_paddle.getPosition().y > (window.getSize().y - blue_paddle.getGlobalBounds().height)) ||
        (blue_paddle.getPosition().y < 0)) // If Paddle Hits Bottom of Window
    {
      blue_paddle.setPosition(40, 0);
    }
    else
    {
      blue_paddle.move(+0, +30);
    }

  }
}

void Game::spawn()
{
  // Spawn ball after score
  ball.setPosition(
    window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2,
    window.getSize().y / 2 - menu_text.getGlobalBounds().height / 2);
}

void Game::score()
{
  // Ball goes off left side of screen
  if (ball.getPosition().x < 5)
  {
    rscore += 1;
    red_score.setString(std::to_string(rscore));
    spawn();

  }
  //Ball goes off right side of screen
  if (ball.getPosition().x  > 1060)
  {
    bscore += 1;
    blue_score.setString(std::to_string(bscore));
    spawn();
  }

  if (rscore == 5)
  {
    in_menu = true; // back to menu
  }
  else if (bscore == 5)
  {
    in_menu = true; // back to menu
  }
}

void Game::mouseClicked(sf::Event event) // Unused
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);
}