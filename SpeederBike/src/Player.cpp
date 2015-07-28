#include "../include/Player.hh"
#include <stdlib.h>
#include <iostream>

sf::Sprite speeder;
sf::Texture ptexture;


Player::Player() {
  m_moveX  = 10;
  m_moveY  = 10;
  m_positionlaser = 0.0;
  m_velocitylaser = 0.1;
  lowerbound.x = 75.0;
  lowerbound.y = 200.0;
  upperbound.x = 350.0;
  upperbound.y = 420.0;
 
}
Player::~Player() {;}

//Load texture
void Player::player_texture(){
  if( !ptexture.loadFromFile( "figures/speeder_Luke1.png") )
    {
      std::cout<<"File not found."<<std::endl;
    }
  speeder.setTexture(ptexture);   
}

//Draw sprite
void Player::draw( sf::RenderTarget& target, sf::RenderStates states ) const {
  target.draw(speeder);    
}

//Starting position of player
void Player::player_startpos(){
  speeder.setPosition(200,370);
}

//Movement
void Player::player_movement(){
  
  playerPos  = speeder.getPosition();

  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerPos.x>lowerbound.x)
    {
      speeder.move( -m_moveX, 0 );
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerPos.x<upperbound.x )
    {
      speeder.move( m_moveX, 0 );
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerPos.y>lowerbound.y )
    {
      speeder.move( 0, -m_moveY );
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && playerPos.y<upperbound.y )
    {
      speeder.move( 0, m_moveY );
    }
}

  
  

