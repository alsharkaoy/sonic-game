#include <string>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include "Menu.h" 
#include<SFML/Graphics.hpp>
#include<SFML/Audio.hpp>
#include<iostream>
#include<sstream>
#include<string>z

using namespace sf;
using namespace std;

const int gravity = 500;
bool onground = false;
float inair;
float maxinair = 0.3f;


static const float hight = 600.0f;



void resizeview(const sf::RenderWindow& window, sf::View& view) {
	float c = float(window.getSize().x) / float(window.getSize().y);
	view.setSize(hight * c, hight);
}

//void sound(SoundBuffer Beginning, Sound beginning) {
//	
//	/*Buffer.loadFromFile("M:/2013.10.16_sonic&knuckles_sfml_beta (1)/Sonic & Knuckles SFML (Beta 2013.10.16)/data/ogg/musics/boss.ogg");*/
//	Beginning.loadFromFile("M:/2013.10.16_sonic&knuckles_sfml_beta (1)/Sonic & Knuckles SFML (Beta 2013.10.16)/data/ogg/musics/zone_1.ogg");
//
//	beginning.setBuffer(Beginning);
//	beginning.setVolume(20);
//	beginning.play();
//	beginning.setLoop(true);
//	
//}





int main() {




	sf::RenderWindow window(sf::VideoMode(600, 754), "sonic");
	sf::Texture ture;
	ture.loadFromFile("M:/new.png");
	sf::Sprite player(ture);

	Menu menu(window.getSize().x, window.getSize().y);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					menu.moveup();
					break;
				case sf::Keyboard::Down:
					menu.movdown();
					break;
				case sf::Keyboard::Return:
					window.close();
					switch (menu.mainmenuPressed())
						/////////////////////////////////////****where are you ********************///////////////////////////
					{
					case 0: {



						int x = 9, y = 0, score = 0, coinanimation = 0, coinanimation1 = 0, coinanimation2 = 0, coinanimation3 = 0,score2=0,b=0;
						int cnt = 40;
						int monsteranimation1 = 0, monster = 0;
						
						RenderWindow window(VideoMode(600, 600), "Sonic");

						window.setFramerateLimit(20);

						int c = 0;
						bool gravity = true;
						bool move = true;

						sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(hight, hight));
						View view2;
						Texture sonic, monster1, sscore, sonic2, landscapeTexture, cloudsTexture, power_texture, run_texture;

						////coin sound 
						SoundBuffer Beginning;
						Beginning.loadFromFile("M:/m.ogg");
						Sound  beginning;
						beginning.setBuffer(Beginning);
						beginning.setVolume(20);
					

						
						

						//monster sound 
						SoundBuffer s_monster;
						s_monster.loadFromFile("M:/2013.10.16_sonic&knuckles_sfml_beta (1)/Sonic & Knuckles SFML (Beta 2013.10.16)/data/ogg/sounds/brrr.ogg");
						Sound  smonster;
						smonster.setBuffer(s_monster);
						smonster.setVolume(20);

						sonic.loadFromFile("M:/movesonic.png");
						sonic2.loadFromFile("M:/sonic.png");

						Sprite bsonic;
						bsonic.setTexture(sonic2);
						bsonic.setPosition(100, 382);
						Sprite sprite1;//       ”ждня 


						Texture Ground[18];
						Sprite ground[18];

						for (int i = 0; i < 18; i++)
						{
							Ground[0].loadFromFile("m:/ground/ground1.png");
							ground[0].setPosition(50, 0);

							Ground[1].loadFromFile("m:/ground/ground2-1.png");
							ground[1].setPosition(3569, 0);

							Ground[2].loadFromFile("m:/ground/ground2-2.png");
							ground[2].setPosition(3637, 0);

							Ground[3].loadFromFile("m:/ground/ground2-3.png");
							ground[3].setPosition(3771, 0);

							Ground[4].loadFromFile("m:/ground/ground3.png");
							ground[4].setPosition(3803, 0);

							Ground[5].loadFromFile("m:/ground/ground4-1.png");
							ground[5].setPosition(5575, 0);

							Ground[6].loadFromFile("m:/ground/ground4-2.png");
							ground[6].setPosition(5607, 0);

							Ground[7].loadFromFile("m:/ground/ground4-3.png");
							ground[7].setPosition(5741, 0);

							Ground[8].loadFromFile("m:/ground/ground5.png");
							ground[8].setPosition(5810, -15);

							Ground[9].loadFromFile("m:/ground/ground6.png");
							ground[9].setPosition(9370, -15);

							Ground[10].loadFromFile("m:/ground/ground7.png");
							ground[10].setPosition(9665, -15);

							Ground[11].loadFromFile("m:/ground/ground8.png");
							ground[11].setPosition(12150, -15);

							Ground[12].loadFromFile("m:/ground/ground9.png");
							ground[12].setPosition(12585, -15);

							Ground[13].loadFromFile("m:/ground/ground2-1.png");
							ground[13].setPosition(14367, -55);

							Ground[14].loadFromFile("m:/ground/ground2-2.png");
							ground[14].setPosition(14435, -55);

							Ground[15].loadFromFile("m:/ground/ground2-3.png");
							ground[15].setPosition(14569, -55);

							Ground[16].loadFromFile("m:/ground/ground11.png");
							ground[16].setPosition(14600, -15);


							Ground[17].loadFromFile("m:/ground/ground1.png");
							ground[17].setPosition(-500, 0);


							ground[i].setTexture(Ground[i]);
						}
						/*
						Texture g;
						g.loadFromFile("M:/ground/uground3.png");
						Sprite g1;
						g1.setTexture(g);
						g1.setPosition(3700,500);

						*/

						Sprite landscape;
						landscapeTexture.loadFromFile("M:/landscape.png");
						landscape.setTexture(landscapeTexture);
						landscape.setScale(Vector2f(1000.0f, 1000.0f));
						landscape.setPosition(-500.0f, -450.0f);

						Sprite clouds[11];

						for (int i = 0; i < 10; i++)
						{
							cloudsTexture.loadFromFile("C:/Users/Home/Downloads/clouds.png");
							clouds[i].setTexture(cloudsTexture);
							clouds[10].setPosition(-180.0f, -150.0f);
							clouds[0].setPosition(-150.0f, -150.0f);
							clouds[1].setPosition(1200.0f, -150.0f);
							clouds[2].setPosition(2500.0f, -150.0f);
							clouds[3].setPosition(3800.0f, -150.0f);
							clouds[4].setPosition(4900.f, -150.0f);
							clouds[5].setPosition(5600.f, -150.0f);
							clouds[6].setPosition(7800.f, -150.0f);
							clouds[7].setPosition(9000.f, -150.0f);
							clouds[8].setPosition(12000.f, -150.0f);
							clouds[9].setPosition(14000.f, -120.0f);
							clouds[10].setPosition(-180.0f, -150.0f);

						}

						
						power_texture.loadFromFile("C:/Users/Home/Downloads/power1.png");
						IntRect r(116.6 * 4, 116.6 * 2, 116.6, 116.6);
						Sprite power(power_texture, r);
						power.setPosition(700, 150);


						run_texture.loadFromFile("C:/Users/Home/Downloads/run.png");
						Sprite run_sprite;

						int counter = 0;  //counter
						sprite1.setTexture(sonic);
						sprite1.setTextureRect(IntRect(x * 160, 0, 120, 168));
						sprite1.setPosition(100, 86);//      ”ждня
						//sprite.setScale(sf::Vector2f(2, 3));
						sprite1.setOrigin(60, 0);//      ”ждня    
						//sprite.setTextureRect(IntRect(1 * 175, 0, 175, 175));


						bool mons = true;
						monster1.loadFromFile("M:/m1.png");//жЌ‘ 1
						IntRect mon1(105, 0, 105, 100);
						Sprite m1(monster1, mon1);
						m1.setPosition(600, 200);
						m1.setOrigin(100, 100);

						Texture Coin;
						
						Sprite coin[21];
						

						for (size_t i = 0; i < 20; i++)
						{
							Coin.loadFromFile("M:/coin.png");//«бяжнд
							coin[i].setTexture(Coin);
							coin[i].setTextureRect(IntRect(48, 0, 48, 47));

							coin[0].setPosition(300, 150);
							coin[1].setPosition(400, 150);
							coin[2].setPosition(500, 150);
							coin[3].setPosition(600, 150);
							coin[4].setPosition(1000, 150);
							coin[5].setPosition(1400, 150);
							coin[6].setPosition(1600, 150);
							coin[7].setPosition(1800, 150);
							coin[8].setPosition(2000, 150);
							coin[9].setPosition(3000, 150);
							coin[10].setPosition(3200, 150);
							coin[11].setPosition(3400, 150);
							coin[12].setPosition(5000, 150);
							coin[13].setPosition(5200, 150);
							coin[14].setPosition(6000, 150);
							coin[15].setPosition(6200, 150);
							coin[16].setPosition(6400, 150);
							coin[17].setPosition(6800, 150);
							coin[18].setPosition(10000, 150);
							coin[19].setPosition(10200, 150);
							coin[20].setPosition(10300, 150);
						}
						Clock t, tim, clock;
						bool draw[20];
						for (size_t i = 0; i < 20; i++)
						{
							draw[i] = true;
						}
					    //bool draw1 = true;
						bool draw2 = true;
						bool draw3 = true;
						bool draw4 = true;



						//vector<sf::Sprite>ground;

						Font font;
						font.loadFromFile("C:/Users/Home/source/repos/sonic/sonic/comic.ttf");

						Text text;
						text.setFont(font);
						text.setString("score:" + std::to_string(score));
						text.setCharacterSize(36);
						text.setFillColor(sf::Color(255, 215, 0));
						text.setPosition(-190, -215);


						Font font2;
						font.loadFromFile("C:/Users/Home/source/repos/sonic/sonic/comic.ttf");

						Text text2;
						text2.setFont(font2);
						text2.setString("YOUR HIGH SCORE:" + std::to_string(score));
						text2.setCharacterSize(36);
						text2.setFillColor(sf::Color(255, 215, 0));
						text2.setPosition(1600, -100);


						SoundBuffer buffer1;
						buffer1.loadFromFile("M:/2013.10.16_sonic&knuckles_sfml_beta (1)/Sonic & Knuckles SFML (Beta 2013.10.16)/data/ogg/musics/zone_1.ogg");
						Sound buffer2;
						buffer2.setBuffer(buffer1);
						buffer2.setVolume(20);
						buffer2.play();

						


						while (window.isOpen())
						{
							float dt = clock.restart().asSeconds();

							Event event;
							while (window.pollEvent(event))
							{
								switch (event.type)
								{
								case Event::Closed:
									window.close();
									break;
								case Event::Resized:
									resizeview(window, view);
								case Event::KeyReleased:
									switch (event.key.code)
									{
									case(Keyboard::Space):
										sprite1.move(0, -17);
										text.move(0, -17);
										break;
									}


									//resizeview(window, view2);
									break;

								}





								/*if (tim.getElapsedTime().asSeconds() > 1.0f)
								{
									m1.setTexture(monster1);
									xx++;
									y = 0;



									m1.setTextureRect(IntRect(xx * 105, 0, 105, 100));
									m1.move(10, 0);
								}*/
								if (Keyboard::isKeyPressed(Keyboard::Space) && cnt >= 36) {
									cnt = 0;
								}


								if (Keyboard::isKeyPressed(Keyboard::Right) && sprite1.getPosition().x < 16500 && move == true)
								{
									move = true;
									sprite1.setScale(1, 1);

									sprite1.setTexture(sonic);

									x++;
									y = 1;
									x = x % 12;

									sprite1.setTextureRect(IntRect(x * 160, 0, 120, 168));
									if (x <= 8) {
										sprite1.move(10, 0);
										text.move(10, 0);
									}
									else if (8 < x < 12) {
										sprite1.move(15, 0);
										text.move(15, 0);
									}
									/*	if (ground.getPosition().x > -100) {
											ground.move(20, 0);
										}*/



									for (size_t i = 0; i < 20; i++)
									{
										if (sprite1.getGlobalBounds().intersects(coin[i].getGlobalBounds()) && draw[i] == true) {
											draw[i] = false;
											score++;
									
											beginning.play();

										}
									}
									

								





									if (sprite1.getGlobalBounds().intersects(ground[2].getGlobalBounds())) {
										sprite1.move(10, 20);
										text.move(10, 20);
									}

									if (sprite1.getGlobalBounds().intersects(ground[6].getGlobalBounds())) {
										sprite1.move(10, -20);
										text.move(10, -20);
									}

									if (sprite1.getGlobalBounds().intersects(ground[9].getGlobalBounds())) {
										sprite1.move(10, 8);
										text.move(10, 8);
									}
									if (sprite1.getGlobalBounds().intersects(ground[11].getGlobalBounds())) {
										sprite1.move(10, -8);
										text.move(10, -8);
									}
									if (sprite1.getGlobalBounds().intersects(ground[14].getGlobalBounds())) {
										sprite1.move(10, 20);
										text.move(10, 20);
									}
								}






								if (Keyboard::isKeyPressed(Keyboard::Left) && sprite1.getPosition().x > -300 && move == true)
								{

									sprite1.setScale(-1, 1);
									move = true;




									sprite1.setTexture(sonic);

									x++;
									y = 0;
									x = x % 12;

									sprite1.setTextureRect(IntRect(x * 160, 0, 120, 168));
									if (x <= 8) {
										sprite1.move(-10, 0);
										text.move(-10, 0);
									}
									else if (8 < x < 12) {
										sprite1.move(-15, 0);
										text.move(-15, 0);
									}
									for (size_t i = 0; i < 20; i++)
									{
										if (sprite1.getGlobalBounds().intersects(coin[i].getGlobalBounds()) && draw[i] == true) {
											draw[i] = false;
											score++;
											beginning.play();

										}
									}
									




									if (sprite1.getGlobalBounds().intersects(ground[2].getGlobalBounds())) {
										sprite1.move(-10, -20);
										text.move(-10, -20);
									}
									if (sprite1.getGlobalBounds().intersects(ground[6].getGlobalBounds())) {
										sprite1.move(-10, 20);
										text.move(-10, 20);
									}
									if (sprite1.getGlobalBounds().intersects(ground[9].getGlobalBounds())) {
										sprite1.move(-10, -8);
										text.move(-10, -8);
									}
									if (sprite1.getGlobalBounds().intersects(ground[11].getGlobalBounds())) {
										sprite1.move(-10, 8);
										text.move(-10, 8);
									} 
									if (sprite1.getGlobalBounds().intersects(ground[14].getGlobalBounds())) {
										sprite1.move(-10, -20);
										text.move(-10, -20);
									}

									




									

									for (size_t i = 0; i < 20; i++)
									{
										if (sprite1.getGlobalBounds().intersects(coin[i].getGlobalBounds()) && draw[i] == true) {
											draw[i] = false;
											score++;
											beginning.play();

										}
									}


								}



								if (sprite1.getGlobalBounds().intersects(m1.getGlobalBounds()) && sprite1.getPosition().y + 150 < m1.getPosition().y && mons == true&& move == true)
								{
							        c = 1;
								    mons = false;
									smonster.play();
								}
								if (sprite1.getGlobalBounds().intersects(m1.getGlobalBounds()) && c==0)
								{
									sprite1.setPosition(100, 86);
									text.setPosition(-190, -215);
									draw2 = false;
								}
								if (sprite1.getGlobalBounds().intersects(power.getGlobalBounds()) && draw4 == true)
								{
									power.setScale(5.1, 5.1);
									if (event.key.code == Keyboard::Right) {
										sprite1.setTexture(sonic);

										b = 22;
										b++;
										y = 0;
										b = b % 29;

										sprite1.setTextureRect(IntRect(b * 160, 0, 120, 168));
										
											sprite1.move(100, 0);
											text.move(100, 0);
									}
									
									draw4 = false;


								}


								score2 = score * 100;

							}


							for (size_t i = 0; i < 21; i++)
							{


								coin[i].setTextureRect(sf::IntRect(coinanimation * 48, 0, 48, 47));
								coinanimation++;
								coinanimation %= 4;
							}

							/*	m1.setTextureRect(sf::IntRect(monsteranimation1 * 105, 0, 105, 100));
								monsteranimation1++;
								monsteranimation1 %= 4;*/


								//move(playervelocity, dt);



							monster++;

							if (monster < 31) {
								m1.setScale(1, 1);
								m1.move(10, 0);
							}
							else if (monster > 31 && monster < 62) {
								m1.setScale(-1, 1);
								m1.move(-10, 0);
							}
							else if (monster == 62) {
								monster = 0;
							}

							if (sprite1.getPosition().x > 16000) {
								sprite1.move(-10, 0);
							}


							/*move(playervelocity, dt);*/

							text.setString("score:" + std::to_string(score));


							/*if (sprite1.getPosition().x > 300 && sprite1.getPosition().x < 16000)*/ {
								view.setCenter(sprite1.getPosition());
							}
							/*view2.setViewport(text.setPosition(0,0));*/

							//gravity
							if (sprite1.getGlobalBounds().intersects(ground[0].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[1].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[2].getGlobalBounds()) ||
								sprite1.getGlobalBounds().intersects(ground[3].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[4].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[5].getGlobalBounds()) ||
								sprite1.getGlobalBounds().intersects(ground[6].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[7].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[8].getGlobalBounds()) ||
								sprite1.getGlobalBounds().intersects(ground[9].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[10].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[11].getGlobalBounds()) ||
								sprite1.getGlobalBounds().intersects(ground[12].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[13].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[14].getGlobalBounds())
								|| sprite1.getGlobalBounds().intersects(ground[15].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[16].getGlobalBounds()) || sprite1.getGlobalBounds().intersects(ground[17].getGlobalBounds())) {
								sprite1.move(0, -40);
							}


							/*for (int i = 0; i < 18; i++)
							{
								if (sprite1.getGlobalBounds().intersects(ground[i].getGlobalBounds()))
								{
									sprite1.move(0, -40);
								}
							}*/


							//jump
							if (cnt < 36) {
								cnt++;
								sprite1.move(0, (cnt - 18));
								text.move(0, (cnt - 18));
							}

							if (sprite1.getPosition().x > 16000) {
								move = false;
							}
							
							if (sprite1.getPosition().x > 16000) {
								draw3 = false;
								
							}


							window.clear();
							window.setView(view);
							//window.setView(view2);

							//window.setView(g);

							//gravity
							if (sprite1.getPosition().x > -500) {
								sprite1.move(0, 40);
							}
							if (sprite1.getPosition().y > 600) {
								sprite1.move(0, 40);
							}

							window.draw(landscape);
							////if (draw3 == false) {
							//	window.draw(text2);
							//}*/
							window.draw(text2);

							for (size_t i = 0; i < 11; i++)
							{
								window.draw(clouds[i]);
							}
							for (size_t i = 0; i < 21; i++)
							{
								if (draw[i] == true)
									window.draw(coin[i]);
							}
							///*if (draw1 == true)
							//	window.draw(sprite3);
							//if (draw2 == true)
							//	window.draw(sprite4);
							//if (draw3 == true)*/
							//	window.draw(sprite5);
							
							if (mons == true)
								window.draw(m1);
							window.draw(sprite1);
							window.draw(text);
							

							window.draw(run_sprite);

							if (draw4 == true)
							{
								window.draw(power);
							}

							/*window.draw(ground1);*/
							for (int i = 0; i < 18; i++)
							{
								window.draw(ground[i]);
							}
							
							window.display();

						}
						system("pause");




					}
						  break;

					case 1:
						std::cout << "pressed option" << std::endl;
						break;
					case 2:
						window.close();
						break;
					}
					break;
				}

				break;

			case sf::Event::Closed:
				window.close();
				break;

			}

		}



		window.clear();
		//menu.draw(window);
		window.draw(player);
		menu.draw(window);
		window.display();




	}

	return 0;
}















