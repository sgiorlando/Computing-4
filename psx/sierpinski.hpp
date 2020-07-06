// Scott Giorlando
// PS1
// Copyright[2017] <Scott Giorlando>
#ifndef _SIERPINSKI_HPP
#define _SIERPINSKI_HPP
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

sf::ConvexShape initialTriangle(int x);

class Sierpinski : public sf::Drawable {
 public:
  Sierpinski(int num, float a, float b, float c);
  virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

 private:
  int depth;
  sf::ConvexShape triangle;
  float A;
  float B;
  float C;
  float height;
};

#endif
