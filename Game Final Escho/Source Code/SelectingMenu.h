#pragma once
#include "Menu.h"
class SelectingMenu :
    public Menu
{
private:
    RectangleShape background;

    RectangleShape StatusBackground;

    string stat[10];
    Text status;
    vector<Text> statuses;

    void initChoose();
    void initStatus();

public:
    map<string, Menu> choose;
    int hp;
    int armor;
    int speed;
    int damage;
    int score;
    SelectingMenu();
    virtual ~SelectingMenu();

    void updateStatus(const float& dt);
    void renderChoose(RenderTarget* target);
    void renderStatus(RenderTarget* target);
    void render(RenderTarget* target);
};

