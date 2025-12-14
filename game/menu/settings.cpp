#include "settings.hpp"
#include "engine/texture.hpp"
#include "core/consts.hpp"

Settings::Settings(RenderWindow& wnd) {
    load_texture(10, "sound", "data/sound+-.png");
    load_texture(10, "fps1", "data/30 fps.png");
    load_texture(10, "fps2", "data/60 fps.png");
    load_texture(10, "fps3", "data/150 fps.png");
    load_texture(10, "fps4", "data/225 fps.png");
    load_texture(10, "fps5", "data/300 fps.png");
}

void Settings::draw(RenderWindow& wnd) {
    draw_texture(X/2, Y/2, wnd, "fps1");
}

void Settings::action(RenderWindow& wnd) {
    // действия
}
