// Scott Giorlando
// PS1
// Copyright[2017] <Scott Giorlando>

#ifndef _ORIGINAL_HPP
#define _ORIGINAL_HPP

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class originalShape : public sf::Drawable {
 public:
    originalShape(int num, double x, double y, double z);
    virtual void draw(sf::RenderTarget& target,
      sf::RenderStates states) const;

 private:
    int depth;
    double X;
    double Y;
    double Z;
    sf::ConvexShape Square;
};

#endif
