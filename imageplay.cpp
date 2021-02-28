/*
#include<iostream>
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
main()
{
    sf::RenderWindow window(sf::VideoMode(1360,730),"image play");
    window.setFramerateLimit(60);

    sf::Image background;
    background.loadFromFile("G:/new sfml/anchit.jpg");
    sf::Vector2f siz=background.getSize();
for(int i=0,j=0;i<500,j<500;i++,j++)
{

sf::Color color = background.getPixel(i, j);
color.r = 0;
color.g=0;
color.b=0;
color.a=255;
background.setPixel(i, j, color);
}
background.saveToFile("G:/new sfml/result4.jpg");
while(window.isOpen())
{
    sf::Event event;

        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::EventType::Closed)
            window.close();
        }
        window.clear(sf::Color::White);
       // window.draw();
        window.display();
    }

}
*/
