#include<cstring>
#include<stdlib.h>
#include<iostream>
#include <SFML/Graphics.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Audio/Sound.hpp>
#include<SFML/Audio/InputSoundFile.hpp>

#include<time.h>
#include<ctime>
#include<stdio.h>
using namespace std;
delay(int mil)
{

    clock_t t=clock();
    while(clock()<t+mil);
}
//function to display the intro screen
split(sf::RenderWindow &window,char s2[200][100],int q)
    {
        for(int i=0;i<q;i++)
        {
            cout<<s2[i];
        }
        cout<<endl;

        sf::Text tex1;//for the right code
    sf::Text tex2[100];//for the wrong code
    sf::Text tex3;
    sf::Text tex4;
    sf::Text tex5;
    sf::RectangleShape rect3(sf::Vector2f(1920,45));
    sf::RectangleShape rect1(sf::Vector2f(960,1080));
    sf::RectangleShape rect2(sf::Vector2f(960,1080));
    rect1.setPosition(sf::Vector2f(0,0));
    rect2.setPosition(sf::Vector2f(960,0));
    rect1.setFillColor(sf::Color(22,144,188,225));//light blue
    rect2.setFillColor(sf::Color(8,90,46,225));//dark green
    rect3.setPosition(sf::Vector2f(0,0));
    rect3.setFillColor(sf::Color::Black);
    sf::Font font;
    font.loadFromFile("font1.ttf");
    tex1.setFont(font);

    tex1.setFillColor(sf::Color::Black);
    int foul[100];//will store the index of the wrong word
    char s1[100][100];
    tex4.setFont(font);
    tex4.setColor(sf::Color::Black);
    tex4.setString("Answer");
    tex4.setCharacterSize(40);
    tex4.setPosition(150,50);

    tex5.setFont(font);
    tex5.setColor(sf::Color::Black);
    tex5.setString("your code");
    tex5.setCharacterSize(40);
    tex5.setPosition(1060,50);
    FILE *f;

    f=fopen("real.txt","r+");

    if(f==NULL)
    {
        cout<<"\n cant open first file";
    }

    //extracting elements from file 1
    int p=0;
    while(fscanf(f,"%s",s1[p])!=EOF)
    {

        p++;
    }

    for(int i=0;i<p;i++)
    {
        cout<<s1[i];
    }


    //checking the files
    int c=0;int tell=0;
    for(int i=0;i<q;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(strcmp(s1[j],s2[i])==0)
            {
                tell=1;
                break;

            }


    }
    if(tell==0)
    {
        foul[c]=i;
                c++;
    }


    }
     cout<<endl<<c;
    int flag=0;
    if(q!=p)
    {
        tex3.setFont(font);
    tex3.setFillColor(sf::Color::Red);

        tex3.setString("you have something missing in the code!, please check the adjoining code......");
        tex3.setPosition(sf::Vector2f(100,1000));
    }

    //for text2
    int count_i=0;
    int trans=1;int pos_x=970,pos_y=200;
    cout<<"\n upto loop";
    for(int i=0;i<q;i++)
    {
        tex2[i].setFont(font);
        tex2[i].setString(s2[i]);
        tex2[i].setFillColor(sf::Color::Black);
        if(trans<=3)
        {
            tex2[i].setPosition(sf::Vector2f(pos_x,pos_y));
            trans++;
            pos_x+=172;

        }
        else if(trans>3)
        {
            pos_x=970;
            pos_y+=40;
            trans=1;

        }
        if(foul[count_i]==i)
        {
            count_i++;
            tex2[i].setFillColor(sf::Color::Red);
        }


    }
    //showing text1
    char put[200];
    //while(fgets(put,199,f)!=NULL);
    tex1.setString("#include <iostream> \n using namespace std; \n int main() \n{\n int a;\n int b; \n int sum=a+b; \n cout<<sum; \n }");
    tex1.setPosition(sf::Vector2f(50,200));
    cout<<endl<<put;



      while (window.isOpen())
    {
        //cout<<"\n inside window event";
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::EventType::Closed)
            window.close();

        }

        window.clear();
        window.setView(window.getDefaultView());
        window.draw(rect1);
        window.draw(rect2);
        window.draw(tex1);
        for(int i=0;i<q;i++)
        {
            window.draw(tex2[i]);
        }
       // window.draw(tex3);
       window.draw(tex4);
       window.draw(tex5);
       window.draw(rect3);
        window.display();




    }
    }







class game//game class
{
     sf::Texture tex;
     sf::Text text1[100];//text for the blocks running
     sf::Text text2[100];//text for the terminal
     sf::Text text10;
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
        window.setFramerateLimit(100);
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

    text10.setFont(font);
    text10.setFillColor(sf::Color::Yellow);
    text10.setPosition(sf::Vector2f(10,10));
    text10.setString("A C++ PROGRAM TO ADD TWO NUMBERS: \n PAUSE: P \n RESUME: R");
    text10.setCharacterSize(40);

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
   // text1[j].setFillColor(sf::Color::Red);
    text1[j].setCharacterSize(40);
    text1[j].setPosition(sf::Vector2f(pos,650));

    }
    for(int i=0;i<h;i++)
    {
        if(i%2==0)
        {
                        text1[i].setFillColor(sf::Color(10,10,70,225));
        }
        else
            text1[i].setFillColor(sf::Color::Red);
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
    int xxx=0;//for terminal text
      int pos4_x=1410,pos4_y=70;
      int pp=1;//for terminal
      //file 2 for the terminal
      FILE *ff;
      ff=fopen("terminal.txt","w+");
      char terminal[500];
      char terminalx[200][100];
      int tx=0;

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
    string word,word1;
     sf::Vector2f player_pos=sp2.getPosition();

    for(int i=0;i<h;i++)
    {
        if(player_pos.y==pos3&&(player_pos.x+200)==xx[i])
        {
            word=text1[i].getString();
            text2[xxx].setFont(font);
           text2[xxx].setString(word);
           text2[xxx].setFillColor(sf::Color::Yellow);
           if(pp<=3)
           {
           text2[xxx].setPosition(sf::Vector2f(pos4_x,pos4_y));
           pp++;
           pos4_x+=172;
           }
           if(pp>3)
           {
               pos4_x=1410;
               pos4_y+=40;
               pp=1;
           }
           xxx++;
           text1[i].setPosition(sf::Vector2f(-100,200));
           strcpy(terminal, word.c_str());
           fprintf(ff,"%s ",terminal);
           strcpy(terminalx[tx],word.c_str());
           // strcpy(terminalx[tx+1]," ");
                      tx++;





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
    //closing this window
    if(xx[h-1]<50)
    {
        cout<<"end";

        //add the function name;
        split(window,terminalx,xxx);
    }
     if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
     {
         while(1)
         {
              if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
                break;
         }
     }



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
  window.draw(text10);
  for(int i=0;i<xxx;i++)
  {
      window.draw(text2[i]);
  }
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

//class 2 for the end and the evaluating screen
game gm;//object of the class game
intro(sf::RenderWindow &window)
{

    sf::Texture tex;
    tex.loadFromFile("intro.png");
    sf::Sprite sp(tex);
    sp.setPosition(sf::Vector2f(0,0));
    while (window.isOpen())
    {
        //cout<<"\n inside window event";
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::EventType::Closed)
            window.close();

        }

        window.clear();
        window.draw(sp);
        window.display();
        delay(2000);
        gm.show(window);

    }

}






main()
{
   sf::RenderWindow window(sf::VideoMode(1920,1080),"view");
   //gm.show(window);//here checking to call the game class
    intro(window);
    //sf::SoundBuffer sbuffer;
    //if(!sbuffer.loadFromFile("sound.wav"))
      //  return -1;

        //sf::Sound sound(sbuffer);
        //sound.play();

}

