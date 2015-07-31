#ifndef PLAYER_HH
#define PLAYER_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

extern double speederPosX;
extern double speederPosY;

class Player : public sf::Drawable, public sf::Transformable {

private:
  double m_moveX, m_moveY; 
  float gravity;
  double Speed;
  double Yknot, Yfinal;
  float m_positionlaser, m_velocitylaser;
  double playerPosX, playerPosY;
  sf::Vector2f playerPos;
  sf::Vector2f lowerbound;
  sf::Vector2f upperbound;
  sf::Clock clock;
  sf::SoundBuffer buffer2;
  sf::Sound SpeederBikeRight;
  bool whileJump;
  double dt;
  
public:
  Player();
  ~Player();
 
  void player_moveSound();
  void player_texture();
  void player_startpos();
  void player_movement();
  void JumpEquation(float);
  void Jump();
  void Health();
  void Shield();
  sf::Vector2f position() {return speeder.getPosition(); }
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  
  sf::Sprite speeder;

  sf::RectangleShape healthbar;
  sf::RectangleShape shieldbar;

};
#endif


