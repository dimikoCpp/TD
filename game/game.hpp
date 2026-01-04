#pragma once
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;
class Core{

public:
    Core(RenderWindow& window);
    ~Core();
    void action(RenderWindow& wnd);
    void draw(RenderWindow& window);
};