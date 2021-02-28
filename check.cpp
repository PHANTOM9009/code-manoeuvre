/*
#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
using namespace std;
void shape(sf::RectangleShape &rect,sf::Vector2f const &pos,sf::Color const &color)
{
    rect.setFillColor(color);
    rect.setPosition(pos);
    rect.setOrigin(rect.getSize()*0.5f);

}
 main()
{

sf::RenderWindow window(sf::VideoMode(1000,700),"anchit rana");
window.setFramerateLimit(60);

sf::RectangleShape prect(sf::Vector2f(50,50));
sf::Vector2f startpos=sf::Vector2f(50,50);
shape(prect,startpos,sf::Color::Green);
/////////////////////////////////////////////////
sf::RectangleShape trect(sf::Vector2f(50,50));
shape(trect,sf::Vector2f(400,50),sf::Color::Blue);
///////////////////////////////////////////////////////
sf::RectangleShape brect(sf::Vector2f(50,100));
sf::Color color(0,0,0,255);
shape(brect,sf::Vector2f(250,50),color);

int x=0,y=450;
int c=0;

 while (window.isOpen())
 {
    sf::Event event;
    while(window.pollEvent(event))
    {
        if(event.type==sf::Event::EventType::Closed)
            window.close();
    }
    ///////////////////////game loop


    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
    {
        prect.rotate(3);
        prect.move(-1,0);
    }
    if(prect.getGlobalBounds().intersects(trect.getGlobalBounds()))
    {
        window.clear(sf::Color::White);
        window.draw(prect);
    window.draw(trect);
    //window.draw(brect);
        window.display();

        window.setTitle("you win");
    }
    if(prect.getGlobalBounds().intersects(brect.getGlobalBounds()))
    {
        cout<<"touched";
        window.setTitle("you loose");
        prect.setPosition(startpos);
    }

   ////////////////////////////////////render screen
    window.clear(sf::Color::Red);
    window.draw(prect);
    window.draw(trect);
    window.draw(brect);
        window.display();
        x++;
}
return 0;
cout<<c;
}

*/
