#pragma once
#include "menu.hpp"

// меню настроек игры
class Settings: public Menu {
public:
    Settings(RenderWindow& wnd);
    void draw(RenderWindow& wnd);
    void action(RenderWindow& wnd);
};