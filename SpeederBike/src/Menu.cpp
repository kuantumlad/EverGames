#include "../include/Menu.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Menu::Menu() {
  m_length = 100;
  m_height = 50;
  m_startposX = 300;
  m_startposY = 100;
}

Menu::~Menu() {;}

void Menu::load_font(){

  if( !font.loadFromFile("fonts/Starjedi.ttf") );
  {
    // std::cout<<"Font file not found."<<std::endl;
  }
  //font.loadFromFile("../fonts/Starjedi.ttf");
}

void Menu::set_text(){
  //Start Text
  Startt.setFont(font);
  Startt.setCharacterSize(30);
  Startt.setColor(sf::Color::Yellow);
  Startt.setString("Start");
  Startt.setPosition( m_startposX, m_startposY );
}


void Menu::start(){
  //Start properties
  Start.setSize( sf::Vector2f(m_length,m_height) );
  Start.setOutlineColor(sf::Color::Yellow);
  Start.setFillColor(sf::Color::Yellow);
  Start.setOutlineThickness( 2.5 );
  Start.setPosition( m_startposX, m_startposY ); 
}


void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(Start);
  target.draw(Startt);
}
