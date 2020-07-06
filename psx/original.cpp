// Scott Giorlando
// PS1 (Origninal Implementation)
// Copyright[2017] <Scott Giorlando>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "original.hpp"

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cout << "Error: Incorrect number of arguments were entered.\n";
    return -1;
  }

  if (argv[1]-1 < 0) {
    std::cout << "Error: Cannot have recursion less than 1.\n";
    return -1;
  }
  int recur_depth = atoi(argv[1]);
  int win_size = atoi(argv[2]);
  sf::RenderWindow window(sf::VideoMode(win_size, win_size),
  "Original Shape");

  double littleSq = win_size / 3;

    while (window.isOpen()) {
      sf::Event event;
      while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
          window.close();
        }
      }
      originalShape coolSq(recur_depth, littleSq, littleSq, littleSq);
      window.clear();
      window.draw(coolSq);
      window.display();

      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
        if (recur_depth != 7) {
        recur_depth++;
        std::cout << "You are at recursion level " << recur_depth << "!\n";
        }
      }
      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
        if (recur_depth != 0) {
          recur_depth--;
          std::cout << "You are at recursion level " << recur_depth << "!\n";
        }
      }
    }
  return 0;
}

/*
 Constructor originalShape takes in 4 parameters one int and three doubles
 The int is the user defined recursion depth,
 the doubles are one third of the defined window size.
 The constructor takes these arguments and sets the points for the square,
 then goes into if statements for each level of recursion and sets the color.
*/
originalShape::originalShape(int num, double x, double y, double z) {
  depth = num;
  X = x;
  Y = y;
  Z = z;
  Square.setPointCount(4);
  Square.setPoint(0, sf::Vector2f(y, z));
  Square.setPoint(1, sf::Vector2f(x+y, z));
  Square.setPoint(2, sf::Vector2f(x+y, x+z));
  Square.setPoint(3, sf::Vector2f(y, x+z));

    if (depth % 2 == 0) {
      Square.setFillColor(sf::Color::Red);
    }

    if (depth % 2 != 0) {
      Square.setFillColor(sf::Color::Blue);
    }
}

/*
Function draw:
Takes in two parameters, checks to see if the depth is not 0, then recurisvely calls
originalShape constructor, if done correctly there should be a square in the center
and one in each corner, and it keeps going until the recursion is done.
*/
void originalShape::draw(sf::RenderTarget& target,
  sf::RenderStates states) const {
  if (depth > 0) {
    target.draw(Square, states);

    originalShape center(depth-2, X/3,
      Y+(X/3), Z+X/3);
    originalShape upperLeft(depth-1, X/3,
      Y-(2*X/3), Z-(2*X/3));
    originalShape upperRight(depth-1, X/3,
      Y+X+(X/3), Z-(2*X/3));
    originalShape bottomLeft(depth-1, X/3,
      Y-(2*X/3), (Z+(4*X)/3));
    originalShape bottomRight(depth-1, X/3,
      Y+X+(X/3), (Z+(4*X)/3));
    target.draw(upperLeft);
    target.draw(upperRight);
    target.draw(bottomLeft);
    target.draw(bottomRight);
    target.draw(center);
  }
}
