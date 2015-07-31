#ifndef OBSTACLES_HH
#define OBSTACLES_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include "Gun.hh"

class Obstacles : public sf::Drawable, public sf::Transformable {

private:
  sf::Sprite ObstSprite1;
  sf::Texture ObstTexture1;


public:
  Obstacles();
  ~Obstacles();

  double ObstPosX, ObstPosY, ObstPosVx;
  double offscreen,RandomOffset;
  double dt;
double timer;
  bool Red, White;
  std::vector<sf::Sprite> StoreObst;
 

  void ObstPosition();
  void ObstMove();
  void ObstHit(Gun *ptr);
  void ObstColorChange();
  void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif
