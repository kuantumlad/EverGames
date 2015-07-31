#include "../include/Obstacles.hh"
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>

Obstacles::Obstacles(){

  ObstPosX = 500.0;
  ObstPosVx = 5;
  offscreen = 50.0;
  dt = 0;

  if( !ObstTexture1.loadFromFile("figures/StormTrooper1.png") ){
    std::cerr<<"-1"<<std::endl;
  }
  ObstSprite1.setTexture(ObstTexture1);
 
  ObstSprite1.setPosition(ObstPosX,0);

  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
  StoreObst.push_back(ObstSprite1);
}

Obstacles::~Obstacles(){;}

// void Obstacles::ObstTexture(){
//   if( !ObstTexture1.loadFromFile("figures/StormTrooper1.png") ){
//     std::cerr<<"-1"<<std::endl;
//   }
//   ObstSprite1.setTexture(ObstTexture1);
// }

void Obstacles::ObstPosition()
{
  srand(time(NULL));
  ObstPosY = (rand()%50)+325;
  RandomOffset = (rand()%30)+15;
  // ObstSprite1.setPosition(ObstPosX,ObstPosY);
}


void Obstacles::ObstMove(){
  dt++;
  srand(time(NULL));
  ObstPosY = (rand()%50)+325;
  RandomOffset = (rand()%30)+15;
  for(std::vector<sf::Sprite>::iterator it = StoreObst.begin(); it != StoreObst.end(); ++it)
    {
      (*it).setPosition(500-ObstPosVx*dt, ObstPosY );
      if( (*it).getPosition().x <= -offscreen ){
	(*it).setPosition(875+RandomOffset, 100 );
	dt=0;

      }
    }
}


void Obstacles::draw(sf::RenderTarget& target, sf::RenderStates states ) const{
  for( std::vector<sf::Sprite>::const_iterator it = StoreObst.begin(); it != StoreObst.end(); ++it )
    target.draw(*it);
}
	
