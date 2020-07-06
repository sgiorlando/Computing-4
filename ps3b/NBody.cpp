//Zachary Palmer & Scott Giorlando

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Audio.hpp>

#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include <cmath>

#include "NBody.hpp"

const double GRAV = 6.6742E-11; //Gravitational constant

int main(int argc, char *argv[])
{

  if(argc > 3 || argc < 3)                  //Check format of parameters
  {
    std::cout << "Error: Incorrect number of parameters were entered." << std::endl;
    return -1;
  }
  double total_time = std::atof(argv[1]);   //Total time the simulation will run
  double delta_time =  std::atof(argv[2]);  //time between steps
  double current_time = 0;                  //Current time (will be incremented)
  int N;                                    //Number of Particles
  float R;                                  //radius of the universe
  bool displayed = false;                   //end screen dislpayed
  std::cin >> N;
  std::cin >> R;
  std::vector<Body*> bodies;                //vector of bodies
  sf::Image background;                     //background image
  sf::Sprite sprite;                        //background sprite
  sf::Texture texture;                      //background texture
  sf::Music music;                          //music file

  if(!background.loadFromFile("starfield.jpg"))
  {
    std::cout << "Error: Background did not load properly." << std::endl;
    return -1;
  }
  if(music.openFromFile("2001.wav"))
  {
    music.setLoop(true);
    music.play();
  }

  sf::Vector2u size = background.getSize();
  texture.loadFromImage(background);
  sprite.setTexture(texture);
  sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Universe Brought to you by Zach and Scott");
  window.setFramerateLimit(40);
  universeScale.x = (R * 2.0) / window.getSize().x;
  universeScale.y = (R * 2.0) / window.getSize().x;

  for(int i = 0; i < N; i++)                //instantiate the vector of bodies
  {
    Body *body = new Body();
    std::cin >> *body;
    bodies.push_back(body);
  }

  while(window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
        window.close();
    }
    if(current_time < total_time)
    {
      window.clear(sf::Color::White);
      window.draw(sprite);
      for(int i = 0; i < N; i++)            //Loop to step each body a given number of seconds
        (*bodies[i]).step(N,i,delta_time,bodies);

      for(int i = 0; i < N; i++)            //Loop to set each sprite and draw them
      {
        (*bodies[i]).setsprite();
        window.draw(*bodies[i]);
      }
      current_time = current_time + delta_time;  //incerement current time by delta time
    }
    if (current_time >= total_time && !displayed)
    {
      for(int i = 0; i < N; i++)            //Loop to display status of bodies at end time
      {
        std::cout << *bodies[i] << std::endl;
      }
      displayed = true;
    }
    window.display();
  }
  return 0;
}

void Body::setsprite()
{
  sprite.setPosition(xPos / universeScale.x, yPos / universeScale.y * -1);
}

void Body::step(int numPlanets, int currentPlanet, double sec, std::vector<Body*> planets)
{
  double radius, xForce, yForce, gForce;
  for(int i = 0; i < numPlanets; i++)
    {
      if(i != currentPlanet)
      {
        radius = sqrt(pow(xPos-planets[i]->getxPos(),2) + pow(yPos - planets[i]->getyPos(),2));
        gForce = GRAV * planets[i]->getMass() * mass / pow(radius,2);
        xForce = gForce * (xPos - (planets[i]->getxPos())) / radius;
        yForce = gForce * (yPos - (planets[i]->getyPos())) / radius;
        xVel   = xVel + sec * xForce / mass;
        yVel   = yVel + sec * yForce / mass;
      }
    }
    xPos = xPos-(sec*xVel);
    yPos = yPos-(sec*yVel);
}


void Body::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
  states.transform.translate(target.getSize().x * .5, target.getSize().y * .5);
  target.draw(sprite, states);
}

std::ostream& operator << (std::ostream &out, const Body &newBody)
{
  out << std::setiosflags(std::ios::scientific) << std::setw(11) << std::setprecision(4) << newBody.xPos << " " << std::setw(11) << std::setprecision(4) << newBody.yPos << " "
      << std::setw(11) << std::setprecision(4) << newBody.xVel << " " << std::setw(11) << std::setprecision(4) << newBody.yVel << " "
      << std::setw(11) << std::setprecision(4) << newBody.mass << " " << std::setw(12) << newBody.file;
      return out;
}

std::istream& operator >> (std::istream &in, Body &newBody)
{
  in >> newBody.xPos >> newBody.yPos >> newBody.xVel >> newBody.yVel >> newBody.mass >> newBody.file;
  if(newBody.texture.loadFromFile(newBody.file))
  {
    newBody.sprite.setTexture(newBody.texture);
    newBody.sprite.setOrigin(newBody.sprite.getLocalBounds().width*.5, newBody.sprite.getLocalBounds().height*.5);
    newBody.setsprite();
  }
  return in;
}
