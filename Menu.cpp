#include "Menu.hh"
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

Menu::Menu() {
  m_nameX = 100;
  m_nameY = 50;
  m_nameposX = 200;
  m_nameposY = 100;

  m_startX = 100;
  m_startY = 50;
  m_startposX = 300;
  m_startposY = 100;
}

Menu::~Menu() {;}

void Menu::text() {

  font.loadFromFile("arial.ttf");

  //Name text
  namet.setFont(font);
  namet.setCharacterSize(30);
  namet.setStyle(sf::Text::Bold);
  namet.setColor(sf::Color::White);
  namet.setPosition( m_nameposX, m_nameposY );
  //Start Text
  startt.setFont(font);
  startt.setCharacterSize(30);
  startt.setStyle(sf::Text::Bold);
  startt.setColor(sf::Color::White);
  startt.setString("Start");
  startt.setPosition( m_nameposX, m_nameposY );
}


void Menu::name(){
  //Name properties
  Name.setSize( sf::Vector2f(m_nameX,m_nameY) );
  Name.setOutlineColor(sf::Color::Red);
  Name.setFillColor(sf::Color( 100, 0, 128 ));
  Name.setOutlineThickness( 2.5 );
  Name.setPosition( m_nameposX, m_nameposY ); 
}

void Menu::start(){
  //Start properties
  Start.setSize( sf::Vector2f(m_startX,m_startY) );
  Start.setOutlineColor(sf::Color::Red);
  Start.setFillColor(sf::Color( 100, 0, 128 ));
  Start.setOutlineThickness( 2.5 );
  Start.setPosition( m_startposX, m_startposY ); 
}

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(Name);
  target.draw(Start);
  target.draw(namet);
  target.draw(startt);
}
