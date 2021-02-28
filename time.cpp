/*
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
main()
{
    sf::RenderWindow window(sf::VideoMode(1000,700),"time");
    window.setFramerateLimit(60);
    sf::Clock clock;
    sf::Time et;
    while(window.isOpen())
    {
        sf::Time time=clock.restart();
        et+=time;
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::EventType::Closed)
                window.close();
        }

        if(et>sf::seconds(5))
            window.close();
    }
}
*/
