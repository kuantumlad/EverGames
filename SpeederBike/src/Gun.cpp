#include "../include/Gun.hh"
#include "../include/Player.hh"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>
#include <locale>


Gun::Gun() {
 
  laser_velocity=10.0;
  timer = 1/60.0;
  laser.setSize(sf::Vector2f(50, 4));
  laser.setFillColor(sf::Color(17,167,242,255));
  laserY=0.0;
  sf::Vector2f lasermove(0.0,0.0);

  ammo = 25;
  NoAmmo = false;

 if( !font.loadFromFile("fonts/STARWARS.TTF") );
  {
    std::cerr<<"Font file not found."<<std::endl;
  }

  Ammo.setFont(font);
  Ammo.setCharacterSize(25);
  Ammo.setColor(sf::Color(17,167,242,255));
  Ammo.setString("25");
  Ammo.setPosition(845,15);
}

void Gun::generatelaser(Player *ptr){
  sf::Vector2f speederPos = ptr->position();
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
    {
     
      time1 = clock.getElapsedTime();
      if(timer>=0.12 && ammo>0)
	{
	  noise1.play();
	  sf::Vector2f offset(115.0,105.0);
	  sf::Vector2f laserPos(0.0,0.0);

	  laserPos.x = speederPos.x + offset.x;
	  laserPos.y = speederPos.y + offset.y;

	  laser.setPosition(laserPos);
	  store_laser.push_back(laser);
	  ammo--;
	} 
      timer=clock.restart().asSeconds();
    }  
  else if ( ammo == 0)
    {
      ammo = 0;
    }
}
      

void Gun::laser_move(){
  for( std::vector<sf::RectangleShape>::iterator it = store_laser.begin(); it != store_laser.end(); ++it )
    {
      lasermove = (*it).getPosition();
      laserY = lasermove.y;
      (*it).setPosition(lasermove.x, laserY);
      (*it).move(laser_velocity, 0);  
    }
}
  
void Gun::laser_sound(){
 
  if(!buffer.loadFromFile("sound/LAZER.WAV") )
    {
      std::cout<<"File not found."<<std::endl;
    }
  noise1.setBuffer(buffer);
}

void Gun::RemainingAmmo(){
  std::string CurrentAmmo;
  std::ostringstream convert;
  convert << ammo;
  CurrentAmmo = convert.str();
  Ammo.setString(CurrentAmmo);
}
  


//Draw Bullet
void Gun::draw( sf::RenderTarget& target, sf::RenderStates states ) const {
  for( std::vector<sf::RectangleShape>::const_iterator it = store_laser.begin(); it != store_laser.end(); ++it ){
    target.draw(*it);}
  target.draw(Ammo);
}
