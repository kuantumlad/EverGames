#ifndef MENU_HH
#define MENU_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Menu : public sf::Drawable {

private: 
  int m_length, m_height;
  int m_startposX, m_startposY;

public:

  sf::RectangleShape Start;
  sf::Font font;
  sf::Text Startt;

  Menu();
  ~Menu();

  void load_font();
  void set_text();
  void start();
  void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif
