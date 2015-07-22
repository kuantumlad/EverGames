#include "Player.hh"
#include "Gun.hh"
#include "Menu.hh"
#include "Starmap.hh"

#include <SFML/Graphics.hpp>


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
    window.setFramerateLimit(60);

    Player speeder1;
    Gun laser;
    Starmap Stars;
    Stars.init_star();
    // Menu Buttons;

    speeder1.player_texture();
    speeder1.player_startpos();
    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
        sf::Event event;
        while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
	  if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    window.close();
        }

	speeder1.player_movement();
	laser.laser_sound();
	laser.generatelaser(&speeder1);
	laser.laser_move();
	

        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
	window.draw(Stars);
	window.draw(speeder1);
	window.draw(laser);
	//window.draw(Buttons);
	// end the current frame
        window.display();
	Stars.update();
    }
    return 0;
}
