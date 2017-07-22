#ifndef MENU_HH
#define MENU_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


class Menu : public sf::Drawable {

public: 
  int m_length, m_height;
  int m_startposX, m_startposY;
  double offset; 
  sf::SoundBuffer buffer;
  sf::Music MenuMusic;
  sf::Sound ItemNoise;

  std::vector<std::string> menutitle;
  std::vector<sf::Text> menuitems;
  std::vector<double> menuposX;

public:
  sf::Font font;
  sf::RectangleShape button;
  sf::Text MenuOptions [3];
  sf::Text start, options, exit, title;
  int SelectedItemIndex;


  Menu();
  ~Menu();

  void load_font();
  void set_text();
  void MoveRight();
  void MoveLeft();
  void PlayMenuMusic();
  void StopMenuMusic();
  void SelectionSound();
  void load_menu_sounds();
  int GetPressedItem(){ return SelectedItemIndex;} 
  void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif
