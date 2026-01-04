#pragma once
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Button;

class Menu {
public:
    virtual ~Menu() = default;
    virtual void draw(RenderWindow& wnd) = 0;
    virtual void action(RenderWindow& wnd) = 0;
};

// главное меню игры
class Main: public Menu {
    Button* play {};
    Button* exit {};
    Button* settings {};
    uint64_t counter = 0;

public:
    Main(RenderWindow& wnd);
    void draw(RenderWindow& wnd);
    void action(RenderWindow& wnd);
};

