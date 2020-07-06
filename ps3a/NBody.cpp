//Zachary Palmer & Scott Giorlando

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/CircleShape.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

#include <stdlib.h>
#include <sstream>
#include <iostream>
#include <vector>
#include <iomanip>
#include <string>

#include "NBody.hpp"

int main(int argc, char *argv[])
{
  int N; //Number of Particles
  float R; //radios of the universe
  std::cin >> N;
  std::cin >> R;
  sf::Image background;
  if(!background.loadFromFile("starfield.jpg")) {
    return -1;
  }
  sf::Vector2u size = background.getSize();
  sf::Texture texture;
  texture.loadFromImage(background);
  sf::Sprite sprite;
  sprite.setTexture(texture);
  sf::RenderWindow window(sf::VideoMode(size.x, size.y), "Universe Brought to you by Zach and Scott");
  window.setFramerateLimit(1);
  universeScale.x = (R * 2.0) / window.getSize().x;
  universeScale.y = (R * 2.0) / window.getSize().x;
  std::vector<Body*> bodies;
  for(int i = 0; i < N; i++)
  {
    Body *body = new Body();
    std::cin >> *body;
    bodies.push_back(body);
    std::cout << *bodies[i] << std::endl;
  }
  while(window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window.close();
      }
    }
    window.clear(sf::Color::White);
    window.draw(sprite);
    for(int i = 0; i < N; i++)
    {
      window.draw(*bodies[i]);
    }
    window.display();
  }
  return 0;
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
    newBody.sprite.setPosition(newBody.xPos / universeScale.x, newBody.yPos / universeScale.y * -1);
  }
  return in;
}
