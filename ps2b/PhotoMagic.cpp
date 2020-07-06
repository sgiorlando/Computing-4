//Scott Giorlando
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <iostream>
#include <string>
#include "LFSR.hpp"

//Function changeImage takes in a image object and a LFSR object as its parameters.
//It is meant to create a new scrambled image and change the LFSR sequence of the original image to encode it.
sf::Image changeImage(sf::Image image, LFSR sequence);

int main(int argc, char* argv[])
{
  int tap_pos = 0;
  std::string bit_seed = "";

  if(argc < 4)
  {
    std::cout << "./PhotoMagic error, 4 arguments requried: [Input File][Output File][Seed][Tap Bit Position]" << std::endl;
  }

  std::string image_input = argv[1];
  std::string image_output = argv[2];

  bit_seed = argv[3];
  tap_pos = atoi(argv[4]);

  //Call the LFSR constructor and make a new LFSR object with the given seed and tap position.
  LFSR l1(bit_seed, tap_pos);

  sf::Image in_image;

  if(!in_image.loadFromFile(image_input))
  {
    std::cout << "Error, unable to load the input image." << std::endl;
    return -1;
  }

  //Assign the new output image file to the new scrambled image.
  sf::Image out_image = changeImage(in_image, l1);

  sf::Vector2u input_size = in_image.getSize();
  sf::Vector2u output_size = out_image.getSize();

  sf::RenderWindow window1(sf::VideoMode(input_size.x, input_size.y), "Input");
  sf::RenderWindow window2(sf::VideoMode(output_size.x, output_size.y), "Output");

  sf::Texture input_texture;
  input_texture.loadFromImage(in_image);

  sf::Texture output_texture;
  output_texture.loadFromImage(out_image);

  sf::Sprite input_sprite;
  input_sprite.setTexture(input_texture);

  sf::Sprite output_sprite;
  output_sprite.setTexture(output_texture);

  while(window1.isOpen() && window2.isOpen())
  {
    sf::Event event;
    while(window1.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window1.close();
      }
    }

    while(window2.pollEvent(event))
    {
      if(event.type == sf::Event::Closed)
      {
        window2.close();
      }
    }
    window1.clear(sf::Color::White);
    window1.draw(input_sprite);
    window1.display();
    window2.clear(sf::Color::White);
    window2.draw(output_sprite);
    window2.display();
  }

  if(!out_image.saveToFile(image_output))
  {
    return -1;
  }

  return 0;
}

//Function changeImage takes in a image object and a LFSR object as its parameters.  It creates a whole new image that is a copy of the original file given as an argument, and it calls the LFSR seed
//and changes the bit sequence of the LFSR string and also changes the color pixels of the new image, which casues the image to be scrambled.  The new scrambled image is returned and later used as the output file.
sf::Image changeImage(sf::Image image, LFSR sequence)
{
  sf::Vector2u new_size = image.getSize();

  sf::Image new_image;
  new_image.create(new_size.x, new_size.y);

  sf::Color pixel;
  for(unsigned int x = 0; x < new_size.x; x++)
  {
    for(unsigned int y = 0; y < new_size.y; y++)
    {
      pixel = image.getPixel(x, y);
      pixel.r = pixel.r ^ sequence.generate(8);
      pixel.g = pixel.g ^ sequence.generate(8);
      pixel.b = pixel.b ^ sequence.generate(8);
      new_image.setPixel(x, y, pixel);
    }
  }
  return new_image;
}
