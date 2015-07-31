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
#include "../include/Map.hh"
#include "../include/Obstacles.hh"

#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{

  const float FPS = 60.0f;
  bool redraw = true;
  float time;

  // create the window
  sf::RenderWindow window(sf::VideoMode(880, 575), "Game");
  sf::Clock clock;
  window.setFramerateLimit(60);

  Player speeder1;
  Gun laser;
  Obstacles StormTrooper;
  Starmap stars;
  stars.init_star();
  Menu menu;
  Map forest( window.getSize().x, window.getSize().y );

  menu.load_font();
  speeder1.player_texture();
  speeder1.player_moveSound();
  laser.laser_sound();
  menu.load_menu_sounds();
  speeder1.player_startpos();
  // menu.PlayMenuMusic();
  bool firsttry = true;

  // run the program as long as the window is open
  while (window.isOpen())
    {
      // check all the window's events that were triggered since the last iteration of the loop

     
      sf::Event event;
     
      if( clock.getElapsedTime().asSeconds() >= 1.0f/FPS)
	{
	  redraw = true;
	}

      while (window.pollEvent(event))
        {
	  // "close requested" event: we close the window
	  if (event.type == sf::Event::Closed || sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    window.close();
	 
      // 	  if(firsttry)
      // 	    {
      // 	      switch(event.type)
      // 		{
      // 		case sf::Event::KeyReleased:
      // 		  switch ( event.key.code)
      // 		    {
      // 		    case sf::Keyboard::Left:
      // 		      menu.MoveLeft();
      // 		      break;

      // 		    case sf::Keyboard::Right:
      // 		      menu.MoveRight();
      // 		      break;

      // 		    case sf::Keyboard::Return:
		 
      // 		      switch( menu.GetPressedItem() )
      // 			{
      // 			case 0:
      // 			  std::cout<<"Start button has been pressed"<<std::endl;
      // 			  firsttry = false;
      // 			  menu.StopMenuMusic();
      // 			  menu.SelectionSound();
      // 			  clock.restart();
      // 			  break;
      // 			case 1:
      // 			  std::cout<<"Options button has been pressed"<<std::endl;
      // 			  break;
      // 			case 2:
      // 			  std::cout<<"Exit button has been pressed"<<std::endl;
      // 			  window.close();
      // 			  break;
      // 			}
      // 		    }
      // 		}
      // 	      break;
      // 	    }
      // 	}
   
      // if( redraw )
      // 	{
      // 	  if (firsttry)
      // 	    {
      // 	      window.clear(sf::Color::Black);
      // 	      window.draw(menu);
      // 	      window.display();
      // 	    }
	}
	 
      //  else if(!firsttry)
      //    {
	      time = clock.getElapsedTime().asSeconds();
	      forest.update(time);
	      // StormTrooper.ObstPosition();
	      StormTrooper.ObstMove();
	      speeder1.Jump();
	      speeder1.player_movement();
	      laser.generatelaser(&speeder1);
	      laser.laser_move();

	
	      // clear the window with black color
	      window.clear(sf::Color::Black);

	      // draw everything here...
	       window.draw(forest);
	      window.draw(speeder1);
	      window.draw(laser);
	      window.draw( StormTrooper);
	      // end the current frame
	      window.display();
	      // }      
	      //}
    }

  return 0;
}
