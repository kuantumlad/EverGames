#include "Player.hh"
#include <stdlib.h>
#include <iostream>

sf::Sprite speeder;
//sf::RectangleShape laser;
sf::Texture ptexture;


Player::Player() {
  m_moveX  = 10;
  m_moveY  = 10;
  m_positionlaser = 0.0;
  m_velocitylaser = 0.1;
  // speederPosX = 0.0;
  // speederPosY = 0.0;
 
}
Player::~Player() {;}

//Load texture
void Player::player_texture(){
  if( !ptexture.loadFromFile( "speeder_Luke1.png") )
    {
      std::cout<<"File not found."<<std::endl;
    }
  speeder.setTexture(ptexture);   
}

//Draw sprite
void Player::draw( sf::RenderTarget& target, sf::RenderStates states ) const {
  target.draw(speeder);
  //  target.draw(laser);
    
}

//Starting position of player
void Player::player_startpos(){
  speeder.setPosition(350,520);
}

//Movement
void Player::player_movement(){

  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) )
    {
      speeder.move( -m_moveX, 0 );
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) )
    {
      speeder.move( m_moveX, 0 );
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) )
    {
      speeder.move( 0, -m_moveY );
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) )
    {
      speeder.move( 0, m_moveY );
    }
}

sf::Vector2f Player::player_position(){  //removed player_ from class function,add sf
  sf::Vector2f speederPos = speeder.getPosition();
  //  speederPosX = speederPos.x;
  // speederPosY = speederPos.y;
  return speederPos;
}


//  double laserY = lasermove.y;
//  laser.move(0.1, 0);
 
//  sf::Vector2f lasermove=laser.getPosition();
//  laser.setPosition(lasermove.x, laserY);
//}

// void Player::gun(){

//   if( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) )
//     {
      
//       sf::Vector2f speederPos = speeder.getPosition();
//       sf::Vector2f offset(75.0,60.0);
//       sf::Vector2f laserPos(0.0,0.0);

//       laserPos.x = speederPos.x + offset.x;
//       laserPos.y = speederPos.y + offset.y;

//       laser.setSize(sf::Vector2f(100, 4));
//       laser.setFillColor(sf::Color::Green);
//       laser.setPosition(laserPos);

//     }
// }
