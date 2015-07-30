#include "../include/Obstacles.hh"
#include <stdlib.h>
#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>

Obstacles::Obstacles(){

  ObstPosX = 500.0;
  ObstPosY = 300.0;
}

Obstacles::~Obstacles(){;}

void Obstacles::ObstTexture(){
  if( !ObstTexture1.loadFromFile("figure/storm_trooper.jpg") ){
    std::cerr<<"-1"<<std::endl;
  }
  ObstSprite1.setTexture(ObstTexture1);
}

void Obstacles::ObstPosition()
{
  //srand(time(NULL));
  // ObstPosY = (rand()%50)+325;

  ObstSprite1.setPosition(ObstPosX,ObstPosY);
}

void Obstacles::draw(sf::RenderTarget& target, sf::RenderStates states ) const{
  target.draw(ObstSprite1);
}
	
