#define Max_main_menu 3
#include <SFML/Graphics.hpp>
//#include <windows.h>

class Menu
{

public :
    int menu_selected;
    Menu(float width ,float hight);
    void draw(sf::RenderWindow &window);
    void move_up();
    void move_down();
    ~Menu(){};
private :

    sf::Font font;
    sf::Text mainmenu[Max_main_menu];


};


