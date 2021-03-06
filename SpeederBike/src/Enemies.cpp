#include "../include/Enemies.hh"
#include "../include/Gun.hh"

#include <iostream>
#include <cmath>
#include <time.h>
#include <stdio.h>


Enemies::Enemies(){

  for( int i = 0; i < 2; i++ ){
    struct Enemy atrooper;
    sf::Texture trooptex;
    if( !trooptex.loadFromFile("/home/brandon/Documents/projects/sfml/EverGames/SpeederBike/figures/enemy2.png") ){
      std::cerr<<"-1"<<std::endl;
    }
    atrooper.stormtrooper.setTexture(trooptex);
    atrooper.x = (rand()%100) + 250;
    atrooper.y = (rand()%10) + 350;
    sf::Vector2f pos(atrooper.x,atrooper.y);
    atrooper.hit = false;
    atrooper.hit = 0;
    atrooper.stormtrooper.setPosition(pos);
    storeenemies.push_back(atrooper);

  }

}

void Enemies::initializeEnemies(){

  /*
  for( int i = 0; i < 2; i++ ){
    struct Enemy atrooper;
    sf::Texture trooptex;
    if( !trooptex.loadFromFile("/home/brandon/Documents/projects/sfml/EverGames/SpeederBike/figures/enemy2.png") ){
      std::cerr<<"-1"<<std::endl;
    }
    atrooper.stormtrooper.setTexture(trooptex);
    atrooper.x = (rand()%100) + 250;
    atrooper.y = (rand()%10) + 350;
    sf::Vector2f pos(atrooper.x,atrooper.y);
    atrooper.hit = false;
    atrooper.hit = 0;
    atrooper.stormtrooper.setPosition(pos);
    storeenemies.push_back(atrooper);

    }*/
}

void Enemies::draw(sf::RenderTarget& target, sf::RenderStates states ) const{
  for( std::vector<Enemy>::const_iterator it = storeenemies.begin(); it != storeenemies.end(); ++it ){
    target.draw((*it).stormtrooper);
    //    std::cout << (*it).stormtrooper.getPosition().x << std::endl;
  }
}
