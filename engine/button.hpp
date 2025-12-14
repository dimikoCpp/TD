#pragma once
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

struct Rect2d {
    int x {}, y {}; // левый верхний угол прямоугольника
    int w {}, h {}; // размеры
};

class Button {
    Texture* tex {};
    Sprite* spr {};
    Rect2d hitbox {};
    function<void ()> deiystvie {};

public: 
    Button(Rect2d h, int s, string name, function<void ()> func = {});
    ~Button();

    void draw(RenderWindow& wnd);
    void action(RenderWindow& wnd);
    bool check(int x, int y); // проверка что корды мышки находятся в кнопке
};