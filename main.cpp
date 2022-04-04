#include "Engine.h"
#include "Menu.h"

using namespace sf;


int main()
{
    Board b;
    RenderWindow window_1(VideoMode(800, 800), "Chess_Menu");
    Texture t;
    if (!t.loadFromFile("images/menu.jpeg")) cout<<"Erreur";
    Sprite sp;
    sp.setTexture(t);
    sp.setPosition(0,0);
    Menu menu(600,600);

//window de menu
     while(window_1.isOpen())
    {
        sf::Event ev;
        while(window_1.pollEvent(ev))
        {
            if(ev.type==Event::Closed)
            {
                window_1.close();
            }
            if(ev.type==Event::KeyReleased)
            {
                if(ev.key.code==sf::Keyboard::Up)
                {
                    menu.move_up();
                    break;
                }

                 if(ev.key.code==sf::Keyboard::Down)
                {
                    menu.move_down();
                    break;
                }
                if(ev.key.code==sf::Keyboard::Enter)
                {
                    window_1.close();
                    break;
                }
            }

        }
        window_1.clear();
        window_1.draw(sp);
        menu.draw(window_1);
        window_1.display();
    }


    //le cas de jouer conter perssonne
        if(menu.menu_selected==0)
        {
            RenderWindow window(VideoMode(1000, 1000), "Chess");
            bool isMove=false;
            bool isLegal=false;
             float dx=0, dy=0;
            Vector2f oldPos,newPos;
           Piece* rt = NULL;
            bool turn = white;

         while(window.isOpen())
        {
           Event e;
           Vector2i pos = Mouse::getPosition(window);


           while (window.pollEvent(e))
          {
            if (e.type == Event::Closed)
                window.close();



            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                  for(int i=0;i<8;i++)
                   for(int j=0;j<8;j++)
                  {
                      if(b.position[i][j] == NULL) continue;
                      Sprite &s= b.position[i][j]->spr;
//On cherche la piece sur laquelle l'utilisateur a cliqu�
                        if (s.getGlobalBounds().contains(pos.x,pos.y))

                        {
                            isMove=true;
                            rt = b.position[i][j];
                            dx=pos.x - s.getPosition().x;
                            dy=pos.y - s.getPosition().y;
                            oldPos  = s.getPosition();
                        }
                    }

             if (e.type == Event::MouseButtonReleased)
                if (e.key.code == Mouse::Left)
                 {
                  isMove=false;
                  Vector2f p = rt->spr.getPosition() + Vector2f(sizespr/2,sizespr/2);
                  newPos = Vector2f( sizespr*int(p.x/sizespr), sizespr*int(p.y/sizespr) );
                  Move m(rt, newPos.y/sizespr , newPos.x/sizespr ,0);
                  //verifier si le coup est autoris�
                  if(m.is_Legal(b, turn))
                  {
                     b.play(m);
                     rt->spr.setPosition(newPos);
                     turn = !turn;
                  }

                  else
                  rt->spr.setPosition(oldPos);
            }
               if (isMove) rt->spr.setPosition(pos.x-dx,pos.y-dy);
        window.draw(b.spr);
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(b.position[i][j] == NULL) continue;

                Sprite &s = b.position[i][j]->spr;
                window.draw(s);
            }
            window.display();
         }


        }

    }
    else{
            //quitter le jeu
            if(menu.menu_selected==2)
            {
                 exit(1);

            }
          //partie  contre pc
        else{


         RenderWindow window(VideoMode(1000, 1000), "Chess");
            bool isMove=false;
            bool isLegal=false;
             float dx=0, dy=0;
            Vector2f oldPos,newPos;
           Piece* rt = NULL;
            bool turn = white;
            bool player_turn = white;

       while(window.isOpen())
      {
        Event e;
        Vector2i pos = Mouse::getPosition(window);


        while (window.pollEvent(e))//attente d'un evenement
        {
            if (e.type == Event::Closed)
                window.close();



            if (e.type == Event::MouseButtonPressed)
                if (e.key.code == Mouse::Left)
                  for(int i=0;i<8;i++)
                   for(int j=0;j<8;j++)
                  {
                      if(b.position[i][j] == NULL) continue;
                      Sprite &s= b.position[i][j]->spr;

                        if (s.getGlobalBounds().contains(pos.x,pos.y))
                        {
                            isMove=true;
                            rt = b.position[i][j];
                            dx=pos.x - s.getPosition().x;
                            dy=pos.y - s.getPosition().y;
                            oldPos  = s.getPosition();
                        }
                    }

             if (e.type == Event::MouseButtonReleased && turn==player_turn)
                if (e.key.code == Mouse::Left)
                 {
                  isMove=false;
                  Vector2f p = rt->spr.getPosition() + Vector2f(sizespr/2,sizespr/2);
                  newPos = Vector2f( sizespr*int(p.x/sizespr), sizespr*int(p.y/sizespr) );
                  Move m(rt, newPos.y/sizespr , newPos.x/sizespr ,0);
                  if(m.is_Legal(b, turn))
                  {
                     b.play(m);
                     rt->spr.setPosition(newPos);
                     turn = !turn;
                  }

                  else
                  rt->spr.setPosition(oldPos);
            }

               if (turn != player_turn)
                {
                Move m = b.Best_Move(turn, 4);
                if (m.piece==NULL)//le cas d'un echec et mat
                {
                    Texture t1;
                    t1.loadFromFile("images/checkmate.jpg");
                    Sprite sp1;
                    sp1.setTexture(t1);
                    sp1.setPosition(250,250);
                    window.draw(sp1);
                    window.display();
                    //Sleep(5000);
                    exit(1);
                }
                b.play(m);
                turn = !turn;
                m.piece->spr.setPosition(m.square[1]*sizespr, m.square[0]*sizespr);
                Liberer();
                //Sleep(500);
                }
        }


        if (isMove) rt->spr.setPosition(pos.x-dx,pos.y-dy);
        window.draw(b.spr);
        for(int i = 0; i < 8; i++)
            for(int j = 0; j < 8; j++)
            {
                if(b.position[i][j] == NULL) continue;

                Sprite &s = b.position[i][j]->spr;
                window.draw(s);
            }
            window.display();
    }



    }
    }
}



