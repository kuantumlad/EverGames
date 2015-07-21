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
 

public:
  Player();
  ~Player();

 

  void player_texture();
  void player_startpos();
  void player_movement();
  void player_position();
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  
  sf::Sprite speeder;


};
#endif


