#include "../include/Menu.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>

Menu::Menu() {
  m_length = 100;
  m_height = 50;
  m_startposX = 0.0;
  m_startposY = 400.0;
  i=0;
  k=0;

  menuoptions.push_back("START");
  menuoptions.push_back("OPTIONS");
  menuoptions.push_back("EXIT");

  menuposX.push_back(250);
  menuposX.push_back(350);
  menuposX.push_back(495);
  
  // Menu Text
  title.setFont(font);
  title.setCharacterSize(40);
  title.setColor(sf::Color::Yellow);
  title.setString("ENDOR CHALLENGE");
  title.setPosition(200,200);

  start.setFont(font);
  start.setCharacterSize(20);
  start.setColor(sf::Color::Red);
  start.setString(menuoptions[0]);
  start.setPosition(menuposX[0], m_startposY);

  options.setFont(font);
  options.setCharacterSize(20);
  options.setColor(sf::Color::Yellow);
  options.setString(menuoptions[1]);
  options.setPosition(menuposX[1], m_startposY);

  exit.setFont(font);
  exit.setCharacterSize(20);
  exit.setColor(sf::Color::Yellow);
  exit.setString(menuoptions[2]);
  exit.setPosition(menuposX[2], m_startposY);

}


Menu::~Menu() {;}

void Menu::load_font(){

  if( !font.loadFromFile("fonts/STARWARS.TTF") );
  {
     std::cerr<<"Font file not found."<<std::endl;
  }
}




void Menu::menumove(){
  if( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ){   
    i=0;
    i++;
    if(i>0 && i<2){
      start.setFont(font);
      start.setCharacterSize(20);
      start.setColor(sf::Color::Yellow);
      start.setString(menuoptions[0]);
      start.setPosition(menuposX[0], m_startposY);

      options.setFont(font);
      options.setCharacterSize(20);
      options.setColor(sf::Color::Red);
      options.setString(menuoptions[1]);
      options.setPosition(menuposX[1], m_startposY);     
    }
    i=1; 
    i++;

    // else if( i == 2 )
    //   {
    // 	options.setFont(font);
    // 	options.setCharacterSize(20);
    // 	options.setColor(sf::Color::Yellow);
    // 	options.setString(menuoptions[0]);
    // 	options.setPosition(menuposX[0], m_startposY);

    // 	exit.setFont(font);
    // 	exit.setCharacterSize(20);
    // 	exit.setColor(sf::Color::Red);
    // 	exit.setString(menuoptions[1]);
    // 	exit.setPosition(menuposX[1], m_startposY);
    //   }

    std::cout<<"i = "<<i<<std::endl;
  }


  // if( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ){   
 //    j=0;   
 // j++;
 //    if(j>0 && j<2){
     
 //      start.setFont(font);
 //      start.setCharacterSize(20);
 //      start.setColor(sf::Color::Red);
 //      start.setString(menuoptions[0]);
 //      start.setPosition(menuposX[0], m_startposY);
     

 //      options.setFont(font);
 //      options.setCharacterSize(20);
 //      options.setColor(sf::Color::Yellow);
 //      options.setString(menuoptions[1]);
 //      options.setPosition(menuposX[1], m_startposY);
     
 //    }
 // j=1;
 //    std::cout<<"j = "<<j<<std::endl;
 //  }
  
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(title);
  target.draw(start);
  target.draw(options);
  target.draw(exit);
  }
