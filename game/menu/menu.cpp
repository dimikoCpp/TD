#include <cmath>
#include "menu.hpp"
#include "../../core/consts.hpp"
#include "../../engine/button.hpp"
#include "../../engine/texture.hpp"
#include "../../game/scene.hpp"
using namespace sf;

// сделать курсор мышки
static void set_mouse_cursor(RenderWindow& wnd) {
    // установка своего курсора
    Texture texture;
    auto result = texture.loadFromFile("data/better_cursor.png");
    if (!result)
        throw runtime_error("texture not loaded");

    sf::Image cursorImage = texture.copyToImage();
    auto size = cursorImage.getSize();
    Vector2u center(size.x/2, size.y/2);
    auto cursor = Cursor::createFromPixels(cursorImage.getPixelsPtr(), size, center);
    if (cursor)
        wnd.setMouseCursor(*cursor);
}

Main::Main(RenderWindow& wnd) {
    load_texture(5, "main menu", "data/main menu.png");
    load_texture(5, "settings", "data/settings.png");
    load_texture(5, "play", "data/play.png");
    load_texture(5, "exit", "data/exit.png");

    exit = new Button({100, 100, 50, 50}, "exit", sc_goback);
    play = new Button({X/2-50, Y/2-50, 220, 100}, "play");
    settings = new Button({X-100, 100, 100, 100}, "settings", [&]{
        sc_goto("settings", wnd);
    });
}

void Main::draw(RenderWindow& wnd) {
    static float color = 0;
    //wnd.clear(Color(color, color, color));

    color += 0.01; // скорость изменения цвета фона
    auto r = (cos(color + 0.6) + 1) * 255.0 * 0.5;
    auto g = (cos(color - 0.2) + 1) * 255.0 * 0.5;
    auto b = (cos(color + 0.5) + 1) * 255.0 * 0.5;
    wnd.clear(Color(r, g, b));

    // следить чтобы курсор не потерялся
    counter++;
    if (counter % 60 == 0)
        set_mouse_cursor(wnd);

    draw_texture(X/2-250, Y/2-250, wnd, "main menu");
    
    exit->draw(wnd);
    play->draw(wnd);
    settings->draw(wnd);
}

void Main::action(RenderWindow& wnd) {
    exit->action(wnd);
    play->action(wnd);
    settings->action(wnd);
}
