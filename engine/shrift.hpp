#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

// нарисовать текст на экране
void draw_shrift(RenderWindow& screen, string txt, int x, int y, int size=32, Color color=Color::White);

// загрузить шрифт с диска
void load_shrift(string name);
