#include "texture.hpp"
#include <map>
#include <iostream>

struct td_texture {
    Texture *tex {};
    Sprite *spr {};
};

// <имя_текстуры, данные_текстуры>
static map<string, td_texture> all_textures;

td_texture load_from_file(string file, int size) {
    td_texture result;
    result.tex = new Texture(file);
    result.spr = new Sprite(*result.tex);
    // изменить размер картинки
    result.spr->setScale(Vector2f(size, size));
    // чтобы центр текстуры был в центре картинки
 //   result.spr->setOrigin(Vector2f(result.tex->getSize().x / 2, result.tex->getSize().y / 2));
    return result;
}

void load_texture(int size, string name, string file) {
    all_textures[name] = load_from_file(file, size);
}

void draw_texture(int X, int Y, RenderWindow& wnd, string name) {
    // проверить что текстура есть в списке текстур, если нет, то вылететь
    
    if (all_textures.find(name) == all_textures.end()) {
        cout << "не удалось загрузить текстуру с названием \"" << name << "\"" << endl;
        std::terminate(); // закрыть игру
    }

    
    auto tex = all_textures[name];
    tex.spr->setPosition(Vector2f(X, Y));
    wnd.draw(*tex.spr);
}
