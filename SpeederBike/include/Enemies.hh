#ifndef ENEMIES_HH
#define ENEMIES_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include "Gun.hh"

#include <vector>

class Enemies : public sf::Drawable, public sf::Transformable {

private:
  
  struct Enemy{
    sf::Sprite stormtrooper;
    sf::Texture stormtroopertexture;
    sf::Vector2f position;
    float vx, vy;
    float x, y;
    bool hit;
    int hitcount;
  };

  std::vector<Enemy> storeenemies;
  std::vector<Enemy>::iterator molit, bolit;

  float timer;

public:
  Enemies();
  ~Enemies(){;};

  void initializeEnemies();
  void updateEnemies();
  void addEnemies(sf::Sprite,float,float,bool);
  void hitEnemies();

  void draw(sf::RenderTarget&, sf::RenderStates) const;

};
#endif
