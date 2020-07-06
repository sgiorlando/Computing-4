//Scott Giorlando
//PS0
#include <SFML/Graphics.hpp>

int main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!");

  sf::Texture texture;
  if(!texture.loadFromFile("sprite.png"))
    {
      return EXIT_FAILURE;
    }
  sf::Sprite sprite(texture);

  sf::Font font;
  if(!font.loadFromFile("dejavusans.ttf"))
  {
    return EXIT_FAILURE;
  }
  sf::Text text("Hello SFML", font, 50);

  sf::CircleShape shape(200.f);
  shape.setFillColor(sf::Color::Green);

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {

      if (event.type == sf::Event::Closed)
      {
        window.close();
      }

    }

    shape.setPosition(100, 100);
    sprite.setScale(0.5f, 0.5f);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
      sprite.move(-1, 0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
      sprite.move(1, 0);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
      sprite.move(0, -1);
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
      sprite.move(0, 1);
    }

    sprite.rotate(1);
    text.move(1, 1);
    window.clear();
    window.setFramerateLimit(60);
    window.draw(shape);
    window.draw(sprite);
    window.draw(text);
    window.display();
  }

  return EXIT_SUCCESS;
}
