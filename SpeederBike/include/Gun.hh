#ifndef GUN_HH
#define GUN_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "Player.hh"
class Player;

class Gun : public sf::Drawable, public sf::Transformable {
private:
  sf::RectangleShape laser;
  double laserY, counte, laser_counter;
  double laser_velocity;
  sf::SoundBuffer buffer;
  sf::Sound noise1;
  sf::Vector2f lasermove;
  sf::Clock clock;
  sf::Time time1;
  float timer;

  double ammo;
  bool NoAmmo;

public:
  Gun();
  ~Gun(){;}
  void updater();
  void laser_move();  
  void generatelaser(Player *ptr);
  void laser_sound();
  std::vector<sf::RectangleShape> LaserPosition(){ return store_laser;}
  void draw(sf::RenderTarget&, sf::RenderStates) const;
  void RemainingAmmo();

  sf::Vector2f laserPos();
  
  std::vector<sf::RectangleShape> store_laser;

  sf::Font font;
  sf::Text Ammo;
  std::string CurrentAmmo;

};
#endif 
