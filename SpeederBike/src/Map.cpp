#include "../include/Map.hh"
#include <stdlib.h>
#include <iostream>


Map::Map(float DisplayX, float DisplayY){

  MapSpeed = 5;
  if( !MapTexture.loadFromFile( "figures/forestbackground.png") )
    {
      std::cout<<"File not found."<<std::endl;
    }
  MapSprite.setTexture(MapTexture);
  
  MapSprite.setPosition(0,0);
  StoreMap.push_back(MapSprite);
  MapSprite.setPosition(DisplayX*1.0, 0);
  StoreMap.push_back(MapSprite);
  MapSprite.setPosition(DisplayX*2.0, 0);
  StoreMap.push_back(MapSprite);  
  // std::cout<<StoreMap[2].getPosition().x<<std::endl;
}
 
Map::~Map(){;}

// Load Map Texture
//void Map::LoadMap(){
//
//}

// Move Map
void Map::MoveMap(float time){
  // MapSprite.setPosition(-MapSpeed*time, 0 );
  // sf::Vector2f MapPosition = MapSprite.getPosition();
  // double MapPositionX = MapPosition.x;
  // if( MapPositionX ==-880.0 )
  //   {
  //     StoreMap.push_back(MapSprite);
  //   }
}


void Map::update(float time){
  for(std::vector<sf::Sprite>::iterator it = StoreMap.begin(); it != StoreMap.end(); ++it ) 
    {
      (*it).move(-MapSpeed, 0 );
      if( (*it).getPosition().x <= -880.0 ){
	(*it).setPosition(880,0);
      }      
    }

}


// Draw Map
void Map::draw( sf::RenderTarget& target, sf::RenderStates states ) const{
  for( std::vector<sf::Sprite>::const_iterator it = StoreMap.begin(); it != StoreMap.end(); ++it )
    target.draw(*it);
}
