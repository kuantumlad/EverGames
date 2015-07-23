#ifndef MENU_HH
#define MENU_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Menu : public sf::Drawable {

private: 
  int m_length, m_height;
  int m_startposX, m_startposY;
  int i,j,k;
  double offset; 
  std::vector<std::string> menuoptions;
  std::vector<sf::Text> menuitems;
  std::vector<double> menuposX;

public:

  sf::RectangleShape button;
  sf::Font font;
  sf::Text start, options, exit, title;

  Menu();
  ~Menu();

  void load_font();
  void set_text();
  void menumove();
  void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif
