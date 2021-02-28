/*
#include<SFML/Graphics.hpp>
#include<SFML/Window.hpp>
main()
{
    sf::RenderWindow window(sf::VideoMode(1000,700),"camera");
    window.setFramerateLimit(60);
    sf::Texture tex;
    tex.loadFromFile("animation.png");
    auto wsize=window.getSize();
    sf::View view(sf::Vector2f(0,0),sf::Vector2f(wsize.x,wsize.y));
    view.setCenter(sf::Vector2f(0,0));
    window.setView(view);
    sf::Sprite sp(tex);
    sf::Vector2f spsize=sf::Vector2f(70,80);
    sp.setTextureRect(sf::IntRect(0,0,70,80));
    //
    sp.setOrigin(spsize*0.5f);
    sp.setPosition(sf::Vector2f(-100,-300));
    while(window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {

            if(event.type==sf::Event::EventType::Closed)
                window.close();
        }
        window.clear(sf::Color::Black);
        window.draw(sp);
        window.display();
    }

}
*/
