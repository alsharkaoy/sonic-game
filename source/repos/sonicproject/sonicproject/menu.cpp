#include "Menu.h"
#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
Menu::Menu(float width, float height)
{

	//if (!font.loadFromFile("C:/Windows/Font/sMonoton-Regular.ttf")){}
	font.loadFromFile("C:/Users/Home/source/repos/sonic/sonic/comic.ttf");
	//Play
	//font.loadFromFile("fonts/fontawesome-webfont.ttf");
	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Blue);
	menu[0].setString("Play");
	menu[0].setCharacterSize(50);
	menu[0].setStyle(sf::Text::Bold);
	menu[0].setPosition(sf::Vector2f(width / 2, 200));

	//About
	//font.loadFromFile("C:/Users/nasse/.vscode/extensions/ms-toolsai.jupyter-2021.6.811652604/out/datascience-ui/notebook/node_modules/font-awesome/fonts/FontAwesome.otf");
	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("About");
	menu[1].setCharacterSize(50);
	menu[1].setPosition(sf::Vector2f(width / 2, 400));

	//Exit
	//font.loadFromFile("location.ttf");
	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setCharacterSize(50);
	menu[2].setPosition(sf::Vector2f(width / 2, 600));

	main_menu_select = 0;
}

Menu::~Menu()
{

}

//Function of drawing main menu
void Menu::draw(sf::RenderWindow& window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menu[i]);
	}

}

// Move down
void Menu::movdown()
{
	if (main_menu_select + 1 <= Max_main_menu) //checkif not the last items (exit)
	{
		menu[main_menu_select].setFillColor(sf::Color::White); //change color
		main_menu_select++; //move item

		menu[main_menu_select].setFillColor(sf::Color::Blue);
	}
}

// Move up
void Menu::moveup()
{

	if (main_menu_select - 1 >= 0) //checkif not the last items (exit)
	{
		menu[main_menu_select].setFillColor(sf::Color::White); //change color
		main_menu_select--; //move item
		menu[main_menu_select].setFillColor(sf::Color::Blue);
	}



}


