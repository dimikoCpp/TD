#include <cmath>
#include "menu.hpp"
#include "../../core/consts.hpp"
#include "../../engine/button.hpp"
#include "../../engine/texture.hpp"
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
    load_texture(10, "main menu", "data/main menu.png");

    play = new Button({X/2, Y/2, 250, 100}, "data/play.png");
    settings = new Button({X-100, 100, 50, 50}, "data/Settings.png");
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

    draw_texture(X/2, Y/2, wnd, "main menu");
    

    play->draw(wnd);
    settings->draw(wnd);
}

void Main::action(RenderWindow& wnd) {
    play->action(wnd);
    settings->action(wnd);
}
