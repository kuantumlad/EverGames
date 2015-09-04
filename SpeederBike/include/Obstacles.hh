#ifndef OBSTACLES_HH
#define OBSTACLES_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <stdlib.h>
#include "Gun.hh"

class Obstacles : public sf::Drawable, public sf::Transformable {

private:
 

  struct Enemies{
    sf::Sprite stormtrooper;
    sf::Vector2f position;
    float Vx, Vy;
    bool hit;
    int hitcount;
  };

  // Store Enemies stormtroopers (ST)
  std::vector<Enemies> storeEnemies;
  std::vector<Enemies>::iterator molit, bolit;

  float timer;
  int hitcount;
    


public:
  Obstacles();
  ~Obstacles();

  sf::Sprite ObstSprite1;
  sf::Texture ObstTexture1;

  void initializeEnemies();
  void updateEnemies();
  void EnemiesAdd(sf::Sprite,float,float,bool);
  void HitEnemies();

  double ObstPosX, ObstPosY, ObstPosVx;
  double offscreen,RandomOffset;
  double dt;
  bool Red, White;
  std::vector<sf::Sprite> StoreObst;
 
  




  void ObstPosition();
  void ObstMove();
  void ObstHit(Gun *ptr, sf::Time);
  void ObstColorChange();
  void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif
