#include "../include/Player.hh"
#include <stdlib.h>
#include <iostream>
#include <cmath>

sf::Sprite speeder;
sf::Texture ptexture;


Player::Player() {
  m_moveX  = 7;
  m_moveY  = 7;
  m_positionlaser = 0.0;
  m_velocitylaser = 0.1;
  lowerbound.x = 5.0;
  lowerbound.y = 200.0;
  upperbound.x = 450.0;
  upperbound.y = 375.0;
  gravity = 3*9.8;
  whileJump = false;
  Speed = 10.0;
  dt = 1/60.0;
}
Player::~Player() {;}

//Load texture
void Player::player_texture(){
  if( !ptexture.loadFromFile( "figures/speeder_Luke3.png") )
    {
      std::cout<<"File not found."<<std::endl;
    }
  speeder.setTexture(ptexture);   
}

//Draw sprite
void Player::draw( sf::RenderTarget& target, sf::RenderStates states ) const {
  target.draw(speeder);    
}

void Player::player_moveSound(){
  if(!buffer2.loadFromFile("sound/anakin_pod_thrusters.wav") )
    {
      std::cout<<"File not found."<<std::endl;
    }
    SpeederBikeRight.setBuffer(buffer2);
}

//Starting position of player
void Player::player_startpos(){
  speeder.setPosition(200,370.0);
}

// Apply gravity
void Player::JumpEquation(float time){
  Yknot = playerPos.y;
  speeder.move(0,-gravity*dt);
}

// Jump
void Player::Jump(){
      if(whileJump){
	Yknot = playerPos.y;
	Speed+=gravity*dt;
	speeder.move(0,Speed);
	if(speeder.getPosition().y >= upperbound.y){
	  speeder.setPosition(speeder.getPosition().x, upperbound.y );
	  Speed=10.0;
	  whileJump = false;}
      }
}


//Movement
void Player::player_movement(){
  playerPos = speeder.getPosition();
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && playerPos.x>lowerbound.x)
    {
      speeder.move( -m_moveX, 0 );
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && playerPos.x<upperbound.x )
    {
      speeder.move( m_moveX, 0 );
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && playerPos.y>lowerbound.y && !whileJump )
    {
      whileJump = true;
      Speed = -Speed;     
    }
  else if( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && playerPos.y<upperbound.y )
    {
      speeder.move( 0, m_moveY );
    }
}

  
  

