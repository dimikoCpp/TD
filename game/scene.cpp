#include "scene.hpp"
#include <stack>
#include "menu/menu.hpp"
#include "menu/settings.hpp"
#include <iostream>

stack<Menu*> line;

void sc_goto(string name, RenderWindow& wnd){
    if(name=="main_menu"){
        line.push(new Main(wnd));
    }
    else if(name=="settings"){
        line.push(new Settings(wnd));
    }
    else{
        cout << "scene's name isn't correct -> "<< name << endl;
    }
}

void sc_goback(){
    line.pop();
}

void sc_draw(RenderWindow& wnd){
    auto menu = line.top();
    menu -> draw(wnd);
}

void sc_action(RenderWindow& wnd){
    auto menu = line.top();
    menu -> action(wnd);
}