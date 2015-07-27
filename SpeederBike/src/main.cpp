//****************************************//
//                                        // 
//    Brandon Clary's SpeederBike Game    //
//               7/22/2015                //
//              version 1.0.2             //
//                                        //
//****************************************//  


#include "../include/Player.hh"
#include "../include/Gun.hh"
#include "../include/Menu.hh"
#include "../include/Starmap.hh"

#include <SFML/Graphics.hpp>
#include <iostream>

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

    menu.load_font();
   
    speeder1.player_texture();
    laser.laser_sound();
    menu.load_menu_sounds();
    speeder1.player_startpos();
    //menu.set_text();
    menu.MenuSound();

    // run the program as long as the window is open
    while (window.isOpen())
    {
        // check all the window's events that were triggered since the last iteration of the loop
      sf::Event event;
      while (window.pollEvent(event))
        {
            // "close requested" event: we close the window
	  // if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	  // window.close();

	  switch(event.type)
	    {
	    case sf::Event::KeyReleased:
	      switch ( event.key.code)
		{
		case sf::Keyboard::Left:
		  menu.MoveLeft();
		  break;

		case sf::Keyboard::Right:
		  menu.MoveRight();
		  break;

		case sf::Keyboard::Return:
		  switch( menu.GetPressedItem() )
		    {
		    case 0:
		      std::cout<<"Start button has been pressed"<<std::endl;
		      break;
		    case 1:
		      std::cout<<"Options button has been pressed"<<std::endl;
		      break;
		    case 2:
		      std::cout<<"Exit button has been pressed"<<std::endl;
		      window.close();
		      break;
		    }
		}
	      
	      break;
	    case sf::Event::Closed:
	      window.close();
	      
	      break;

	    }
	

	


      
	speeder1.player_movement();

	laser.generatelaser(&speeder1);
	laser.laser_move();
	
        // clear the window with black color
        window.clear(sf::Color::Black);

        // draw everything here...
	//	window.draw(stars);
	window.draw(menu);

	//window.draw(speeder1);
	//	window.draw(laser);
      	// end the current frame
        window.display();
	//	stars.update();
	}
    }
    return 0;
}
