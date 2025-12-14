#include <cassert>
#include "game.hpp"
#include "menu/menu.hpp"
#include "game/menu/settings.hpp" // <-- домашка

 Core::Core(RenderWindow& window) {
    //menu = new Main(window); // рабочее меню, с него копируй (game/menu/menu.cpp)
    menu = new Settings(window); // это сделать надо (game/menu/setting.cpp)
    //menu = new In_game();
}

Core::~Core() {
    delete menu;
}

void Core::action(RenderWindow& wnd) {
    assert(menu != nullptr);
    menu->action(wnd);
}

void Core::draw(RenderWindow& window){
    assert(menu != nullptr);
    menu->draw(window);
}
