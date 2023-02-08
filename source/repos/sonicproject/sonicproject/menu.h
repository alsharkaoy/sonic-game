#pragma once
#include <SFML/GpuPreference.hpp>
#include <SFML/Graphics.hpp>
#include <string>
#define Max_main_menu 3

class  Menu {

public:
	Menu(float width, float height);

	~Menu();


	void draw(sf::RenderWindow& window);
	void moveup();
	void movdown();
	int mainmenuPressed() { return main_menu_select; }



private:
	int main_menu_select;
	sf::Font font;
	sf::Text menu[Max_main_menu];
};



