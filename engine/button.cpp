#include "button.hpp"

Button::Button(Rect2d h, int s, string name, function<void ()> func)
{
    deiystvie = func;
    hitbox = h;
    hitbox.x -= hitbox.w/2;
    hitbox.y -= hitbox.h/2;
    tex = new Texture(name);
    spr = new Sprite(*tex);
    spr->setScale(Vector2f(s, s));
    spr->setOrigin(Vector2f(tex->getSize().x / 2, tex->getSize().y / 2));
    spr->setPosition(Vector2f(h.x, h.y));
}

Button::~Button() {
    delete spr;
    delete tex;
}

void Button::draw(RenderWindow& wnd) {
    wnd.draw(*spr);

    RectangleShape rect(Vector2f(hitbox.w, hitbox.h));
    auto pos = spr->getPosition();
    auto center = spr->getOrigin();
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
