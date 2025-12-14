#include <chrono>
#include <SFML/Graphics.hpp>
#include "engine/shrift.hpp"
#include "core/consts.hpp"
#include "game/game.hpp"
#include "engine/texture.hpp"
using namespace sf;
using namespace std;

int main() {
    load_texture(20, "play", "data/play.png");

    load_shrift("data/Typographica-Blp5.ttf");
    RenderWindow window(VideoMode({X, Y}), GAME_NAME, sf::Style::Close);
    window.setFramerateLimit(MAX_FPS);
    window.setVerticalSyncEnabled(0);
    Core c(window);
    auto time_start = chrono::steady_clock::now();
    int fps = 0;
    string fps_txt;
    string fps_now_txt;

    while (window.isOpen()) {
        auto now = chrono::steady_clock::now();
        auto elapsed = chrono::duration_cast<chrono::milliseconds>(now - time_start);
        if (elapsed.count() >= 1000) {
            fps_txt = to_string(fps);
            fps = 0;
            time_start = chrono::steady_clock::now();
        }

        c.action(window);
        
        while (const optional event = window.pollEvent()) {
            // Close window: exit
            if (event->is<Event::Closed>())
                window.close();
        }

        window.clear(Color(0, 0, 255));
        c.draw(window);
        draw_shrift(window, "FPS: " + fps_txt, 123, 321, 50, Color(255,0,0));
        draw_shrift(window, "FPS (2): " + fps_now_txt, 123, 370, 50, Color(255,0,0));
        //for (int i = 0; i < 10; ++i)
            //draw_texture(X/2 + (rand() % 100), Y/2 + (rand() % 100), window, "play");
        window.display();
        ++fps;

        auto end = chrono::steady_clock::now();
        auto dt = chrono::duration_cast<chrono::milliseconds>(now - end);
        fps_now_txt = to_string(int( 1000.0 / dt.count() ));
    } // конец главного цикла
}