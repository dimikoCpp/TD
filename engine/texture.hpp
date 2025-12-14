#pragma once
#include <string>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

// загрузить текстуру в хранилище текстур
void load_texture(int size, string name, string file);

// нарисовать текстуру на экране
void draw_texture(int X, int Y, RenderWindow& wnd, string name);
