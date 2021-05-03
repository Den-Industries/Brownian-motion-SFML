#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include <time.h>
#include <string>
#include "view.h"
using namespace sf;
using namespace std;

class molsstuff {
public:
	float xs, ys, x, y, a;
};

int main()
{
	srand(time(NULL));
	int sw = GetSystemMetrics(SM_CXSCREEN);
	int sh = GetSystemMetrics(SM_CYSCREEN);
	int qofmols;
	bool start = false;
	bool mod1 = false;
	bool mod2 = false;
	bool mod3 = false;
	float speedmol;
	float temp = 0;
	float gasmass = 1;
	float gasmolmass;
	float molgasmolmass;
	float cs;
	float sn;
	float exity = 0;
	float r;
	float stuffy = -5;
	float cd = 0;
	float cds[10];
	int color[3];
	color[0] = 0;
	color[1] = 0;
	color[2] = 0;
	for (int i = 0; i < 10; i++) cds[i] = 0;

	Font font;
	font.loadFromFile("font.ttf");
	Text text("", font, 24);
	text.setFillColor(Color(170, 170, 170));
	text.setStyle(sf::Text::Bold);

	Image exit_image;
	exit_image.loadFromFile("images/exitimage.png");
	exit_image.createMaskFromColor(Color(255, 255, 255));
	Texture exit_t;
	exit_t.loadFromImage(exit_image);
	Sprite s_exit;
	s_exit.setTexture(exit_t);
	s_exit.setPosition(0, 0);

	Image mod1_image;
	mod1_image.loadFromFile("images/mod1image.png");
	mod1_image.createMaskFromColor(Color(255, 255, 255));
	Texture mod1_t;
	mod1_t.loadFromImage(mod1_image);
	Sprite s_mod1;
	s_mod1.setTexture(mod1_t);
	s_mod1.setPosition(0, 0);

	Image mod2_image;
	mod2_image.loadFromFile("images/mod2image.png");
	mod2_image.createMaskFromColor(Color(255, 255, 255));
	Texture mod2_t;
	mod2_t.loadFromImage(mod2_image);
	Sprite s_mod2;
	s_mod2.setTexture(mod2_t);
	s_mod2.setPosition(0, 0);

	Image mod3_image;
	mod3_image.loadFromFile("images/mod3image.png");
	mod3_image.createMaskFromColor(Color(255, 255, 255));
	Texture mod3_t;
	mod3_t.loadFromImage(mod3_image);
	Sprite s_mod3;
	s_mod3.setTexture(mod3_t);
	s_mod3.setPosition(0, 0);

	Image reset_image;
	reset_image.loadFromFile("images/resetimage.png");
	reset_image.createMaskFromColor(Color(255, 255, 255));
	Texture reset_t;
	reset_t.loadFromImage(reset_image);
	Sprite s_reset;
	s_reset.setTexture(reset_t);
	s_reset.setPosition(0, 0);

	Image di_image;
	di_image.loadFromFile("images/den industries.png");
	di_image.createMaskFromColor(Color(255, 255, 255));
	Texture di_t;
	di_t.loadFromImage(di_image);
	Sprite s_di;
	s_di.setTexture(di_t);

	Image stuff_image;
	stuff_image.loadFromFile("images/stuff.png");
	stuff_image.createMaskFromColor(Color(255, 255, 255));
	Texture stuff_t;
	stuff_t.loadFromImage(stuff_image);
	Sprite s_stuff[10];
	for (int i = 0; i < 10; i++) s_stuff[i].setTexture(stuff_t);

	Image mol_image;
	mol_image.loadFromFile("images/molecules.png");
	mol_image.createMaskFromColor(Color(255, 255, 255));
	Texture mol_t;
	mol_t.loadFromImage(mol_image);

	Sprite s_mol[9];
	for (int i = 0; i < 9; i++) s_mol[i].setTexture(mol_t);
	s_mol[0].setTextureRect(IntRect(0, 0, 85, 85));
	s_mol[1].setTextureRect(IntRect(85, 0, 85, 85));
	s_mol[2].setTextureRect(IntRect(170, 0, 85, 85));
	s_mol[3].setTextureRect(IntRect(0, 85, 85, 85));
	s_mol[4].setTextureRect(IntRect(85, 85, 85, 85));
	s_mol[5].setTextureRect(IntRect(170, 85, 85, 85));
	s_mol[6].setTextureRect(IntRect(0, 170, 85, 85));
	s_mol[7].setTextureRect(IntRect(85, 170, 85, 85));
	s_mol[8].setTextureRect(IntRect(170, 170, 85, 85));

	CircleShape shapeshow[1000];
	molsstuff stuff[1000];

	RenderWindow window(sf::VideoMode(sw, sh), "I love molecules", Style::Fullscreen);
	window.setVerticalSyncEnabled(true);
	view.reset(sf::FloatRect(0, 0, sw, sh));
	window.setPosition(Vector2i(0, 0));
	Clock clock;
	getplayercoordinateforview(int(sw / 2), int(sh / 2));
	if (true)
	{
		s_mol[0].setPosition(getviewx() - 85 - 43, getviewy() - 85 - 43);
		s_mol[1].setPosition(getviewx() - 43, getviewy() - 85 - 43);
		s_mol[2].setPosition(getviewx() + 43, getviewy() - 85 - 43);
		s_mol[3].setPosition(getviewx() - 85 - 43, getviewy() - 43);
		s_mol[4].setPosition(getviewx() - 43, getviewy() - 43);
		s_mol[5].setPosition(getviewx() + 43, getviewy() - 43);
		s_mol[6].setPosition(getviewx() - 85 - 43, getviewy() + 43);
		s_mol[7].setPosition(getviewx() - 43, getviewy() + 43);
		s_mol[8].setPosition(getviewx() + 43, getviewy() + 43);
		s_exit.setPosition(getviewx() + int(sw / 2) - 126, getviewy() - int(sh / 2));
	}
	s_di.setOrigin(127, 48);
	s_di.setPosition(getviewx(), sh - 56);
	if (!mod1)
		s_mod1.setColor(Color(205, 205, 205));
	else
		s_mod1.setColor(Color(255, 255, 255));
	if (!mod2)
		s_mod2.setColor(Color(205, 205, 205));
	else
		s_mod2.setColor(Color(255, 255, 255));
	if (!mod3)
		s_mod3.setColor(Color(205, 205, 205));
	else
		s_mod3.setColor(Color(255, 255, 255));
	while (window.isOpen())
	{
		if (start)
		{
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		if (cd < 41) cd += time;
		for (int i = 0; i < 10; i++) if (cds[i] < 101) cds[i] += time;
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			s_exit.setColor(Color::Green);
			window.draw(s_exit);
			window.display();
			Sleep(300);
			window.close();
		}
		//Данные положения курсора//
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
				if (event.key.code == Mouse::Left) {//а именно левая
					if (s_exit.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						s_exit.setColor(Color::Green);
						window.draw(s_exit);
						window.display();
						Sleep(300);
						window.close();
					}
					if (s_mod1.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						mod1 = !mod1;
						if(!mod1)
						s_mod1.setColor(Color(205, 205, 205));
						else
						s_mod1.setColor(Color(255, 255, 255));
						window.draw(s_mod1);
						window.display();
						Sleep(700);
						for (int i = 0; i < 1000; i++) shapeshow[i].setFillColor(Color(color[0], color[1], color[2]));
					}
					if (s_mod2.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						mod2 = !mod2;
						if (!mod2)
							s_mod2.setColor(Color(205, 205, 205));
						else
							s_mod2.setColor(Color(255, 255, 255));
						window.draw(s_mod2);
						window.display();
						Sleep(700);
					}
					if (s_mod3.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						mod3 = !mod3;
						if (!mod3)
							s_mod3.setColor(Color(205, 205, 205));
						else
							s_mod3.setColor(Color(255, 255, 255));
						window.draw(s_mod3);
						window.display();
						Sleep(700);
					}
					if (s_reset.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						s_reset.setColor(Color::Green);
						window.draw(s_reset);
						window.display();
						Sleep(300);
						start = false;
						for (int i = 0; i < 9; i++) s_mol[i].setColor(Color(255, 255, 255));
						s_reset.setColor(Color(255, 255, 255));
					}
					if (cds[0] > 100 && s_stuff[0].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40)
						{
							if (temp > -223) temp -= 50; else temp = -273;
							cd = 0;
							cds[0] = 0;
							speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass);
							cout << speedmol << "\n";
							for (int i = 0; i < 1000; i++)
							{
								cs = cos(stuff[i].a * 0.0175);
								sn = sin(stuff[i].a * 0.0175);
								stuff[i].xs = speedmol * cs;
								stuff[i].ys = speedmol * sn;
							}
						}
					}
					if (cds[1] > 100 && s_stuff[1].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (temp > -273 && cd > 40)
						{
							temp -= 1;
							cd = 0;
							cds[1] = 0;
							speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass);
							cout << speedmol << "\n";
							for (int i = 0; i < 1000; i++)
							{
								cs = cos(stuff[i].a * 0.0175);
								sn = sin(stuff[i].a * 0.0175);
								stuff[i].xs = speedmol * cs;
								stuff[i].ys = speedmol * sn;
							}
						}
					}
					if (cds[2] > 100 && s_stuff[2].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40)
						{
							temp += 1;
							cd = 0;
							cds[2] = 0;
							speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass);
							cout << speedmol << "\n";
							for (int i = 0; i < 1000; i++)
							{
								cs = cos(stuff[i].a * 0.0175);
								sn = sin(stuff[i].a * 0.0175);
								stuff[i].xs = speedmol * cs;
								stuff[i].ys = speedmol * sn;
							}
						}
					}
					if (cds[3] > 100 && s_stuff[3].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40)
						{
							temp += 50;
							cd = 0;
							cds[3] = 0;
							speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass);
							cout << speedmol << "\n";
							for (int i = 0; i < 1000; i++)
							{
								cs = cos(stuff[i].a * 0.0175);
								sn = sin(stuff[i].a * 0.0175);
								stuff[i].xs = speedmol * cs;
								stuff[i].ys = speedmol * sn;
							}
						}
					}
					if (cds[4] > 100 && s_stuff[4].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40 && gasmass > 1)
						{
							gasmass -= 1;
							cd = 0;
							cds[4] = 0;
							qofmols = int((gasmass / gasmolmass) * 1000);
						}
					}
					if (cds[5] > 100 && s_stuff[5].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40 && gasmass > 0.11)
						{
							gasmass -= 0.1;
							cd = 0;
							cds[5] = 0;
							qofmols = int((gasmass / gasmolmass) * 1000);
						}
					}
					if (cds[6] > 100 && s_stuff[6].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40 && qofmols < 990)
						{
							gasmass += 0.1;
							cd = 0;
							cds[6] = 0;
							qofmols = int((gasmass / gasmolmass) * 1000);
						}
					}
					if (cds[7] > 100 && s_stuff[7].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40 && qofmols < 890)
						{
							gasmass += 1;
							cd = 0;
							cds[7] = 0;
							qofmols = int((gasmass / gasmolmass) * 1000);
						}
					}
					if (cds[8] > 100 && s_stuff[8].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40)
						{
							if (temp > 217) temp -= 500; else temp = -273;
							cd = 0;
							cds[8] = 0;
							speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass);
							cout << speedmol << "\n";
							for (int i = 0; i < 1000; i++)
							{
								cs = cos(stuff[i].a * 0.0175);
								sn = sin(stuff[i].a * 0.0175);
								stuff[i].xs = speedmol * cs;
								stuff[i].ys = speedmol * sn;
							}
						}
					}
					if (cds[9] > 100 && s_stuff[9].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
					{
						if (cd > 40)
						{
							temp += 500;
							cd = 0;
							cds[9] = 0;
							speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass);
							cout << speedmol << "\n";
							for (int i = 0; i < 1000; i++)
							{
								cs = cos(stuff[i].a * 0.0175);
								sn = sin(stuff[i].a * 0.0175);
								stuff[i].xs = speedmol * cs;
								stuff[i].ys = speedmol * sn;
							}
						}
					}
				}
		}
		/*
		`````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
		```````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
		````````````````````````````````````````````````````````````````````````````````````````````````````````
		````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````
		`````````````````````````````````````````````````````````````````````````````````````````````````
		*/
		gasmass = (gasmass / 0.1) / 10;

		if (gasmass < 0.1) gasmass = 0.1;

		for (int i = 0; i < qofmols; i++)
		{
			stuff[i].x += stuff[i].xs * time / 1000;
			stuff[i].y += stuff[i].ys * time / 1000;
			if (stuff[i].x > sw + r) stuff[i].x = 0 - r + 1;
			if (stuff[i].y > sh + r) stuff[i].y = 0 - r + 1;
			if (stuff[i].x < 0 - r) stuff[i].x = sw + r - 1;
			if (stuff[i].y < 0 - r) stuff[i].y = sh + r - 1;
			shapeshow[i].setPosition(stuff[i].x, stuff[i].y);
		}


		if (mod1 == true || mod2 == true)
			for (int i = 0; i < qofmols; i++)
			{
				float min = 255;
				for (int u = 0; u < qofmols; u++)
					if (i != u)
					{
						float da = sqrt((stuff[i].x - stuff[u].x) * (stuff[i].x - stuff[u].x) + (stuff[i].y - stuff[u].y) * (stuff[i].y - stuff[u].y));
						if (da < min) min = da;
						if (min > 255) min = 255;
						if (da < r * 2 && mod2 == true) 
						{
							/*
							float vx = stuff[i].xs, vy = stuff[i].ys, nx = stuff[u].x - stuff[i].x, ny = stuff[u].y - stuff[i].y;
							stuff[u].xs = (vx + ((nx * 2 * ((vx * nx) + (vy * ny))) * -1));
							stuff[u].ys = (vy + ((ny * 2 * ((vx * nx) + (vy * ny))) * -1));
							float a1, a2;
							a1 = sqrt((stuff[u].xs * stuff[u].xs) + (stuff[u].ys * stuff[u].ys));
							a2 = a1 / speedmol;
							stuff[u].xs = stuff[u].xs / a2;
							stuff[u].ys = stuff[u].ys / a2;
							*/
							float a1, a2;
							a1 = (stuff[i].a + stuff[u].a) / 2;
							a2 = a1 + 180;
							if (a1 > 360) a1 = a1 - 360;
							if (a2 > 360) a2 = a2 - 360;
							stuff[i].a = a1;
							stuff[u].a = a2;
							cs = cos(stuff[i].a * 0.0175);
							sn = sin(stuff[i].a * 0.0175);
							stuff[i].xs = speedmol * cs;
							stuff[i].ys = speedmol * sn;
							cs = cos(stuff[u].a * 0.0175);
							sn = sin(stuff[u].a * 0.0175);
							stuff[u].xs = speedmol * cs;
							stuff[u].ys = speedmol * sn;

							float da1 = sqrt(((stuff[i].x + stuff[i].xs * time / 1000) - (stuff[u].x + stuff[u].xs * time / 1000)) * ((stuff[i].x + stuff[i].xs * time / 1000) - (stuff[u].x + stuff[u].xs * time / 1000)) + ((stuff[i].y + stuff[i].ys * time / 1000) - (stuff[u].y + stuff[u].ys * time / 1000)) * ((stuff[i].y + stuff[i].ys * time / 1000) - (stuff[u].y + stuff[u].ys * time / 1000)));
							if (da1 < da)
							{
								stuff[i].a = a2;
								stuff[u].a = a1;
								cs = cos(stuff[i].a * 0.0175);
								sn = sin(stuff[i].a * 0.0175);
								stuff[i].xs = speedmol * cs;
								stuff[i].ys = speedmol * sn;
								cs = cos(stuff[u].a * 0.0175);
								sn = sin(stuff[u].a * 0.0175);
								stuff[u].xs = speedmol * cs;
								stuff[u].ys = speedmol * sn;
							}
						}
					}
				if (mod1 == true)
				{
					int newcolor[3];
					newcolor[0] = min;
					newcolor[1] = min;
					newcolor[2] = min;
					if (color[0] - 1 < newcolor[0]) newcolor[0] = int(color[0]) - 1;
					if (color[1] - 1 < newcolor[1]) newcolor[1] = int(color[1]) - 1;
					if (color[2] - 1 < newcolor[2]) newcolor[2] = int(color[2]) - 1;
					shapeshow[i].setFillColor(Color(color[0] - (newcolor[0]), color[1] - (newcolor[1]), color[2] - (newcolor[2])));
				}
			}

		if (mod3 == true)
		{
			stuff[0].x = pos.x;
			stuff[0].y = pos.y;
		}


		/*
		
		Прогу с молекулами кодю
		for (int i = 0; i < 1000; i++)
							{
								cs = cos(stuff[i].a * 0.0175);
								sn = sin(stuff[i].a * 0.0175);
								stuff[i].xs = speedmol * cs;
								stuff[i].ys = speedmol * sn;
							}
		*/
		//cout << temp << "   " << speedmol << "   "<< stuff[2].a << "  " << stuff[2].xs << "  " << stuff[2].ys << "\n";

		window.setView(view);
		window.clear(Color(30, 30, 30, 0));
		window.getSystemHandle();

		if (pos.y > 126)
		{
			if (stuffy > -127) stuffy -= 0.3 * time;
		}
		else
			if (stuffy < -2) stuffy += 0.6 * time;

		s_stuff[0].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87, getviewy() - int(sh / 2) + 56 + stuffy);
		s_stuff[1].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87 + 58, getviewy() - int(sh / 2) + 56 + stuffy);
		s_stuff[2].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87 + 87, getviewy() - int(sh / 2) + 56 + stuffy);
		s_stuff[3].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87 + 116, getviewy() - int(sh / 2) + 56 + stuffy);
		s_stuff[4].setPosition(getviewx() - int(sw / 2) + int(sw / 455), getviewy() - int(sh / 2) + 85 + stuffy);
		s_stuff[5].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 58, getviewy() - int(sh / 2) + 85 + stuffy);
		s_stuff[6].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87, getviewy() - int(sh / 2) + 85 + stuffy);
		s_stuff[7].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 116, getviewy() - int(sh / 2) + 85 + stuffy);
		s_stuff[8].setPosition(getviewx() - int(sw / 2) + int(sw / 455), getviewy() - int(sh / 2) + 56 + stuffy);
		s_stuff[9].setPosition(getviewx() - int(sw / 2) + int(sw / 455) + 87 + 116 + 58, getviewy() - int(sh / 2) + 56 + stuffy);

		/*
	s_stuff.setTextureRect(IntRect(0, 0, 57, 28));
	s_stuff1.setTextureRect(IntRect(57, 0, 28, 28));
	s_stuff2.setTextureRect(IntRect(85, 0, 28, 28));
	s_stuff3.setTextureRect(IntRect(113, 0, 57, 28));
	s_stuff4.setTextureRect(IntRect(0, 0, 57, 28));
	s_stuff5.setTextureRect(IntRect(57, 0, 28, 28));
	s_stuff6.setTextureRect(IntRect(85, 0, 28, 28));
	s_stuff7.setTextureRect(IntRect(113, 0, 57, 28));
		*/

		if (cds[0] < 100) s_stuff[0].setTextureRect(IntRect(0, 29, 57, 28)); else s_stuff[0].setTextureRect(IntRect(0, 0, 57, 28));
		if (cds[1] < 100) s_stuff[1].setTextureRect(IntRect(57, 29, 28, 28)); else s_stuff[1].setTextureRect(IntRect(57, 0, 28, 28));
		if (cds[2] < 100) s_stuff[2].setTextureRect(IntRect(85, 29, 28, 28)); else s_stuff[2].setTextureRect(IntRect(85, 0, 28, 28));
		if (cds[3] < 100) s_stuff[3].setTextureRect(IntRect(113, 29, 57, 28)); else s_stuff[3].setTextureRect(IntRect(113, 0, 57, 28));
		if (cds[4] < 100) s_stuff[4].setTextureRect(IntRect(0, 29, 57, 28)); else s_stuff[4].setTextureRect(IntRect(0, 0, 57, 28));
		if (cds[5] < 100) s_stuff[5].setTextureRect(IntRect(57, 29, 28, 28)); else s_stuff[5].setTextureRect(IntRect(57, 0, 28, 28));
		if (cds[6] < 100) s_stuff[6].setTextureRect(IntRect(85, 29, 28, 28)); else s_stuff[6].setTextureRect(IntRect(85, 0, 28, 28));
		if (cds[7] < 100) s_stuff[7].setTextureRect(IntRect(113, 29, 57, 28)); else s_stuff[7].setTextureRect(IntRect(113, 0, 57, 28));
		if (cds[8] < 100) s_stuff[8].setTextureRect(IntRect(256, 29, 86, 28)); else s_stuff[8].setTextureRect(IntRect(256, 0, 86, 28));
		if (cds[9] < 100) s_stuff[9].setTextureRect(IntRect(170, 29, 86, 28)); else s_stuff[9].setTextureRect(IntRect(170, 0, 86, 28));

		for (int i = 0; i < qofmols; i++) window.draw(shapeshow[i]);
		s_exit.setPosition(getviewx() + int(sw / 2) - 126, getviewy() - int(sh / 2) + stuffy);
		window.draw(s_exit);
		s_reset.setPosition(getviewx() + int(sw / 2) - 126 - 126, getviewy() - int(sh / 2) + stuffy);
		window.draw(s_reset);
		s_mod1.setPosition(getviewx() + int(sw / 2) - 126 - 126 - 126, getviewy() - int(sh / 2) + stuffy);
		window.draw(s_mod1);
		s_mod2.setPosition(getviewx() + int(sw / 2) - 126 - 126 - 126 - 126, getviewy() - int(sh / 2) + stuffy);
		window.draw(s_mod2);
		s_mod3.setPosition(getviewx() + int(sw / 2) - 126 - 126 - 126 - 126 - 126, getviewy() - int(sh / 2) + stuffy);
		window.draw(s_mod3);
			;
		std::ostringstream thing;
		thing << "Temp ";
		thing << int(temp);
		thing << " C";
		text.setString(thing.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		text.setPosition(getviewx() - int(sw / 2) + int(sw / 455), getviewy() - int(sh / 2) + stuffy);//задаем позицию текста, отступая от центра камеры
		window.draw(text);

		std::ostringstream thing1;
		thing1 << "Mass ";
		thing1 << gasmass;
		thing1 << " kg";
		text.setString(thing1.str());//задаем строку тексту и вызываем сформированную выше строку методом .str() 
		text.setPosition(getviewx() - int(sw / 2) + int(sw / 455), getviewy() - int(sh / 2) + 28 + stuffy);//задаем позицию текста, отступая от центра камеры
		window.draw(text);

		for (int i = 0; i < 10; i++) window.draw(s_stuff[i]);
		window.display();
		}
		else
		{	
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			s_exit.setColor(Color::Green);
			window.draw(s_exit);
			window.display();
			Sleep(300);
			window.close();
		}
		//Данные положения курсора//
		Vector2i pixelPos = Mouse::getPosition(window);
		Vector2f pos = window.mapPixelToCoords(pixelPos);
		Event event;
		while (window.pollEvent(event))
	{	
		if (event.type == sf::Event::Closed)
			window.close();
		if (event.type == Event::MouseButtonPressed)//если нажата клавиша мыши
			if (event.key.code == Mouse::Left) {//а именно левая
			if (s_exit.getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
			{
				s_exit.setColor(Color::Green);
				window.draw(s_exit);
				window.display();
				Sleep(300);
				window.close();
			}
				for (int i = 0; i < 9; i++) if (s_mol[i].getGlobalBounds().contains(pos.x, pos.y))//и при этом координата курсора попадает в спрайт
				{
					s_mol[i].setColor(Color::Red);
					window.draw(s_mol[i]);
					window.display();
					Sleep(500);
					gasmass = 1;
					temp = 0;
					int mol;
					mol = i + 1;
					switch (mol)
					{
					case 1:
						gasmolmass = 6.6;
						molgasmolmass = 4;
						r = 4;
					break;
					case 2:
						gasmolmass = 3.3;
						molgasmolmass = 2;
						r = 5;
					break;
					case 3:
						gasmolmass = 26.7;
						molgasmolmass = 32;
						r = 6;
					break;
					case 4:
					gasmolmass = 46, 5;
					molgasmolmass = 28;
					r = 6.5;
					break;
				case 5:
					gasmolmass = 73;
					molgasmolmass = 44;
					r = 7;
					break;
				case 6:
					gasmolmass = 100;
					molgasmolmass = 64;
					r = 7;
					break;
				case 7:
					gasmolmass = 58;
					molgasmolmass = 71;
					r = 7.5;
					break;
				case 8:
					gasmolmass = 28.3;
					molgasmolmass = 17;
					r = 10;
					break;
				case 9:
					gasmolmass = 26.6;
					molgasmolmass = 16;
					r = 5;
					break;
				}
				qofmols = int((gasmass / gasmolmass) * 1000);
				speedmol = (sqrt(3 * (temp + 273)) * 0.4175 * 1.17) / sqrt(molgasmolmass);
				for (int i = 0; i < 1000; i++)
				{
					shapeshow[i].setRadius(r);
					switch (mol)
					{
					case 1:
						color[0] = 60;
						color[1] = 197;
						color[2] = 255;
						shapeshow[i].setFillColor(Color(60, 197, 255));
						break;
					case 2:
						color[0] = 255;
						color[1] = 159;
						color[2] = 190;
						shapeshow[i].setFillColor(Color(255, 159, 190));
						break;
					case 3:
						color[0] = 153;
						color[1] = 217;
						color[2] = 234;
						shapeshow[i].setFillColor(Color(153, 217, 234));
						break;
					case 4:
						color[0] = 193;
						color[1] = 193;
						color[2] = 193;
						shapeshow[i].setFillColor(Color(193, 193, 193));
						break;
					case 5:
						color[0] = 138;
						color[1] = 130;
						color[2] = 142;
						shapeshow[i].setFillColor(Color(138, 130, 142));
						break;
					case 6:
						color[0] = 255;
						color[1] = 249;
						color[2] = 128;
						shapeshow[i].setFillColor(Color(255, 249, 128));
						break;
					case 7:
						color[0] = 47;
						color[1] = 215;
						color[2] = 97;
						shapeshow[i].setFillColor(Color(47, 215, 97));
						break;
					case 8:
						color[0] = 191;
						color[1] = 129;
						color[2] = 254;
						shapeshow[i].setFillColor(Color(191, 129, 254));
						break;
					case 9:
						color[0] = 295;
						color[1] = 155;
						color[2] = 89;
						shapeshow[i].setFillColor(Color(255, 155, 89));
						break;
					}
					shapeshow[i].setOrigin(r, r);
					stuff[i].x = rand() % 1336;
					stuff[i].y = rand() % 768;
					shapeshow[i].setPosition(stuff[i].x, stuff[i].y);
					if (true)
					{
						stuff[i].a = rand() % 360;
						cs = cos(stuff[i].a * 0.0175);
						sn = sin(stuff[i].a * 0.0175);
						stuff[i].xs = speedmol * cs;
						stuff[i].ys = speedmol * sn;
					}
				}
				start = true;
				stuffy = -2;
			}
		}
		}

		window.setView(view);
		window.clear(Color(30, 30, 30, 0));
		window.getSystemHandle();

		window.draw(s_exit);
		window.draw(s_di);
		for (int i = 0; i < 9; i++) window.draw(s_mol[i]);
		
		window.display();
		}
	}

	return 0;
}