#ifndef GUN_HH
#define GUN_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Player.hh"

class Gun : public sf::Drawable, public sf::Transformable {

public:
  Gun();
  ~Gun();
  void updater();
  void move();  
  void generatelaser();
  void draw(sf::RenderTarget&, sf::RenderStates) const;

  sf::Vector2f laserPos();


};
#endif 
