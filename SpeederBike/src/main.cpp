//****************************************//
//                                        // 
//    Brandon Clary's SpeederBike Game    //
//               7/22/2015                //
//              version 0.1               //
//                                        //
//****************************************//  


#include "../include/Player.hh"
#include "../include/Gun.hh"
#include "../include/Menu.hh"
#include "../include/Starmap.hh"

#include <SFML/Graphics.hpp>


int main()
{
    // create the window
    sf::RenderWindow window(sf::VideoMode(800, 600), "Game");
    window.setFramerateLimit(60);

    Player speeder1;
    Gun laser;
    Starmap stars;
    stars.init_star();
    Menu menu;

   
    speeder1.player_texture();
    laser.laser_sound();
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

	laser.generatelaser(&speeder1);
	laser.laser_move();
	
window.draw(menu);
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
	//	window.draw(stars);
	
	//window.draw(speeder1);
	//	window.draw(laser);
      	// end the current frame
        window.display();
	//	stars.update();
    }
    return 0;
}
