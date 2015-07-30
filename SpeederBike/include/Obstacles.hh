#ifndef OBSTACLES_HH
#define OBSTACLES_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Obstacles : public sf::Drawable, public sf::Transformable {

private:
  sf::Sprite ObstSprite1;
  sf::Texture ObstTexture1;

public:
  Obstacles();
  ~Obstacles();

  double ObstPosX, ObstPosY;

  void ObstTexture();
  void ObstPosition();

  void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif
