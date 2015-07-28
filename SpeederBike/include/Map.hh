#ifndef MAP_HH
#define MAP_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Map : public sf::Drawable, public sf::Transformable{

private:
  double MapSpeed;

public:
  Map(float, float);
  ~Map();
 float time;
  sf::Sprite MapSprite;
  sf::Texture MapTexture;
  std::vector<sf::Sprite> StoreMap;
  void update(float);
  void LoadMap();
  void MoveMap(float);
  void draw(sf::RenderTarget&, sf::RenderStates) const;

};
#endif
