#include "Menu.h"

Menu::Menu(float width ,float hight)
 {
     if(!font.loadFromFile("fonts/arial.ttf")){}
     //play user
     mainmenu[0].setFont(font);
     mainmenu[0].setColor(sf::Color::Blue);
     mainmenu[0].setString("2 Players");
     mainmenu[0].setCharacterSize(50);
     mainmenu[0].setPosition(sf::Vector2f(width/2 -50,hight/(Max_main_menu +1)));
     //play ord
     mainmenu[1].setFont(font);
     mainmenu[1].setColor(sf::Color::White);
     mainmenu[1].setString("1 Player");
     mainmenu[1].setCharacterSize(50);
     mainmenu[1].setPosition(sf::Vector2f(width/2 -50,hight/(Max_main_menu +1)*2));

     mainmenu[2].setFont(font);
     mainmenu[2].setColor(sf::Color::White);
     mainmenu[2].setString("Exit");
     mainmenu[2].setCharacterSize(50);
     mainmenu[2].setPosition(sf::Vector2f(width/2 -50,hight/(Max_main_menu +1)*3));

     menu_selected=2;
 }

 void Menu::draw(sf::RenderWindow &window)
 {
     for(int i=0;i<3;i++)
     {
         window.draw(mainmenu[i]);
     }
 }

 void Menu::move_down()
 {
     if(menu_selected+1<= Max_main_menu)
     {
         mainmenu[menu_selected].setColor(sf::Color::White);
         menu_selected++;
         if(menu_selected==3)
         {
             menu_selected=0;
         }
         mainmenu[menu_selected].setColor(sf::Color::Blue);

     }
 }
 void Menu::move_up()
 {

     if(menu_selected-1>=  -1)
     {
         mainmenu[menu_selected].setColor(sf::Color:: White);
         menu_selected--;
         if(menu_selected==-1)
         {
             menu_selected=2;
         }
         mainmenu[menu_selected].setColor(sf::Color ::Blue);

     }

 }