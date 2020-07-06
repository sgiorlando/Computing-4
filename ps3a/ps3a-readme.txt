/**********************************************************************
 *  N-Body Simulation ps3a-readme.txt template
 **********************************************************************/

Name: Zachary Palmer & Scott Giorlando
OS: Windows 10
Machine (e.g., Dell Latitude, MacBook Pro): Surface Book, Razer Blade
                                            Custom built Windows PC
Text editor: Atom

/**********************************************************************
 *  Briefly explain the workings of the features you implemented.
 *  Include code excerpts.
 **********************************************************************/
1.) Celestial body object is Drawable and SFML while loop uses window.draw(obj)
  the Body class inherits from the drawable class and we overloaded the draw function
  this way so that it properly drew on the screen\

    states.transform.translate(target.getSize().x * .5, target.getSize().y * .5);
    target.draw(sprite, states);

2.) implementation loads universe from stdin
  simply using std::cin >> *body was how we did this

3.) body class has >> overloaded to read in a row from universe file
  The >> overload function took care of both assigning the variables to the inputs but
  also setting things like the texture, origin and position of the sprite

    in >> newBody.xPos >> newBody.yPos >> newBody.xVel >> newBody.yVel >> newBody.mass >> newBody.file;
    if(newBody.texture.loadFromFile(newBody.file))
    {
      newBody.sprite.setTexture(newBody.texture);
      newBody.sprite.setOrigin(newBody.sprite.getLocalBounds().width*.5, newBody.sprite.getLocalBounds().height*.5);
      newBody.sprite.setPosition(newBody.xPos / universeScale.x, newBody.yPos / universeScale.y * -1);
      }

4.) supports arbitrary number of body objects (per universe file)
  For every body object it pushes it back into a vector named bodies

    for(int i = 0; i < N; i++)
    {
      Body *body = new Body();
      std::cin >> *body;
      bodies.push_back(body);
      std::cout << *bodies[i] << std::endl;
      }

5.) scaling works for arbitrary universe size and given SFML window size declared in main.cpp
  using a global variable universeScale of type Vector2f set according to the size of the background image
  (though you can also set it manually in this line rather than the size.x and size.y)

    universeScale.x = (R * 2.0) / window.getSize().x;
    universeScale.y = (R * 2.0) / window.getSize().x;

/**********************************************************************
 *  List whatever help (if any) you received from the instructor,
 *  classmates, or anyone else.
 **********************************************************************/
 Just Zach and Scott (the group)

/**********************************************************************
 *  Describe any serious problems you encountered.
 **********************************************************************/
Weirdly enough the window output looked strange on Scott's Laptop (the
background was the earth rather than the starfield) but it worked properly
on Zach's Desktop and Laptop
