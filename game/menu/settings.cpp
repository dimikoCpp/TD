#include "settings.hpp"
#include "engine/texture.hpp"
#include "core/consts.hpp"
#include <iostream>

using namespace std;

struct fps_struct {
    string tex_name {};
    int real_fps {};

    inline fps_struct(string name, int fps): tex_name{name}, real_fps{real_fps} {}
};

static vector<fps_struct> fps_structs;
static size_t index = 0;

Settings::Settings(RenderWindow& wnd) {
    load_texture(10, "sound", "data/sound+-.png");
    load_texture(10, "fps1", "data/30 fps.png");
    load_texture(10, "fps2", "data/60 fps.png");
    load_texture(10, "fps3", "data/150 fps.png");
    load_texture(10, "fps4", "data/225 fps.png");
    load_texture(10, "fps5", "data/300 fps.png");

    fps_structs.push_back(fps_struct("fps1", 30));
    fps_structs.push_back(fps_struct("fps2", 60));
    fps_structs.push_back(fps_struct("fps3", 150));
    fps_structs.push_back(fps_struct("fps4", 225));
    fps_structs.push_back(fps_struct("fps5", 300));

    auto exit_from_game = [this]{
        if(index== 4){
            index = -1;
        }
        ++index;
        fps_btn->set_texture(fps_structs[index].tex_name);
    };

    fps_btn = new Button({X/2, Y/2, 200, 200},
        fps_structs[index].tex_name, exit_from_game);
}
    

void Settings::draw(RenderWindow& wnd) {
    fps_btn->draw(wnd);
}

void Settings::action(RenderWindow& wnd) {
    fps_btn->action(wnd);
}
