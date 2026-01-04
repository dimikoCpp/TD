#pragma once
#include "menu.hpp"
#include "engine/button.hpp" 

// меню настроек игры
class Settings: public Menu {
  

public:
    Button* fps_btn {};
    Settings(RenderWindow& wnd);
    void draw(RenderWindow& wnd);
    void action(RenderWindow& wnd);
    Button* exit_btn {};
};