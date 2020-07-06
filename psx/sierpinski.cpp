// Scott Giorlando
// PS1 (Sierpinski version)
// Copyright[2017] <Scott Giorlando>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <cmath>
#include <iostream>
#include <cstdlib>
#include "sierpinski.hpp"

int main(int argc, char* argv[]) {
  if (argc < 3 || argc > 4) {
    std::cout << "./sierpinski[recursion-depth][side-length]\n";
    return -1;
  }

  int recur_depth = atoi(argv[1]);

  if (recur_depth < 0) {
    std::cout << "Depth should be greater than 0.\n";
    return -2;
  }

  float wHeight = atoi(argv[2]);
  sf::ConvexShape baseTri = initialTriangle(wHeight);
  sf::RenderWindow window(sf::VideoMode(wHeight, wHeight),
  "Sierpinski Triangle");

  while (window.isOpen()) {
    sf::Event event;
    while (window.pollEvent(event)) {
      if (event.type == sf::Event::Closed) {
        window.close();
      }
    }

    Sierpinski sierTri(recur_depth, (wHeight/4),
    wHeight-(wHeight/2*sqrt(3))+(wHeight/4*sqrt(3)), (wHeight/2));
    window.clear();
    window.draw(baseTri);
    window.draw(sierTri);
    window.display();
  }

  return 0;
}

sf::ConvexShape initialTriangle(int x) {
  sf::Vector2f left = sf::Vector2f(0, x);
  sf::Vector2f top = sf::Vector2f(x/2, x-x/2*sqrt(3));
  sf::Vector2f right = sf::Vector2f(x, x);
  sf::ConvexShape triangle(3);
  triangle.setFillColor(sf::Color::Yellow);
  triangle.setPoint(0, left);
  triangle.setPoint(1, top);
  triangle.setPoint(2, right);
  return triangle;
}

/*
 Constructor Sierpinski
 Takes 4 parameters 3 floats and a int
 The floats represent the points on the triagnle,
 a being a left side, b being a right, and c being the side.
 This constructor takes a depth and sets the points on the triangle.
*/
Sierpinski::Sierpinski(int num, float a, float b, float c) {
  triangle.setPointCount(3);
  depth = num;
  A = a;
  B = b;
  C = c;
  // height of the triangle
  height = (c*(sqrt(3))/2);

  triangle.setFillColor(sf::Color::Black);
  triangle.setPoint(0, sf::Vector2f(a, b));
  triangle.setPoint(1, sf::Vector2f((c+a), b));
  triangle.setPoint(2, sf::Vector2f(((c/2)+a), height+b));
}

/*
 Function Sierpinski::draw
 This function takes in a target and states, and it draws the triangle and
 recurisvely calls the Sierpinski constructor.
 This should draw smaller triangles with each level of recursion.
*/
void Sierpinski::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    if (depth != 0) {
      target.draw(triangle, states);
      Sierpinski X(depth - 1, A-(C/4), B+(height/2), (C/2));
      Sierpinski Y(depth - 1, (A+(3*C)/4), B+(height/2), (C/2));
      Sierpinski Z(depth - 1, (A+(C)/4), B-(height/2), (C/2));
      target.draw(X);
      target.draw(Y);
      target.draw(Z);
    }
}
