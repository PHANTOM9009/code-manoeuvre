/*
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000,700),"texture");
    window.setFramerateLimit(60);
    sf::Texture tex;

    tex.loadFromFile("images.jpg");


    tex.setRepeated(true);

    sf::Vector2u tsize=tex.getSize();
     sf::Sprite sp(tex);
     sp.setColor(sf::Color::Magenta);

    sp.setTextureRect(sf::IntRect(0,0,(float)tsize.x*4,(float)tsize.y*5));

    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::EventType::Closed)
                window.close();
        }
        ///////////////
        //circle.rotate(3);
        //circle.move(1,0);

        //////////////render frame
        window.clear(sf::Color::White);
        window.draw(sp);
        window.display();
    }


}
*/

