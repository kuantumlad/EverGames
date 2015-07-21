#include "Gun.hh"
#include "Player.hh"
#include <stdlib.h>
#include <iostream>

// sf::RectangleShape laser;
// sf::Vector2f lasermove;
// double laserY;
// std::vector<sf::Vector2f> store_laser;

Gun::Gun() {
 
  laser_velocity=10.0;
  timer = 1/60.0;
  laser.setSize(sf::Vector2f(100, 4));
  laser.setFillColor(sf::Color::Green);
  laserY=0.0;
  sf::Vector2f lasermove(0.0,0.0);
 
}
//Gun::~Gun() {;}

void Gun::generatelaser(Player *ptr){
  sf::Vector2f speederPos = ptr->position();
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
    {
      time1 = clock.getElapsedTime();
      // timer = time1.asSeconds();
      if(timer>=0.1)
	{
	  sf::Vector2f offset(75.0,60.0);
	  sf::Vector2f laserPos(0.0,0.0);

	  laserPos.x = speederPos.x + offset.x;
	  laserPos.y = speederPos.y + offset.y;

	  laser.setPosition(laserPos);
	  store_laser.push_back(laser);
	}
     
      
      timer=clock.restart().asSeconds();

    }
      
     
}
      



// void Gun::updater(){

//   lasermove = laser.getPosition();
//   laserY = lasermove.y;

//   laser.setPosition(lasermove.x, laserY);
//   laser.move(laser_velocity, 0); 
  

// }

void Gun::laser_move(){

  for( std::vector<sf::RectangleShape>::iterator it = store_laser.begin(); it != store_laser.end(); ++it )
    {
      lasermove = (*it).getPosition();
      laserY = lasermove.y;

      (*it).setPosition(lasermove.x, laserY);
      (*it).move(laser_velocity, 0); 
   
    }

}
  
//Draw Bullet
void Gun::draw( sf::RenderTarget& target, sf::RenderStates states ) const {
  for( std::vector<sf::RectangleShape>::const_iterator it = store_laser.begin(); it != store_laser.end(); ++it )
    target.draw(*it);

}
