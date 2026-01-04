#include <cassert>
#include "game.hpp"
#include "scene.hpp"

Core::Core(RenderWindow& wnd) {
    sc_goto("main_menu", wnd);
}

Core::~Core() {
}

void Core::action(RenderWindow& wnd) {
    sc_action(wnd);
}

void Core::draw(RenderWindow& wnd){
    sc_draw(wnd);
}
