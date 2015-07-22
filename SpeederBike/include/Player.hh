#ifndef PLAYER_HH
#define PLAYER_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

extern double speederPosX;
extern double speederPosY;

class Player : public sf::Drawable, public sf::Transformable {

private:
  double m_moveX, m_moveY; 
  float m_positionlaser, m_velocitylaser;
  double playerPosX, playerPosY;
  sf::Vector2f playerPos;
  sf::Vector2f lowerbound;
  sf::Vector2f upperbound;
  
public:
  Player();
  ~Player();
 
  void player_texture();
  void player_startpos();
  void player_movement();
  sf::Vector2f position() {return speeder.getPosition(); }
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  
  sf::Sprite speeder;


};
#endif


