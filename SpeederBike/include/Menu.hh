#ifndef MENU_HH
#define MENU_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Menu : public sf::Drawable {

private: 
  int m_length, m_height;
  int m_startposX, m_startposY;
  double offset; 
  sf::SoundBuffer buffer;//, buffer1;
  sf::Sound MenuMusic;
  sf::Sound ItemNoise;

  std::vector<std::string> menutitle;
  std::vector<sf::Text> menuitems;
  std::vector<double> menuposX;

public:

  sf::RectangleShape button;
  sf::Font font;
  sf::Text MenuOptions [3];
  sf::Text start, options, exit, title;
  bool key, Start, Options, Exit;
  int SelectedItemIndex;


  Menu();
  ~Menu();

  void load_font();
  void set_text();
  void MoveRight();
  void MoveLeft();
  void MenuSound();
  void load_menu_sounds();
  int GetPressedItem(){ return SelectedItemIndex;} 
  void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif
