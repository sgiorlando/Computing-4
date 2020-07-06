//Zachary Palmer and Scott Giorlando
#include "EditDistance.hpp"

#include <SFML/System.hpp>

#include <stdlib.h>
#include <iostream>
#include <string>

int main(int argc, char* argv[])
{
  sf::Clock c;
  sf::Time t;
  int editDistance;
  std::string alignmentList;
  std::string inputString1;
  std::string inputString2;

  std::cin >> inputString1;
  std::cin >> inputString2;

  ED edit(inputString1, inputString2);

  editDistance = edit.optimal();
  alignmentList = edit.alignTable();
  t = c.getElapsedTime();

  std::cout << "Edit distance = " << editDistance << "\n" << alignmentList << std::endl;
  std::cout << "Execution time is: " << t.asSeconds() << " seconds" << std::endl;

  return 0;
}
