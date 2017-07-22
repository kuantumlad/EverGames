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
  SelectedItemIndex=0;

  if( !font.loadFromFile("fonts/STARWARS.TTF") );
  {
    std::cerr<<"Font file not found."<<std::endl;
  }
  
  menutitle.push_back("START");
  menutitle.push_back("OPTIONS");
  menutitle.push_back("EXIT");

  menuposX.push_back(230);
  menuposX.push_back(330);
  menuposX.push_back(485);
  
  // Menu Text
  title.setFont(font);
  title.setCharacterSize(40);
  title.setColor(sf::Color::Yellow);
  title.setString("ENDOR CHALLENGE");
  title.setPosition(195,195);

  MenuOptions[0].setFont(font);
  MenuOptions[0].setCharacterSize(20);
  MenuOptions[0].setColor(sf::Color::Red);
  MenuOptions[0].setString("START");//menutitle[0]);
  MenuOptions[0].setPosition(menuposX[0], m_startposY);

  MenuOptions[1].setFont(font);
  MenuOptions[1].setCharacterSize(20);
  MenuOptions[1].setColor(sf::Color::Yellow);
  MenuOptions[1].setString("OPTIONS");//menutitle[1]);
  MenuOptions[1].setPosition(menuposX[1], m_startposY);

  MenuOptions[2].setFont(font);
  MenuOptions[2].setCharacterSize(20);
  MenuOptions[2].setColor(sf::Color::Yellow);
  MenuOptions[2].setString("EXIT");
  MenuOptions[2].setPosition(menuposX[2], m_startposY);

}

Menu::~Menu() {;}

void Menu::load_menu_sounds(){
 if(!buffer.loadFromFile("sound/R2D2e.wav") )
    {
      std::cout<<"r2d2 File not found."<<std::endl;
    }
  ItemNoise.setBuffer(buffer);

 if(!MenuMusic.openFromFile("sound/SWopening.wav") )
    {
      std::cout<<"Opening Music File not found."<<std::endl;
    }


}

void Menu::PlayMenuMusic(){
  MenuMusic.play();
  MenuMusic.setLoop(true);
}

void Menu::StopMenuMusic(){
  MenuMusic.stop();
}

void Menu::SelectionSound(){
  ItemNoise.play();
}

/*void Menu::load_font(){
  sf::Font fontmenu;
  if( !fontmenu.loadFromFile("STARWARS.TTF") );
  {
    std::cerr<<"Font file not found."<<std::endl;
  }
  }*/

void Menu::MoveLeft(){
  if( SelectedItemIndex - 1 >=0 ){   
    MenuOptions[SelectedItemIndex].setColor(sf::Color::Yellow);
    SelectedItemIndex--;
    MenuOptions[SelectedItemIndex].setColor(sf::Color::Red);
  }
}

void Menu::MoveRight(){
  if( SelectedItemIndex + 1 < 3 ){   
    MenuOptions[SelectedItemIndex].setColor(sf::Color::Yellow);
    SelectedItemIndex++;
    MenuOptions[SelectedItemIndex].setColor(sf::Color::Red);
  }
}

void MenuOptions(){

}
  

void Menu::draw(sf::RenderTarget& target, sf::RenderStates states) const {
  target.draw(title);
  for( int i = 0; i<3; i++){
    target.draw(MenuOptions[i]);
  }
}

