#include "Gun.hh"
#include "Player.hh"
#include <stdlib.h>
#include <iostream>

sf::RectangleShape laser;
std::vector<laserPos> store_laser;

Gun::Gun() {
  double speederPosX = 0;
  double speederPosY = 0;}
Gun::~Gun() {;}

void Gun::generatelaser(){
  
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
    {
      sf::Vector2f offset(75.0,60.0);
      sf::Vector2f laserPos(0.0,0.0);

      laserPos.x = speederPosX + offset.x;
      laserPos.y = speederPosY + offset.y;

      laser.setSize(sf::Vector2f(100, 4));
      laser.setFillColor(sf::Color::Green);
      laser.setPosition(laserPos);
      store_laser.push_back(laser);
    }
}

void Gun::updater(){

  double laserY = lasermove.y;
  laser.move(0.1, 0);
 
  sf::Vector2f lasermove=laser.getPosition();
  laser.setPosition(lasermove.x, laserY);

}

void Gun::move(){

  for( int i=0; i<=store_laser.size(); i++ )
    {
      store_laser[i]->updater();
    }

}
  
//Draw Bullet
void Player::draw( sf::RenderTarget& target, sf::RenderStates states ) const {
 target.draw(laser);
}
