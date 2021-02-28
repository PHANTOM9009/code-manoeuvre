/*
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
main()
{
    sf::RenderWindow window(sf::VideoMode(1000,700),"animation");
    window.setFramerateLimit(60);
    sf::Texture tex;
    tex.loadFromFile("animation.png");
    sf::Sprite sp(tex);
    //sp.setColor(sf::Color::Red);
    sf::Vector2u spsize=tex.getSize();
   sp.setTextureRect(sf::IntRect(0,0,spsize.x,spsize.y));
    int framesnum=8;
    int animd=1;
    sf::Time elapsedtime;
        sf::Clock clock;
    while(window.isOpen())
    {
        sf::Time time=clock.restart();
        elapsedtime+=time;

        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::EventType::Closed)
                window.close();

        }
        float timeAsSec=elapsedtime.asSeconds();
        int frame=(int)((timeAsSec/animd)*framesnum)%framesnum;
        sp.setTextureRect(sf::IntRect((spsize.x)/8*frame,0,(spsize.x)/8,(spsize.y)/8));

        window.clear(sf::Color::White);
        window.draw(sp);
        window.display();

    }


}
*/
