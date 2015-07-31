#include "../include/Obstacles.hh"
#include "../include/Gun.hh"
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>

Obstacles::Obstacles(){

  ObstPosX = 600.0;
  ObstPosVx = 5;
  offscreen = 50.0;
  dt = 0;
  timer = 1;

  Red = false;
  White = false;

  if( !ObstTexture1.loadFromFile("figures/StormTrooper1.png") ){
    std::cerr<<"-1"<<std::endl;
  }
  ObstSprite1.setTexture(ObstTexture1);
 
  //ObstSprite1.setPosition(ObstPosX,0);

  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);

  sf::FloatRect LaserRect(0,0,0,0);
  sf::Vector2f LaserRectPos(0.0,0.0);

}

Obstacles::~Obstacles(){;}

void Obstacles::ObstPosition()
{
  srand(time(NULL));
  ObstPosY = (rand()%50)+325;
  RandomOffset = (rand()%30)+15;
}


void Obstacles::ObstMove(){
  dt++;
  srand(time(NULL));
  ObstPosY = (rand()%50)+325;
  RandomOffset = (rand()%30)+15;
  for(std::vector<sf::Sprite>::iterator it = StoreObst.begin(); it != StoreObst.end(); ++it)
    {
      (*it).setPosition(ObstPosX-ObstPosVx*dt, ObstPosY );
      if( (*it).getPosition().x <= -offscreen ){
	(*it).setPosition(875+RandomOffset, 100 );
	dt=0;
      }
    }
}


void Obstacles::ObstHit(Gun *ptr){
  std::vector<sf::RectangleShape> laserHolder = ptr->LaserPosition();
  for(std::vector<sf::RectangleShape>::iterator it = laserHolder.begin(); it != laserHolder.end(); ++it)
    {
      sf::Vector2f LaserRectPos = (*it).getPosition();

      sf::Rect<float> LaserRect( LaserRectPos.x, LaserRectPos.y, 50.0, 4.0 );
      for(std::vector<sf::Sprite>::iterator it2 = StoreObst.begin(); it2 != StoreObst.end(); ++it2)
	{
	  sf::Rect<float> ObstRect( (*it2).getPosition().x, (*it2).getPosition().y, 50.0, 50.0 );

	  if( LaserRect.intersects(ObstRect) )
	    {
	      Red=true;
	      while( timer <= 200.0){
		if(Red){
		std::cout<<"herer"<<std::endl;

		  (*it2).setColor(sf::Color::Red);
		  White = true;
		}
	        if(White){
		  (*it2).setColor(sf::Color::White);
		}
		timer++;
	      }
	    }
	}
    }
}
	
	
	
    

void Obstacles::draw(sf::RenderTarget& target, sf::RenderStates states ) const{
  for( std::vector<sf::Sprite>::const_iterator it = StoreObst.begin(); it != StoreObst.end(); ++it )
    target.draw(*it);
}
	
