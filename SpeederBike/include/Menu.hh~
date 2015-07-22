#ifndef MENU_HH
#define MENU_HH

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class Menu : public sf::Drawable {

private: 
int m_nameX, m_nameY, m_startX, m_startY;
int m_nameposX, m_nameposY, m_startposX, m_startposY;

public:

sf::RectangleShape Name;
sf::RectangleShape Start;
sf::Font font;
sf::Text namet;
sf::Text startt;

Menu();
~Menu();

void text();
void name();
void start();
void butt_pressed();
void draw(sf::RenderTarget&, sf::RenderStates) const;

};

#endif
