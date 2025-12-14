#include "shrift.hpp"
#include <iostream>
using namespace std;
using namespace sf;

static Font font;

void draw_shrift(RenderWindow& screen, string txt, int x, int y, int size, Color color) {
    Text text(font);
    text.setString(txt);
    text.setPosition(Vector2f(x, y));
    text.setCharacterSize(size);
    text.setFillColor(color);
    //text.setStyle(Text::Bold | Text::Underlined);
    screen.draw(text);
}

void load_shrift(string name) {
    if (!font.openFromFile(name))
    {
        cout << "error while loading file \"" << name << "\"" << endl;
        terminate();
    }
}
