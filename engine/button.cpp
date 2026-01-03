#include "button.hpp"
#include "texture.hpp"
Button::Button(Rect2d h, string name, function<void ()> func)
{
    deiystvie = func;
    hitbox = h;
    hitbox.x -= hitbox.w/2;
    hitbox.y -= hitbox.h/2;
    texture = name;
}

void Button::set_texture(string new_tex) {
    texture = new_tex;
}

Button::~Button() {

}

void Button::draw(RenderWindow& wnd) {
    draw_texture(hitbox.x, hitbox.y, wnd, texture);

    RectangleShape rect(Vector2f(hitbox.w, hitbox.h));
    rect.setPosition(Vector2f(hitbox.x, hitbox.y));
    rect.setOutlineThickness(1);
    rect.setOutlineColor(Color(255, 0, 0));
    rect.setFillColor(Color::Transparent);
    wnd.draw(rect);
}

void Button::action(RenderWindow& wnd) {
    if (Mouse::isButtonPressed(Mouse::Button::Left)) {
        //clicksound.play();
        Vector2i pos = Mouse::getPosition(wnd);
        if (check(pos.x, pos.y) && deiystvie) {
            deiystvie();
        }
    }
}

bool Button::check(int x, int y) {
    bool a = hitbox.x <= x;
    bool b = x <= hitbox.x + hitbox.w;
    bool c = hitbox.y <= y;
    bool d = y <= hitbox.y + hitbox.h;

    if (a && b){
        if (c && d){
        return true; 
        }
    }
    return false;
}
