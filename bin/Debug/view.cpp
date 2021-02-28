#include<cstring>
#include<stdlib.h>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<time.h>
#include<ctime>
#include<stdio.h>
using namespace std;
class game//game class
{
     sf::Texture tex;
     sf::Text text1[100];//text for the blocks running
     sf::Text text2[100];//text for the terminal
        sf::Sprite sp;
        sf::Sprite sp1;
        sf::Texture tex1;
        //texture for background change
        sf::Texture tex2;
        sf::Texture tex3;
        sf::Sprite sp2;
        sf::Sprite sp3[100];
 public:
    show(sf::RenderWindow &window)
    {
        window.setFramerateLimit(80);
    sf::Vector2u winsize=window.getSize();


    tex.loadFromFile("b1.png");
    sp.setTexture(tex);
   // sp.setPosition(sf::Vector2f(200,0));

     sp1.setTexture(tex);
     sp1.setPosition(sf::Vector2f(1920,0));

       tex1.loadFromFile("plane2.png");
    sp2.setTexture (tex1);
     sp2.setPosition(sf::Vector2f(50,600));

      tex2.loadFromFile("b2.png");
    tex3.loadFromFile("b4.png");

    //change this loop to change the textures rendered
     for(int i=0;i<68;i++)
    {

        sp3[i].setTexture(tex2);
    }
    for(int i=68;i<100;i++)
    {
        sp3[i].setTexture(tex3);
    }
    //set position loop will not change in any fuckin case
    int p=2;
    for(int i=0;i<100;i++)
    {
        sp3[i].setPosition(sf::Vector2f(1920*p,0));
        p++;
    }
////////////////////////////////////////////////////////////////////////////////////////
    bool jump;

    sf::View view(sf::FloatRect(0,0,winsize.x,winsize.y));
    view.setViewport(sf::FloatRect(0,0,0.75,1));
   sf::View view1(sf::FloatRect(0,0,winsize.x,winsize.y));
   //sf::View view2(sf::FloatRect(0,0,winsize.x,winsize.y));
 // view2.setViewport(sf::FloatRect(0.75,0,0.25,1));

int flag=0;
    sf::Time et=sf::seconds(0);
    sf::Clock ck;
    float tm;//time in seconds

    sf::Color color=sf::Color(13,29,80,255);//rectangle of the terminal
    sf::RectangleShape rect(sf::Vector2f(600,1080));
    rect.setPosition(sf::Vector2f(1400,0));
    rect.setFillColor(color);

     sf::RectangleShape rect1(sf::Vector2f(20,50));
    rect1.setPosition(sf::Vector2f(5000,200));
    rect1.setFillColor(sf::Color::Black);
    /////defining text here now....using font1 by default.

    sf::Font font;//text for terminal
    font.loadFromFile("font1.ttf");
    sf::Text text("TERMINAL",font,50);
    text.setFillColor(sf::Color::Yellow);
    text.setStyle(sf::Text::Underlined);
    text.setPosition(sf::Vector2f(1530,10));
    text.setOutlineThickness(3);
    //setting text to the blocks
    FILE *f;
    f=fopen("blocks.txt","r+");
    char ch[50][100];
    int h=0;
    while(fscanf(f,"%s",ch[h])!=EOF)
    {
        text1[h].setString(ch[h]);
        text1[h].setFont(font);
        h++;
    }
    int rx;
    int pos=1400;
    time_t tt;
    int seedval=time(&tt);
    srand(seedval);

    for(int j=0;j<h;j++)
    {


        pos=pos+1000;
    text1[j].setFillColor(sf::Color::Black);
    text1[j].setCharacterSize(30);
    text1[j].setPosition(sf::Vector2f(pos,650));

    }
    int countt=0;
    int pos2=4400;
    int pos3=600;



    int xx[100];
    sf::Vector2f vect;
    //storing value of x coordinates of blocks in xx
    for(int i=0;i<h;i++)
    {
        vect=text1[i].getPosition();
        xx[i]=vect.x;
    }

    while (window.isOpen())
    {
        et+=ck.restart();
        tm=et.asSeconds();
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::EventType::Closed)
            window.close();
        }
    view.move(10.f,0.f);
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {

            jump=true;
            flag=1;

    }
    if(jump==true)
    {
       sp2.move(0,-8);
        if(sf::Vector2f(50,400)==sp2.getPosition())
        {
            jump=false;
        }
    }

    //collisions
    string word;
     sf::Vector2f player_pos=sp2.getPosition();
     int xxx=0;int pos4_x=1410,pos4_y=60;
    for(int i=0;i<h;i++)
    {
        if(player_pos.y==pos3&&(player_pos.x+200)==xx[i])
        {
            word=text1[i].getString();
            cout<<word<<endl;
           text2[xxx].setString(word);
           text2[xxx].setFillColor(sf::Color::Yellow);
           text2[xxx].setPosition(sf::Vector2f(1410.f,60.f));
           xxx++;
           pos4_y+=40;


        }
    }


    /*
   sf::Vector2f player_pos=sp2.getPosition();
   pos2=pos2-10;
   if(player_pos.y==pos3&&(player_pos.x+200)==pos2)
   {
       cout<<"collide"<<endl;
   }
   */




    //for eliminating the blocks which have gone past the jet

    /*
    for(int i=0;i<h;i++)
    {
        vect=text1[i].getPosition();
        if(vect.x<50)
        {
            countt++;
        }
            //red++;

    }
    */




    window.clear();
    //rendering the background and the alphabets
    window.setView(view);
    window.draw(sp);
    window.draw(sp1);
   for(int i=0;i<100;i++)
   {
       window.draw(sp3[i]);
   }
   for(int i=0;i<h;i++)
   {
   window.draw(text1[i]);//render alphabets here
   }

   //RENDERING  view 1 i.e the player and of the code that appears on the screen..
   window.setView(view1);
   window.draw(sp2);
  window.draw(rect);
  window.draw(text);
  window.draw(text2[0]);
    //display everything
    window.display();
    //for the down motion of the player
    if(flag==1&&jump==false)//downfall
    {
        sp2.move(0,8);
        if(sf::Vector2f(50,600)==sp2.getPosition())
        {
            flag=0;
        }

    }
    //updating the x coordinate of the blocks
    for(int i=0;i<h;i++)
    {
        xx[i]=xx[i]-10;

    }


}


    }

};
game gm;//object of the class game

delay(int mil)
{

    clock_t t=clock();
    while(clock()<t+mil);
}
/*
main()
{
    sf::RenderWindow window(sf::VideoMode(1920,1080),"view");
    window.setFramerateLimit(80);
    sf::Vector2u winsize=window.getSize();
    sf::Texture tex;

    tex.loadFromFile("b1.png");
    sf::Sprite sp(tex);
   // sp.setPosition(sf::Vector2f(200,0));

     sf::Sprite sp1(tex);
     sp1.setPosition(sf::Vector2f(1920,0));
     sf::Texture tex1;
       tex1.loadFromFile("plane2.png");
     sf::Sprite sp2(tex1);
     sp2.setPosition(sf::Vector2f(50,600));

     sf::Sprite sp3[12];
     for(int i=0;i<12;i++)
    {

        sp3[i].setTexture(tex);
    }
    int p=2;
    for(int i=0;i<12;i++)
    {
        sp3[i].setPosition(sf::Vector2f(1920*p,0));
        p++;
    }
////////////////////////////////////////////////////////////////////////////////////////
    bool jump;

    sf::View view(sf::FloatRect(0,0,winsize.x,winsize.y));
    view.setViewport(sf::FloatRect(0,0,0.75,1));
   sf::View view1(sf::FloatRect(0,0,winsize.x,winsize.y));
   //sf::View view2(sf::FloatRect(0,0,winsize.x,winsize.y));
 // view2.setViewport(sf::FloatRect(0.75,0,0.25,1));

int flag=0;
    sf::Time et=sf::seconds(0);
    sf::Clock ck;
    float tm;//time in seconds

    sf::Color color=sf::Color(13,29,80,255);//rectangle of the terminal
    sf::RectangleShape rect(sf::Vector2f(600,1080));
    rect.setPosition(sf::Vector2f(1400,0));
    rect.setFillColor(color);

     sf::RectangleShape rect1(sf::Vector2f(20,50));
    rect1.setPosition(sf::Vector2f(5000,200));
    rect1.setFillColor(sf::Color::Black);
    /////defining text here now....using font1 by default.

    sf::Font font;
    font.loadFromFile("font1.ttf");
    sf::Text text("TERMINAL",font,50);
    text.setFillColor(sf::Color::Yellow);
    text.setStyle(sf::Text::Underlined);
    text.setPosition(sf::Vector2f(1530,10));



    while (window.isOpen())
    {
        et+=ck.restart();
        tm=et.asSeconds();
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::EventType::Closed)
            window.close();
        }
    view.move(10.f,0.f);
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
    {

            jump=true;
            flag=1;

    }
    if(jump==true)
    {
       sp2.move(0,-10);
        if(sf::Vector2f(50,400)==sp2.getPosition())
        {
            jump=false;
        }
    }



    window.clear();
    //rendering the background and the alphabets
    window.setView(view);
    window.draw(sp);
    window.draw(sp1);
   for(int i=0;i<12;i++)
   {
       window.draw(sp3[i]);
   }
   window.draw(rect1);//render alphabets here

   //RENDERING  view 1 i.e the player and of the code that appears on the screen..
   window.setView(view1);
   window.draw(sp2);
  window.draw(rect);
  window.draw(text);
    //display everything
    window.display();
    //for the down motion of the player
    if(flag==1&&jump==false)//downfall
    {
        sp2.move(0,10);
        if(sf::Vector2f(50,600)==sp2.getPosition())
        {
            flag=0;
        }

    }


}
}
*/

main()
{
   sf::RenderWindow window(sf::VideoMode(1920,1080),"view");
   gm.show(window);//here checking to call the game class

}

