#pragma once
#include "menu.hpp"
#include "engine/button.hpp" 

// меню настроек игры
class Settings: public Menu {
    Button* fps_btn {};

public:
    Settings(RenderWindow& wnd);
    void draw(RenderWindow& wnd);
    void action(RenderWindow& wnd);
};