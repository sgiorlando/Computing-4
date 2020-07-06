//Zachary Palmer & Scott Giorlando

#ifndef __NBODY_HPP_INCLUDED
#define __NBODY_HPP_INCLUDED

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <vector>

sf::Vector2f universeScale;

class Body : public sf::Drawable
{
public:
  //CONSTRUCTORS
  Body() {;}
  Body(float xPos, float yPos, float xVel, float yVel, float mass, std::string file);
  //PUBLIC FUNCTIONS
  void step(int numPlanets, int currentPlanet, double sec, std::vector<Body*> planets);
  //ACCESSORS
  float getxPos() {return xPos;}
  float getyPos() {return yPos;}
  float getxVel() {return xVel;}
  float getyVel() {return yVel;}
  float getMass() {return mass;}
  std::string getfile() {return file;}
  sf::Sprite* getsprite() {return &sprite;}
  sf::Texture gettexture() {return texture;}
  //MUTATORS
  void setsprite(); //New function sets the sprite position to the new position.
  void setxPos(float xNew) {xPos = xNew;}
  void setyPos(float yNew) {yPos = yNew;}
  void setxVel(float xVelNew) {xVel = xVelNew;}
  void setyVel(float yVelNew) {yVel = yVelNew;}
  void setmass(float massNew) {mass = massNew;}
  //OVERLOADING OPERATORS
  friend std::istream& operator >> (std::istream &in, Body &newBody);
  friend std::ostream& operator << (std::ostream &out, const Body &newBody);
private:
  //PRIVATE VARIABLES
  float xPos, yPos, xVel, yVel, xAccel, yAccel, mass;
  std::string file;
  sf::Sprite sprite;
  sf::Texture texture;
  //PRIVATE FUNCTIONS
  virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;
};

#endif //NBODY_HPP
